#include "pantspainter.h"
#include "libdwgr.h"
#include "libdxfrw.h"
#include "readcad.h"
#define CN(a) QString::fromLocal8Bit(a)
#define INT(a) QString::number(a,10)
PantsPainter::PantsPainter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	first_boot = true;
	selected_dir = new QDir(CN("./modelfiles"));
	file_list = new QFileInfoList(selected_dir->entryInfoList());
	ui.groupBox_2->setEnabled(false);
	ui.groupBox->setEnabled(true);
	ui.checkBox->setChecked(true);
	ui.radioButton->setChecked(true);
	
	autoget_filename();
	index = min_index;
	ui.lineEdit->setText(*first_filename);
	ui.lineEdit_2->setText(*second_filename);
	
	ui.label_7->setText(INT(index));

	ui.label_6->setText(selected_dir->path());

	ui.spinBox_7->setValue(ui.openGLWidget->get_rotate_speed());
	//std::ofstream log("out.log", std::ios::app);
	//for (auto a : *file_list)
	//{
	//	log << a.fileName().toStdString() << std::endl;
	//}
	

	connect(ui.checkBox,SIGNAL(clicked()),this,SLOT(change_mode()));
	connect(ui.pushButton_5,SIGNAL(clicked()),this,SLOT(next_group()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(last_group()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(open_folder()));
	connect(this, SIGNAL(index_changed(int)), this, SLOT(read_file(int)));
	connect(ui.radioButton, SIGNAL(clicked()), this, SLOT(select_model1()));
	connect(ui.radioButton_2, SIGNAL(clicked()), this, SLOT(select_model2()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(set_opengl_proprety_foldermode()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(select_color()));
	connect(ui.spinBox_7, SIGNAL(valueChanged(int)), this, SLOT(change_rotate_speed(int)));
	connect(ui.pushButton_12, SIGNAL(clicked()), this, SLOT(set_filename()));

	connect(ui.pushButton_11, SIGNAL(clicked()), this, SLOT(set_background_color()));

	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(selcted_file()));
	connect(ui.comboBox_2,SIGNAL(currentIndexChanged(int)),this,SLOT(read_selectd_model_proprety(int)));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(select_color_file_mode()));
	connect(ui.pushButton_8, SIGNAL(clicked()), this, SLOT(set_model_proprety_file_mode()));
	connect(ui.pushButton_10, SIGNAL(clicked()), this, SLOT(clear_all_model()));
	connect(ui.pushButton_9, SIGNAL(clicked()), this, SLOT(clear_selected_model()));

	connect(ui.openGLWidget, SIGNAL(points2path(bool)), this, SLOT(turn_off_button(bool)));

	connect(ui.openGLWidget, SIGNAL(zoom_status_changed(double)), this, SLOT(zoom_changed(double)));

	connect(ui.pushButton_13, &QPushButton::clicked, this, &PantsPainter::open_cad_file);
	emit index_changed(index);
	first_boot = false;
}

PantsPainter::~PantsPainter()
{

}

void PantsPainter::change_mode()
{
	if (ui.checkBox->isChecked())
	{
		ui.groupBox->setEnabled(true);
		ui.groupBox_2->setEnabled(false);
		ui.openGLWidget->erase_path(-1);
		ui.openGLWidget->erase_points(-1);
		ui.openGLWidget->reset_date();
		emit index_changed(index);
	}
	else
	{
		ui.groupBox->setEnabled(false);
		ui.groupBox_2->setEnabled(true);
		ui.openGLWidget->erase_path(-1);
		ui.openGLWidget->erase_points(-1);
		ui.comboBox_2->clear();
		ui.openGLWidget->reset_date();
		turn_on_button();
	}
}

void PantsPainter::next_group()
{
	switch (ui.comboBox->currentIndex())
	{
	case 0:
		index++;
		if (index > max_index)
		{
			index = max_index;
			emit index_changed(index);
		}
		else emit index_changed(index);
		
		break;
	case 1:
		index += 5;
		if (index > max_index)
		{
			index = max_index;
			emit index_changed(index);
		}
		else emit index_changed(index);

		break;
	case 2:
		index += 10;
		if (index > max_index)
		{
			index = max_index;
			emit index_changed(index);
		}
		else emit index_changed(index);
		break;
	default:
		break;
	}
}

void PantsPainter::last_group()
{
	switch (ui.comboBox->currentIndex())
	{
	case 0:		
		index--;
		if (index < min_index)
		{
			index = min_index;
			emit index_changed(index);
		}
		else emit index_changed(index);


		break;
	case 1:
		index-= 5;
		if (index < min_index)
		{
			index = min_index;
			emit index_changed(index);
		}
		else emit index_changed(index);
		break;
	case 2:
		index-=10;
		if (index < min_index)
		{
			index = min_index;
			emit index_changed(index);
		}
		else emit index_changed(index);
		break;
	default:
		break;
	}
}

void PantsPainter::open_folder()
{
	QString dir = QFileDialog::getExistingDirectory(this, CN("选择目录"), "./");
	dir = dir.toLocal8Bit();
	if (dir.isEmpty()) return;
	else
	{
		
		delete selected_dir;
		delete file_list;
		selected_dir = new QDir(dir);
		file_list = new QFileInfoList(selected_dir->entryInfoList());
		switch (autoget_filename())
		{
		case FILE_NOTFOUND:
			set_filename();
			ui.label_6->setText(selected_dir->path());
			ui.label_7->setText(INT(index));
			ui.lineEdit->setText(*first_filename);
			ui.lineEdit_2->setText(*second_filename);
			break;
		case COUNT_NOT_TRUE:
			ui.label_6->setText(selected_dir->path());
			ui.label_7->setText(INT(index));
			ui.lineEdit->setText(*first_filename);
			ui.lineEdit_2->setText(*second_filename);
			
			break;
		case FOUNDED:
			ui.label_6->setText(selected_dir->path());
			ui.label_7->setText(INT(index));
			ui.lineEdit->setText(*first_filename);
			ui.lineEdit_2->setText(*second_filename);
			index = min_index;
			emit index_changed(index);
			break;
		}
		
		//if (ui.radioButton->isChecked()) select_model1();
		//else select_model2();
		
	}

}

void PantsPainter::read_file(int idx)
{
	ui.openGLWidget->erase_path(-1);
	ui.openGLWidget->erase_points(-1);
	QString fn1 = selected_dir->path() + "/" + *first_filename + INT(idx) + ".txt";
	QString fn2 = selected_dir->path() + "/" + *second_filename + INT(idx) + ".txt";
	std::ifstream f1(fn1.toStdString(), std::ios::in);
	std::ifstream f2(fn2.toStdString(), std::ios::in);

	if (!f1.is_open()) return;
	if (!f2.is_open()) return;

	QVector<QVector3D> addv;
	while (!f1.eof())
	{
		double x, y, z;
		f1 >> x >> y >> z;
		addv.push_back(QVector3D(x, y, z));
	}
	addv.erase(addv.end() - 1);
	ui.openGLWidget->add_points(addv);
	addv.clear();
	while (!f2.eof())
	{
		double x, y, z;
		f2 >> x >> y >> z;
		addv.push_back(QVector3D(x, y, z));
	}
	addv.erase(addv.end() - 1);
	ui.openGLWidget->add_points(addv);

	ui.openGLWidget->set_points_property(1, 1.0, QColor(255, 0, 0));

	ui.label_7->setText(INT(index));

	if (ui.radioButton->isChecked()) select_model1();
	else select_model2();
}

void PantsPainter::select_model1()
{
	double size;
	QColor color;
	if (!ui.openGLWidget->points_is_empty())
	{
		ui.openGLWidget->get_points_property(0,size,color);
		ui.doubleSpinBox->setValue(size);
		ui.spinBox->setValue(color.red());
		ui.spinBox_2->setValue(color.green());
		ui.spinBox_3->setValue(color.blue());
	}
	else if (!ui.openGLWidget->path_is_empty())
	{
		ui.openGLWidget->get_path_property(0, size, color);
		ui.doubleSpinBox->setValue(size);
		ui.spinBox->setValue(color.red());
		ui.spinBox_2->setValue(color.green());
		ui.spinBox_3->setValue(color.blue());
	}
}

void PantsPainter::select_model2()
{
	double size;
	QColor color;
	if (!ui.openGLWidget->points_is_empty())
	{
		ui.openGLWidget->get_points_property(1, size, color);
		ui.doubleSpinBox->setValue(size);
		ui.spinBox->setValue(color.red());
		ui.spinBox_2->setValue(color.green());
		ui.spinBox_3->setValue(color.blue());
	}
	else if (!ui.openGLWidget->path_is_empty())
	{
		ui.openGLWidget->get_path_property(1, size, color);
		ui.doubleSpinBox->setValue(size);
		ui.spinBox->setValue(color.red());
		ui.spinBox_2->setValue(color.green());
		ui.spinBox_3->setValue(color.blue());
	}
	
}

void PantsPainter::set_opengl_proprety_foldermode()
{
	int k;
	if (ui.radioButton->isChecked()) k = 0;
	else k = 1;
	if (!ui.openGLWidget->points_is_empty())
		ui.openGLWidget->set_points_property(k,ui.doubleSpinBox->value(),QColor(ui.spinBox->value(), ui.spinBox_2->value(), ui.spinBox_3->value()));
	else if(!ui.openGLWidget->path_is_empty())
		ui.openGLWidget->set_path_property(k, ui.doubleSpinBox->value(), QColor(ui.spinBox->value(), ui.spinBox_2->value(), ui.spinBox_3->value()));


}

void PantsPainter::select_color()
{
	QColorDialog cd(this);
	cd.setCurrentColor(QColor(ui.spinBox->value(), ui.spinBox_2->value(), ui.spinBox_3->value()));
	
	if (cd.exec() == 1)
	{
		QColor sc = cd.selectedColor();
		ui.spinBox->setValue(sc.red());
		ui.spinBox_2->setValue(sc.green());
		ui.spinBox_3->setValue(sc.blue());
	}

}

void PantsPainter::change_rotate_speed(int d)
{
	ui.openGLWidget->set_rotate_speed(d);
}

void PantsPainter::set_filename()
{
	delete first_filename;
	delete second_filename;
	if (ui.lineEdit->text() == "")
	{
		ui.lineEdit->setText("-");
	}	
	if (ui.lineEdit_2->text() == "")
	{
		ui.lineEdit_2->setText("-");
	}
	if (ui.lineEdit->text()[ui.lineEdit->text().size() - 1] != '-')
	{
		ui.lineEdit->setText(ui.lineEdit->text() + '-');
	}
	if (ui.lineEdit_2->text()[ui.lineEdit_2->text().size() - 1] != '-')
	{
		ui.lineEdit_2->setText(ui.lineEdit_2->text() + '-');
	}

	first_filename = new QString(ui.lineEdit->text().toLocal8Bit());
	second_filename = new QString(ui.lineEdit_2->text().toLocal8Bit());

	QString fi1 = ui.lineEdit->text();
	QString fi2 = ui.lineEdit_2->text();

	fi1.push_front('(');
	fi1.push_back(')');


	QRegExp r1(fi1 + "(\\d+)");
	QVector<int> idx;
	for (auto a : *file_list)
	{
		r1.indexIn(a.fileName());
		if (r1.cap(1) == ui.lineEdit->text())
		{
			idx.push_back(r1.cap(2).toInt());

		}
	}


	autoset_min_max_index(idx);

	index = min_index;

	emit index_changed(index);
}

void PantsPainter::selcted_file()
{
	QString fn = QFileDialog::getOpenFileName(this, CN("打开文件"), "./", CN("制表符分隔，逗号分隔(*.txt *.csv)"));
	if (fn.isEmpty()) return;
	QVector<QVector3D> addv;
	if (fn[fn.size() - 1] == 't')
	{
		std::ifstream f(fn.toStdString(), std::ios::in);
		while (!f.eof())
		{
			double x, y, z;
			f >> x >> y >> z;
			addv.push_back(QVector3D(x, y, z));
		}
		addv.erase(addv.end() - 1);

	}
	else
	{
		std::ifstream f(fn.toStdString(), std::ios::in);
		while (!f.eof())
		{
			double x, y, z;
			char t;
			f >> x>> t >> y>> t >> z;
			addv.push_back(QVector3D(x, y, z));
		}
		addv.erase(addv.end() - 1);
	}

	if (ui.comboBox_3->currentIndex() == 0)
	{
		ui.openGLWidget->add_points(addv, ui.doubleSpinBox_2->value(), QColor(ui.spinBox_4->value(), ui.spinBox_5->value(), ui.spinBox_6->value()));
		ui.comboBox_2->addItem(CN("点") + INT(ui.openGLWidget->get_points_size() - 1),QVariant(QPoint(PantsPainter::POINTS, ui.openGLWidget->get_points_size() - 1)));
	}
	else
	{
		ui.openGLWidget->add_path(addv, ui.doubleSpinBox_2->value(), QColor(ui.spinBox_4->value(), ui.spinBox_5->value(), ui.spinBox_6->value()));
		ui.comboBox_2->addItem(CN("线") + INT(ui.openGLWidget->get_path_size() - 1), QVariant(QPoint(PantsPainter::PATH, ui.openGLWidget->get_path_size() - 1)));

	}
	read_selectd_model_proprety(ui.comboBox_2->currentIndex());
}

void PantsPainter::read_selectd_model_proprety(int)
{
	if (ui.comboBox_2->count() == 0) return;
	auto data = ui.comboBox_2->currentData().toPoint();
	
	if (data.x() == PATH)
	{
		double s;
		QColor color;
		ui.openGLWidget->get_path_property(data.y(),s,color);
		ui.doubleSpinBox_2->setValue(s);
		ui.spinBox_4->setValue(color.red());
		ui.spinBox_5->setValue(color.green());
		ui.spinBox_6->setValue(color.blue());
	}
	else if (data.x() == POINTS)
	{

		double s;
		QColor color;
		ui.openGLWidget->get_points_property(data.y(), s, color);
		ui.doubleSpinBox_2->setValue(s);
		ui.spinBox_4->setValue(color.red());
		ui.spinBox_5->setValue(color.green());
		ui.spinBox_6->setValue(color.blue());
	}
}

void PantsPainter::select_color_file_mode()
{
	QColorDialog cd(this);
	cd.setCurrentColor(QColor(ui.spinBox_4->value(), ui.spinBox_5->value(), ui.spinBox_6->value()));

	if (cd.exec() == 1)
	{
		QColor sc = cd.selectedColor();
		ui.spinBox_4->setValue(sc.red());
		ui.spinBox_5->setValue(sc.green());
		ui.spinBox_6->setValue(sc.blue());
	}
}

void PantsPainter::set_model_proprety_file_mode()
{
	if (ui.comboBox_2->count() == 0) return;
	auto data = ui.comboBox_2->currentData().toPoint();
	switch (data.x())
	{
		case POINTS:
			ui.openGLWidget->set_points_property(data.y(), ui.doubleSpinBox_2->value(), QColor(ui.spinBox_4->value(), ui.spinBox_5->value(), ui.spinBox_6->value()));
			break;
		case PATH:
			ui.openGLWidget->set_path_property(data.y(), ui.doubleSpinBox_2->value(), QColor(ui.spinBox_4->value(), ui.spinBox_5->value(), ui.spinBox_6->value()));
			break;
	
	default:
		break;
	}
}

void PantsPainter::clear_all_model()
{
	ui.comboBox_2->clear();
	ui.openGLWidget->erase_path(-1);
	ui.openGLWidget->erase_points(-1);
	ui.spinBox_4->setValue(255);
	ui.spinBox_5->setValue(255);
	ui.spinBox_6->setValue(255);
	ui.doubleSpinBox_2->setValue(1.0);
	turn_on_button();
	ui.openGLWidget->reset_date();
}

void PantsPainter::set_background_color()
{
	QColorDialog cd(this);
	cd.setCurrentColor(ui.openGLWidget->get_background_color());

	if (cd.exec() == 1)
	{
		QColor sc = cd.selectedColor();
		ui.openGLWidget->set_background_color(sc);
	}
}

void PantsPainter::clear_selected_model()
{
	if (ui.comboBox_2->count() == 0) return;
	auto data = ui.comboBox_2->currentData().toPoint();
	switch (data.x())
	{
	case POINTS:
		ui.openGLWidget->erase_points(data.y());
		for (int i = 0; i < ui.comboBox_2->count(); i++)
		{
			if (ui.comboBox_2->itemData(i).toPoint().x() == POINTS)
			{
				if(ui.comboBox_2->itemData(i).toPoint().y() > data.y() )
				ui.comboBox_2->setItemData(i, QVariant(QPoint(POINTS, ui.comboBox_2->itemData(i).toPoint().y() - 1)));
			}
		}
		
		break;
	case PATH:
		ui.openGLWidget->erase_path(data.y());
		for (int i = 0; i < ui.comboBox_2->count(); i++)
		{
			if (ui.comboBox_2->itemData(i).toPoint().x() ==PATH)
			{
				if (ui.comboBox_2->itemData(i).toPoint().y() > data.y())
					ui.comboBox_2->setItemData(i, QVariant(QPoint(POINTS, ui.comboBox_2->itemData(i).toPoint().y() - 1)));
			}
		}
		
		break;
	default:
		break;
	}
	ui.comboBox_2->removeItem(ui.comboBox_2->currentIndex());

}

void PantsPainter::turn_off_button(bool m)
{
	if (m)
	{
		ui.pushButton_8->setEnabled(false);
		ui.pushButton_9->setEnabled(false);
	}
	else if (!m)
	{
		ui.pushButton_8->setEnabled(false);
		ui.pushButton_9->setEnabled(false);
	}
}

void PantsPainter::turn_on_button()
{
	if(!ui.pushButton_8->isEnabled()) ui.pushButton_8->setEnabled(true);
	
	if (!ui.pushButton_9->isEnabled()) ui.pushButton_9->setEnabled(true);
}

void PantsPainter::zoom_changed(double d)
{
	ui.label_19->setText(QString::number(d, '.', 3));
}

void PantsPainter::open_cad_file()
{
	dxfRW dxf("D:/test.dxf");
	
	ReadCad s(dxf);
	dxf.read(&s,false);
	

	return;

	

	
	//QMessageBox::information(0,"1",QString::number(cad.getVersion(),10),1024);




}

unsigned short PantsPainter::autoget_filename()
{
	QRegExp fnre("([^.]+-)(\\d+)(.txt)");
	QRegExp goodre("([^.]+-)(\\d+)");
	QStringList goodfn;
	QStringList fn1;
	QStringList fn2;
	QString ofn1;
	QString ofn2;
	QVector<int> idx1;
	QVector<int> idx2;
	

	for (auto a : *file_list)
	{
		int i = fnre.indexIn(a.fileName());
		if (i < 0) continue;
		goodfn.push_back(fnre.cap(1) + fnre.cap(2));
	}
	for (auto a : goodfn)
	{
		int i = goodre.indexIn(a);
		if (ofn1.isEmpty()) ofn1 = goodre.cap(1);
		else
		{
			if (ofn1 != goodre.cap(1)) 
			{
				ofn2 = goodre.cap(1);
				break;
			}
		}
	}

	if (goodfn.isEmpty() || ofn2.isEmpty()) 
	{ 
		QMessageBox::warning(this, CN("错误"), CN("无法自动识别目录，请检查文件名格式。"), QMessageBox::Ok);
		return FILE_NOTFOUND;
	}

	QString rfn1 = ofn1;
	QString rfn2 = ofn2;



	rfn1.push_front('(');
	rfn1.push_back(')');
	rfn2.push_front('(');
	rfn2.push_back(')');
	QString indexreg = rfn1 + "(\\d+)";
	QString indexreg2 = rfn2 + "(\\d+)";
	QRegExp findint1(indexreg);
	QRegExp findint2(indexreg2);

	for (auto a : goodfn)
	{
		
		if(findint1.indexIn(a) >= 0)
		fn1.push_back(findint1.cap(0));

	}
	for (auto a : goodfn)
	{

		if (findint2.indexIn(a) >= 0)
			fn2.push_back(findint2.cap(0));

	}
	
	if (!first_boot)
	{
		delete first_filename;
		delete second_filename;
	}
	first_filename = new QString(ofn1.toLocal8Bit());
	second_filename = new QString(ofn2.toLocal8Bit());


	if (fn1.size() != fn2.size())
	{
		QMessageBox::warning(this, CN("错误"), CN("对比文件数目不符合，请手动设置文件名。"), QMessageBox::Ok);
		return COUNT_NOT_TRUE;
	}


	for (auto a : fn1)
	{
		

		if (findint1.indexIn(a) >= 0)
		idx1.push_back(findint1.cap(2).toInt());


	}
	for (auto a : fn2)
	{


		if (findint2.indexIn(a) >= 0)
			idx2.push_back(findint2.cap(2).toInt());

	}






	autoset_min_max_index(idx1);
	
	return FOUNDED;
 }

void PantsPainter::autoset_min_max_index(QVector<int> idx)
{

	int min = 0;
	int max = 0;
	for (int i = 0; i < idx.size(); i++)
	{
		if (idx[i] < idx[min]) min = i;
		if (idx[i] > idx[max]) max = i;
	}

	min_index = idx[min];
	max_index = idx[max];
	emit index_changed(min_index);
}





