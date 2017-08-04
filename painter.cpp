#include "painter.hpp"

Painter::Painter(QWidget * parent) : QOpenGLWidget(parent) 
{
	refresh = new QTimer(this);
	refresh->start(refresh_time);

	backgroud_color.setRedF(0.156);
	backgroud_color.setGreenF(0.156);
	backgroud_color.setBlueF(0.168);
	backgroud_color.setAlphaF(0.0);

	connect(refresh, SIGNAL(timeout()), this, SLOT(refresh_gl()));
}

Painter::~Painter() 
{
	delete refresh;
}

void Painter::refresh_gl()
{
	refresh->start(refresh_time);
}

void Painter::initializeGL()
{
	
	glShadeModel(GL_SMOOTH);
	glClearColor(backgroud_color.redF(), backgroud_color.greenF(), backgroud_color.blueF(), backgroud_color.alphaF());
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	draw_axis();
}
void Painter::paintGL()
{
	glLoadIdentity();
	glOrtho(-1000 / 2, 1000 / 2, -1000 / 2, 1000 / 2, -1000 / 2, 1000 / 2);

	glClearColor(backgroud_color.redF(), backgroud_color.greenF(), backgroud_color.blueF(), backgroud_color.alphaF());


	glCallList(list_axis);
	glCallList(list_path);
	glCallList(list_points);
}
void Painter::resizeGL(int width, int height)
{
	
}

void Painter::draw_axis()
{
	list_axis = glGenLists(1);
	glNewList(list_axis, GL_COMPILE);
	/*红色轴是X轴，绿色是Y轴，蓝色是Z轴*/
	double length = 50.0;

	glLineWidth(5);
	glBegin(GL_LINES);
	glColor3d(1.0, 0.0, 0.0);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(length, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3d(0.0, 1.0, 0.0);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.0, length, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3d(0.0, 0.0, 1.0);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.0, 0.0, length);
	glEnd();


	glEndList();
}

void Painter::draw_path()
{
	list_path = glGenLists(2);
	glNewList(list_axis, GL_COMPILE);
	if (!path.isEmpty())
	{
		for (int i = 0; i < path.size(); i++)
		{
			glLineWidth(path_property[i].first);
			for (int k = 0, l = 1; l < path[i].size(); l++, k++)
			{
				glBegin(GL_LINES);
				glColor3d(path_property[i].second.redF(),
					path_property[i].second.greenF(), path_property[i].second.blueF());
				glVertex3d(path[i][k].x(), path[i][k].y(), path[i][k].z());
				glVertex3d(path[i][l].x(), path[i][l].y(), path[i][l].z());
				glEnd();
			}

		}
	}
	glEndList();
}

void Painter::draw_points()
{
	list_points = glGenLists(3);
	glNewList(list_points, GL_COMPILE);
	if (!points.isEmpty())
	{
		for (int i = 0; i < points.size(); i++)
		{
			
			glBegin(GL_POINTS);
			glPointSize(points_property[i].first);
			glColor3d(points_property[i].second.redF(),
				points_property[i].second.greenF(), points_property[i].second.blueF());
			for (int k = 0; k < points[i].size(); k++)
			{

				glVertex3d(path[i][k].x(), path[i][k].y(), path[i][k].z());
				
			}
			glEnd();
		}
	}
	glEndList();
}

void Painter::add_path(QVector<QVector3D> p,double w = 1.0,QColor c = QColor(255,255,255))
{
	path.push_back(p);
	path_property.push_back(std::pair<double, QColor>(w, c));
}


void Painter::add_a_pathpoint(QVector3D p, int k)
{
	if (path.empty())
	{
		path.push_back(QVector<QVector3D>{ p });
		path_property.push_back(std::pair<double, QColor>(1.0, QColor(255,255,255)));
	}
	else if(k >= path.size()) path[path.size() - 1].push_back(p);
	else if (k < 0) path[0].push_back(p);
	else path[k].push_back(p);
}


void Painter::add_points(QVector<QVector3D> p, double s = 1.0, QColor c  = QColor(255, 255, 255))
{
	points.push_back(p);
	path_property.push_back(std::pair<double, QColor>(s, c));
}


void Painter::add_a_point(QVector3D p, int k)
{
	if (points.empty())
	{
		points.push_back(QVector<QVector3D>{ p });
		points_property.push_back(std::pair<double, QColor>(1.0, QColor(255, 255, 255)));
	}
	else if (k >= path.size()) points[points.size() - 1].push_back(p);
	else if (k < 0) points[0].push_back(p);
	else points[k].push_back(p);
}

bool Painter::set_path_property(int k, double w, QColor c)
{
	if (path_property.empty()) return false;
	else if (k >= path_property.size()) return false;
	else if (k < 0)
	{
		for (auto &f : path_property)
		{
			f.first = w;
			f.second = c;
		}
		return true;
	}
	else 
	{
		path_property[k].first = w;
		path_property[k].second = c;
		return true;
	}
}


bool Painter::set_points_property(int k, double s, QColor c)
{
	if (points_property.empty()) return false;
	else if (k >= points_property.size()) return false;
	else if (k < 0)
	{
		for (auto &f : points_property)
		{
			f.first = s;
			f.second = c;
		}
		return true;
	}
	else
	{
		points_property[k].first = s;
		points_property[k].second = c;
		return true;
	}
}


bool Painter::erase_path(int k)
{
	if (path.empty()) return false;
	else if (k >= path.size()) return false;
	else if (k < 0)
	{
		path.clear();
		path_property.clear();
		return true;
	}
	else
	{
		path.erase(path.begin() + k);
		path_property.erase(path_property.begin() + k);
		return true;
	}
}


bool Painter::erase_points(int k)
{
	if (points.empty()) return false;
	else if (k >= points.size()) return false;
	else if (k < 0)
	{
		points.clear();
		points_property.clear();
		return true;
	}
	else
	{
		points.erase(points.begin() + k);
		points_property.erase(points_property.begin() + k);
		return true;
	}
}

bool Painter::get_path_property(int k, double &w, QColor &c)
{
	if (path_property.empty()) return false;
	else if (k < 0 || k >= path_property.size()) return false;
	else
	{
		 w = path_property[k].first;
		 c = path_property[k].second;
		 return true;
	}
}

bool Painter::get_points_property(int k, double &s, QColor &c)
{
	if (points_property.empty()) return false;
	else if (k < 0 || k >= points_property.size()) return false;
	else
	{
		s = points_property[k].first;
		c = points_property[k].second;
		return true;
	}
}

bool Painter::set_refresh_time(unsigned int t)
{
	refresh_time = t;
}

void Painter::set_background_color(QColor c)
{
	backgroud_color = c;
}

QColor Painter::get_background_color()
{
	return backgroud_color;
}

