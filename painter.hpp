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
	void refresh_gl();
private:
	void draw_axis();
	int list_axis;
	QTimer *refresh;

	QVector<QVector<QVector3D>> path;
	QVector<std::pair<double, QColor>> path_proprety;

};
