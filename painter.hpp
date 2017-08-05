#pragma once
#include <QOpenGLWidget>
#include "QtOpenGL/glut.h"
#include <QTimer>
#include <QVector3D>
#include <QVector4D>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QMatrix4x4>
#include <QMessageBox>
#include <fstream>

class Painter : public QOpenGLWidget {
	Q_OBJECT

public:
	Painter(QWidget * parent = 0);
	~Painter();
	void add_path(QVector<QVector3D>, double = 1.0, QColor = QColor(255, 255, 255));
	void add_a_pathpoint(QVector3D, int);
	void add_points(QVector<QVector3D>, double = 1.0, QColor = QColor(255, 255, 255));
	void add_a_point(QVector3D, int);

	bool set_path_property(int, double, QColor);
	bool set_points_property(int, double, QColor);

	bool erase_path(int);
	bool erase_points(int);

	bool get_path_property(int, double &, QColor &);
	bool get_points_property(int, double &, QColor &);
	QColor get_background_color();

	void set_refresh_time(unsigned int);
	void set_background_color(QColor);
	void set_axis_length(double);

	void set_rotate_speed(unsigned int);

	void zoomin(QWheelEvent*);
	void zoomout(QWheelEvent*);

public slots:
	void refresh_gl();

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);

	void mousePressEvent(QMouseEvent*);
	void mouseMoveEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
	void wheelEvent(QWheelEvent*);
private:
	enum VIEW
	{
		TOP_VIEW = 0,
		UPWARD_VIEW = 1,
		LEFT_VIEW = 2,
		RIGHT_VIEW = 3,
		FORNT_VIEW = 4,
		BEHIND_VIEW = 5
	};


	void draw_model();
	void rotate_model();
	void move_model();
	void reset_date();
	//QMatrix4x4 get_rotate_matrix(double, QVector3D);

	int list_model;


	QTimer *refresh;
	int refresh_time;
	QColor backgroud_color;

	QVector<QVector<QVector3D>>        path;
	QVector<std::pair<double, QColor>> path_property;

	QVector<QVector<QVector3D>>        points;
	QVector<std::pair<double, QColor>> points_property;

	QVector<QPointF> axis_date{QPointF(0,10),QPointF(0,10) ,QPointF(0,10) };

	double view_left;
	double view_right;
	double view_up;
	double view_bottom;

	double axis_length;

	QPointF start_point;
	QPointF moved_point;

	QVector3D eye;
	QVector3D view;
	QVector3D up;

	QVector3D aux_x;
	QVector3D aux_y;
	QVector3D aux_z;

	double rotate_speed;
	double move_speed;

	
	QVector3D log_model_vec;

	bool isnot_rotated;

	double log_max;

	int view_log;
};
