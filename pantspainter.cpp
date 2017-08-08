#include "pantspainter.h"
#define CN(a) QString::fromLocal8Bit(a)
#define INT(a) QString::number(a,10)
PantsPainter::PantsPainter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
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
	emit index_changed(index);
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
		emit index_changed(index);
	}
	else
	{
		ui.groupBox->setEnabled(false);
		ui.groupBox_2->setEnabled(true);
		ui.openGLWidget->erase_path(-1);
		ui.openGLWidget->erase_points(-1);
		ui.comboBox_2->clear();
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
		delete first_filename;
		delete second_filename;
		selected_dir = new QDir(dir);
		file_list = new QFileInfoList(selected_dir->entryInfoList());
		autoget_filename();
		ui.label_6->setText(selected_dir->path());
		ui.label_7->setText(INT(index));
		ui.lineEdit->setText(*first_filename);
		ui.lineEdit_2->setText(*second_filename);
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
	first_filename = new QString(ui.lineEdit->text().toLocal8Bit());
	first_filename = new QString(ui.lineEdit_2->text().toLocal8Bit());
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

void PantsPainter::autoget_filename()
{
	QString tmpfirst;
	QString tmpsecond;
	QString first;
	QString second;

	int i = 0;
	for (auto a : *file_list)
	{
		if (i == 2)
		{
			tmpfirst = a.fileName();
		}
		if (i == (file_list->size() / 2 + 1))
		{
			tmpsecond = a.fileName();
		}
		i++;
	}
	
	for (i = 0; i <= tmpfirst.size() - 6; i++)
	{
		first.push_back(tmpfirst[i]);
	}
	for (i = 0; i <= tmpsecond.size() - 6; i++)
	{
		second.push_back(tmpsecond[i]);
	}



	first_filename = new QString(first.toLocal8Bit());
	second_filename = new QString(second.toLocal8Bit());


	autoset_min_max_index();
 }

void PantsPainter::autoset_min_max_index()
{
	QString first_num;

	for (int i = first_filename->size(); file_list[0][2].fileName()[i] != '.'; i++)
	{
		first_num.push_back(file_list[0][2].fileName()[i]);
	}


	min_index = first_num.toInt();
	max_index = min_index - 1 + (file_list->size() - 2) / 2;


}





