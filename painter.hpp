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
#include <QContextMenuEvent>
#include <QMenu>
class Painter : public QOpenGLWidget {
	Q_OBJECT

public:
	Painter(QWidget * parent = 0);
	~Painter();
	void                               add_path(const QVector<QVector3D>&, double = 1.0, QColor = QColor(255, 255, 255));
	void                               add_a_pathpoint(const QVector3D&, int&);
	void                               add_points(const QVector<QVector3D>&, double = 1.0, QColor = QColor(255, 255, 255));
	void                               add_a_point(const QVector3D&, int&);

	bool                               set_path_property(const int&, const double&, const QColor&);
	bool                               set_points_property(const int&, const double&, const QColor&);

	bool                               erase_path(const int&);
	bool                               erase_points(const int&);

	bool                               get_path_property(const int&, double &, QColor &) const ;
	bool                               get_points_property(const int&, double &, QColor &) const;
	QColor                             get_background_color() const;

	void                               set_refresh_time(const unsigned int&);
	void                               set_background_color(const QColor&);
	void                               set_axis_length(const double&);

	void                               set_rotate_speed(const unsigned int&);

	void                               zoomin(QWheelEvent*);
	void                               zoomout(QWheelEvent*);

	int                                get_rotate_speed() const;
	bool                               path_is_empty();
	bool                               points_is_empty();

	int                                get_path_size();
	int                                get_points_size();
public slots:
	void                               refresh_gl();

	void                               set_axis_display();
	void                               reset_date();
	void                               top_view();
	void                               upward_view();
	void                               fornt_view();
	void                               behind_view();
	void                               left_view();
	void                               right_view();
	void                               path2points();
	void                               points2path();

protected:
	void                               initializeGL();
	void                               paintGL();
	void                               resizeGL(int width, int height);

	void                               mousePressEvent(QMouseEvent*);
	void                               mouseMoveEvent(QMouseEvent*);
	void                               mouseReleaseEvent(QMouseEvent*);
	void                               wheelEvent(QWheelEvent*);

	void                               contextMenuEvent(QContextMenuEvent *e);

signals:
	void points2path(bool);
	void zoom_status_changed(double);
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
	enum MOVE_TYPE
	{
		ZOOMIN = 0,
		ZOOMOUT = 1
	};

	void                               draw_model();
	void                               rotate_model();
	void                               move_model();
	void                               mouse_move(MOVE_TYPE,const QPointF &move_vec);
	void                               axis_move(MOVE_TYPE, const QPointF &move_vec);
	void                               reset_axis();
	//QMatrix4x4 get_rotate_matrix(double, QVector3D);

	int list_model;


	QTimer                             refresh;
	int                                refresh_time;
	QColor                             backgroud_color;

	QVector<QVector<QVector3D>>        path;
	QVector<QVector<QVector3D>>        backup_path;
	QVector<std::pair<double, QColor>> path_property;

	QVector<QVector<QVector3D>>        points;
	QVector<QVector<QVector3D>>        backup_points;
	QVector<std::pair<double, QColor>> points_property;

	QVector<QVector3D>                 axis_x;
	QVector<QVector3D>                 axis_y;
	QVector<QVector3D>                 axis_z;


	double                             view_left;
	double                             view_right;
	double                             view_up;
	double                             view_bottom;

	double                             axis_length;

	QPointF                            start_point;
	QPointF                            moved_point;

	QVector3D                          eye;
	QVector3D                          view;
	QVector3D                          up;

	QVector3D                          aux_x;
	QVector3D                          aux_y;
	QVector3D                          aux_z;

	double                             rotate_speed;
	double                             move_speed;

	
	QVector3D                          log_model_vec;

	bool                               isnot_rotated;

	double                             log_max;

	int                                view_log;


	QMenu                              *menu;

	bool                               axis_display;

	double                             zoom_status;
};
