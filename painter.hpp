#pragma once
#include <QOpenGLWidget>
#include "QtOpenGL/glut.h"
#include <QTimer>
#include <QVector3D>
class Painter : public QOpenGLWidget {
	Q_OBJECT

public:
	Painter(QWidget * parent = 0);
	~Painter();
protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);

	void add_path           (QVector<QVector3D>, double, QColor);
	void add_a_pathpoint    (QVector3D, int);
	void add_points         (QVector<QVector3D>, double, QColor);
	void add_a_point        (QVector3D, int);

	bool set_path_property  (int,double,QColor);
	bool set_points_property(int, double, QColor);

	bool erase_path         (int);
	bool erase_points       (int);

	bool get_path_property(int, double &, QColor &);
	bool get_points_property(int, double &, QColor &);
	QColor get_background_color();

	bool set_refresh_time(unsigned int);
	void set_background_color(QColor);
private:
	void refresh_gl();
	void draw_axis();
	void draw_path();
	void draw_points();

	int list_path;
	int list_axis;
	int list_points;

	QTimer *refresh;
	int refresh_time;
	QColor backgroud_color;

	QVector<QVector<QVector3D>>        path;
	QVector<std::pair<double, QColor>> path_property;

	QVector<QVector<QVector3D>>        points;
	QVector<std::pair<double, QColor>> points_property;

};
