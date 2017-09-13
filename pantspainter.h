#ifndef PANTSPAINTER_H
#define PANTSPAINTER_H

#include <QtWidgets/QMainWindow>
#include "ui_pantspainter.h"
#include <fstream>
#include <QDir>
#include <QFileDialog>
#include <QColorDialog>
#include <QRegExp>
#include <QMessageBox>
class PantsPainter : public QMainWindow
{
	Q_OBJECT

public:
	PantsPainter(QWidget *parent = 0);
	~PantsPainter();
signals:
void index_changed(int);
public slots:

void change_mode();
void next_group();
void last_group();
void open_folder();
void read_file(int);
void select_model1();
void select_model2();
void set_opengl_proprety_foldermode();
void select_color();
void change_rotate_speed(int);
void set_filename();
void selcted_file();
void read_selectd_model_proprety(int);
void select_color_file_mode();
void set_model_proprety_file_mode();
void clear_all_model();
void set_background_color();
void clear_selected_model();
void turn_off_button(bool);
void turn_on_button();
void zoom_changed(double);
void open_cad_file();
void cad_out_csv();
void display_cad();
private:
	Ui::PantsPainterClass ui;

	int index;

	unsigned short autoget_filename();

	void autoset_min_max_index(QVector<int>);

	enum MODEL_TYPE
	{
		PATH = 0,
		POINTS = 1
	};
	enum ERROR_TYPE
	{
		FILE_NOTFOUND = 0,
		COUNT_NOT_TRUE = 1,
		FOUNDED = 2
	};
	QDir selected_dir;
	QFileInfoList file_list;
	int min_index;
	int max_index;

	bool first_boot;
	QString first_filename;
	QString second_filename;

	QVector<QVector3D> cad_dates;


};

#endif // PANTSPAINTER_H
