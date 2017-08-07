#include "painter.hpp"
#define CN(s) QString::fromLocal8Bit(s)
Painter::Painter(QWidget * parent) : QOpenGLWidget(parent) 
{
	refresh = new QTimer(parent);
	refresh_time = 1;
	refresh->start(refresh_time);

	backgroud_color.setRedF(0.156);
	backgroud_color.setGreenF(0.156);
	backgroud_color.setBlueF(0.168);
	backgroud_color.setAlphaF(0.0);

	reset_date();

	

	connect(refresh, SIGNAL(timeout()), this, SLOT(refresh_gl()));
}

Painter::~Painter() 
{
	delete refresh;
}

void Painter::refresh_gl()
{
	
	this->update();
	refresh->start(refresh_time);

}

void Painter::set_axis_display()
{
	if (axis_display)
		axis_display = false;
	else axis_display = true;
}

void Painter::top_view()
{
	eye.setX(0); eye.setY(0); eye.setZ(1);
	up.setX(0); up.setY(1); up.setZ(0);
	view_log = TOP_VIEW;
	path = backup_path;
	points = backup_points;
	isnot_rotated = true;
	reset_axis();
}

void Painter::upward_view()
{
	eye.setX(0); eye.setY(0); eye.setZ(-1);
	up.setX(0); up.setY(-1); up.setZ(0);
	view_log = UPWARD_VIEW;
	path = backup_path;
	points = backup_points;
	isnot_rotated = true;
	reset_axis();
}

void Painter::fornt_view()
{
	
	eye.setX(0); eye.setY(-1); eye.setZ(0);
	up.setX(0); up.setY(0); up.setZ(1);
	view_log = FORNT_VIEW;
	path = backup_path;
	points = backup_points;
	isnot_rotated = true;
	reset_axis();
	
}

void Painter::behind_view()
{
	eye.setX(0); eye.setY(1); eye.setZ(0);
	up.setX(0); up.setY(0); up.setZ(1);
	view_log = BEHIND_VIEW;
	path = backup_path;
	points = backup_points;
	isnot_rotated = true;
	reset_axis();
}

void Painter::left_view()
{
	eye.setX(-1); eye.setY(0); eye.setZ(0);
	up.setX(0); up.setY(0); up.setZ(1);
	view_log = LEFT_VIEW;
	path = backup_path;
	points = backup_points;
	isnot_rotated = true;
	reset_axis();
}

void Painter::right_view()
{
	eye.setX(1); eye.setY(0); eye.setZ(0);
	up.setX(0); up.setY(0); up.setZ(1);
	view_log = RIGHT_VIEW;
	path = backup_path;
	points = backup_points;
	isnot_rotated = true;
	reset_axis();
}

void Painter::path2points()
{
	if (path.empty()) return;
	points = path;
	backup_points = path;
	points_property = path_property;

	path.clear();
	backup_path.clear();
	path_property.clear();
}

void Painter::points2path()
{
	if (points.empty()) return;

	path = points;
	backup_path = points;
	path_property = points_property;

	points.clear();
	backup_points.clear();
	points_property.clear();
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

	
	
}
void Painter::paintGL()
{
	glLoadIdentity();

	glViewport(0, -(this->width() - this->height()) / 2, this->width(), this->width());

	glOrtho(view_left, view_right,view_bottom, view_up, -200 / 2, 200 / 2);

	glClearColor(backgroud_color.redF(), backgroud_color.greenF(), backgroud_color.blueF(), backgroud_color.alphaF());

	//
	draw_model();


	
	gluLookAt(eye.x(), eye.y(), eye.z() , view.x(), view.y(), view.z(), up.x(), up.y(), up.z());
	glCallList(list_model);
	

}
void Painter::resizeGL(int w, int h)
{
	glViewport(0, -(w - h) / 2, w, w);
}

void Painter::draw_model()
{
	list_model = glGenLists(1);
	glNewList(list_model, GL_COMPILE);
	/*红色轴是X轴，绿色是Y轴，蓝色是Z轴*/
	
	if (axis_display)
	{
		glLineWidth(5);
		glBegin(GL_LINES);
		glColor3d(1.0, 0.0, 0.0);
		glVertex3d(axis_x[0].x(), axis_x[0].y(), axis_x[0].z());
		glVertex3d(axis_x[1].x(), axis_x[1].y(), axis_x[1].z());
		glEnd();

		glBegin(GL_LINES);
		glColor3d(0.0, 1.0, 0.0);
		glVertex3d(axis_y[0].x(), axis_y[0].y(), axis_y[0].z());
		glVertex3d(axis_y[1].x(), axis_y[1].y(), axis_y[1].z());
		glEnd();

		glBegin(GL_LINES);
		glColor3d(0.0, 0.0, 1.0);
		glVertex3d(axis_z[0].x(), axis_z[0].y(), axis_z[0].z());
		glVertex3d(axis_z[1].x(), axis_z[1].y(), axis_z[1].z());
		glEnd();
	}
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
			glBegin(GL_LINES);
			glColor3d(path_property[i].second.redF(),
				path_property[i].second.greenF(), path_property[i].second.blueF());
			glVertex3d(path[i][path[i].size() - 1].x(), path[i][path[i].size() - 1].y(), path[i][path[i].size() - 1].z());
			glVertex3d(path[i][0].x(), path[i][0].y(), path[i][0].z());
			glEnd();

		}
	}

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

				glVertex3d(points[i][k].x(), points[i][k].y(), points[i][k].z());

			}
			glEnd();

		}
	}
	glEndList();
}

//void Painter::draw_path()
//{
//	list_path = glGenLists(2);
//	glNewList(list_axis, GL_COMPILE);
//	
//	glEndList();
//}
//
//void Painter::draw_points()
//{
//	list_points = glGenLists(3);
//	glNewList(list_points, GL_COMPILE);
//	
//	glEndList();
//}

void Painter::add_path(QVector<QVector3D> p,double w,QColor c)
{
	path.push_back(p);
	path_property.push_back(std::pair<double, QColor>(w, c));
	backup_path = path;
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


void Painter::add_points(QVector<QVector3D> p, double s, QColor c)
{
	points.push_back(p);
	points_property.push_back(std::pair<double, QColor>(s, c));
	backup_points = points;
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
		backup_path.clear();
		return true;
	}
	else
	{
		path.erase(path.begin() + k);
		path_property.erase(path_property.begin() + k);
		backup_path.erase(backup_path.begin() + k);
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
		points.clear();
		return true;
	}
	else
	{
		points.erase(points.begin() + k);
		points_property.erase(points_property.begin() + k);
		backup_points.erase(points.begin() + k);
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

void Painter::set_refresh_time(unsigned int t)
{
	refresh_time = t;
}

void Painter::set_background_color(QColor c)
{
	backgroud_color = c;
}

void Painter::set_axis_length(double l)
{
	axis_length = l;
}

QColor Painter::get_background_color()
{
	return backgroud_color;
}

void Painter::mousePressEvent(QMouseEvent *e)
{
	moved_point = e->pos();
	start_point = moved_point;
	
}

void Painter::mouseMoveEvent(QMouseEvent *e)
{
	if (e->buttons() & Qt::MiddleButton)
	{
		moved_point = e->pos();
		rotate_model();
	}
	else if (e->buttons() & Qt::LeftButton)
	{
		moved_point = e->pos();
		move_model();
	}
}

void Painter::mouseReleaseEvent(QMouseEvent *e)
{
	
}

void Painter::wheelEvent(QWheelEvent *e)
{
	if (e->delta() > 0)
	{
		zoomin(e);
	}
	else if (e->delta() < 0)
	{
		zoomout(e);
	}
}

void Painter::rotate_model()
{
	QVector3D MouseTrace = aux_y * (start_point.y() - moved_point.y()) + aux_x * (moved_point.x() -start_point.x());
	QVector3D RotateAsix = QVector3D::crossProduct(MouseTrace, aux_z);
	RotateAsix.normalize();

	double angle = MouseTrace.length() * rotate_speed;

	QMatrix4x4 rotatMatrix;
	rotatMatrix.rotate(angle, RotateAsix);

	std::ofstream log("out.log", std::ios::app);

	

	eye = rotatMatrix * eye;
	up = rotatMatrix * up;
	up.normalize();
	aux_y = up;
	aux_z = eye - view;
	aux_x = QVector3D::crossProduct(aux_y, aux_z);
	aux_x.normalize();
	start_point = moved_point;

	//log << angle << std::endl;
	isnot_rotated = false;

	//
}

void Painter::move_model()
{
	QPointF vec = moved_point - start_point; 
	view_left -= vec.x() * move_speed;
	view_right -= vec.x() * move_speed;
	view_up += vec.y() * move_speed;
	view_bottom += vec.y() * move_speed;


	start_point = moved_point;

}



//QMatrix4x4 Painter::get_rotate_matrix(double angle, QVector3D vector)
//{
//	angle = angle / 2 * M_PI / 180;
//	QVector3D vec = vector.normalized();
//	double cosa = cos(angle);
//	double sina = sin(angle);
//	double a = vec.x() * sina;
//	double b = vec.y() * sina;
//	double c = vec.z() * sina;
//	
//	QMatrix4x4 matrix;
//	matrix.setRow(0, QVector4D(1.0 - 2.0*(b*b + c*c), 2.0 * (a*b - c*cosa), 2.0 * (a*c + b*cosa),0));
//	matrix.setRow(1, QVector4D(2.0 * (a*b + c*cosa), 1.0 - 2.0*(c*c + a*a), 2.0 * (b*c - a*cosa), 0));
//	matrix.setRow(2, QVector4D(2.0 * (a*c - b*cosa), 2.0 * (b*c + a*cosa), 1.0 - 2.0*(a*a + b*b), 0));
//	
//	return matrix;
//}

void Painter::set_rotate_speed(unsigned int s)
{
	rotate_speed = s / 100.0;
}

void Painter::zoomin(QWheelEvent*e)
{
	if (isnot_rotated)
	{
		QPointF mousep = e->posF();
		float w = this->width();
		float h = this->height();
		mousep.setX(mousep.x() - w / 2.0);
		mousep.setY(-mousep.y() + h / 2.0);

		mousep.setY(mousep.y() / (h / 2.0 / log_max));
		mousep.setX(mousep.x() / (w / 2.0 / log_max));


		QPointF move_vec(mousep);

		mouse_move(ZOOMIN, move_vec);
		axis_move(ZOOMIN, move_vec);

	}
	view_left *= 0.95;
	view_right *= 0.95;
	view_up *= 0.95;
	view_bottom *= 0.95;

	log_max *= 0.95;

	move_speed *= 0.95;
}

void Painter::zoomout(QWheelEvent*e)
{
	if (isnot_rotated)
	{
		QPointF mousep = e->posF();
		float w = this->width();
		float h = this->height();
		mousep.setX(mousep.x() - w / 2.0);
		mousep.setY(-mousep.y() + h / 2.0);

		mousep.setY(mousep.y() / (h / 2.0 / log_max));
		mousep.setX(mousep.x() / (w / 2.0 / log_max));


		QPointF move_vec(mousep);

		mouse_move(ZOOMOUT, move_vec);
		axis_move(ZOOMOUT, move_vec);

	}


	view_left /= 0.95;
	view_right /= 0.95;
	view_up /= 0.95;
	view_bottom /= 0.95;

	log_max /= 0.95;
	move_speed /= 0.95;
}

void Painter::reset_date()
{
	view_left = -100;
	view_right = 100;
	view_bottom = -100;
	view_up = 100;

	axis_length = 10.0;

	rotate_speed = 0.6;
	move_speed = 0.3;

	view_log = TOP_VIEW;

	log_max = 100.0;

	eye.setX(0); eye.setY(0); eye.setZ(1);
	up.setX(0); up.setY(1); up.setZ(0);
	view.setX(0); view.setY(0); view.setZ(0);
	aux_y.setX(0); aux_y.setY(1); aux_y.setZ(0);
	aux_z = eye - view;
	aux_x = QVector3D::crossProduct(aux_y, aux_z);

	axis_display = true;

	path = backup_path;
	points = backup_points;
	
	isnot_rotated = true;
	view_log = TOP_VIEW;

	reset_axis();
}

void Painter::contextMenuEvent(QContextMenuEvent *e)
{
	menu = new QMenu(this);

	QAction menu_axis(CN("显示坐标"),this);
	menu_axis.setCheckable(true);
	if (axis_display) menu_axis.setChecked(true);
	else menu_axis.setChecked(false);
	
	QAction menu_reset(CN("重置位置"), this);
	//views
	QAction menu_fornt_view(CN("前视图"), this);

	QAction menu_behind_view(CN("后视图"), this);

	QAction menu_left_view(CN("左视图"), this);

	QAction menu_right_view(CN("右视图"), this);

	QAction menu_top_view(CN("俯视图"), this);

	QAction menu_upward_view(CN("仰视图"), this);

	QAction menu_points2path(CN("点连线"), this);

	QAction menu_path2points(CN("取消点连线"), this);

	menu->addAction(&menu_axis);
	menu->addAction(&menu_reset);
	menu->addAction(&menu_top_view);
	menu->addAction(&menu_upward_view);
	menu->addAction(&menu_fornt_view);
	menu->addAction(&menu_behind_view);
	menu->addAction(&menu_left_view);
	menu->addAction(&menu_right_view);
	menu->addAction(&menu_points2path);
	menu->addAction(&menu_path2points);

	connect(&menu_axis, SIGNAL(triggered()), this, SLOT(set_axis_display()));
	connect(&menu_reset, SIGNAL(triggered()), this, SLOT(reset_date()));
	connect(&menu_top_view, SIGNAL(triggered()), this, SLOT(top_view()));
	connect(&menu_upward_view, SIGNAL(triggered()), this, SLOT(upward_view()));
	connect(&menu_fornt_view, SIGNAL(triggered()), this, SLOT(fornt_view()));
	connect(&menu_left_view, SIGNAL(triggered()), this, SLOT(left_view()));
	connect(&menu_right_view, SIGNAL(triggered()), this, SLOT(right_view()));
	connect(&menu_behind_view, SIGNAL(triggered()), this, SLOT(behind_view()));
	connect(&menu_path2points, SIGNAL(triggered()), this, SLOT(path2points()));
	connect(&menu_points2path, SIGNAL(triggered()), this, SLOT(points2path()));

	menu->exec(QCursor::pos());
}

void Painter::mouse_move(MOVE_TYPE t,const QPointF &move_vec)
{
	if (t == ZOOMOUT)
	{
		for (auto &v : path)
		{
			for (auto &p : v)
			{
				switch (view_log)
				{
				case Painter::TOP_VIEW:
					p.setX(p.x() + move_vec.x() / 20.0);
					p.setY(p.y() + move_vec.y() / 20.0);
					break;
				case Painter::UPWARD_VIEW:
					p.setX(p.x() + move_vec.x() / 20.0);
					p.setY(p.y() - move_vec.y() / 20.0);
					break;
				case Painter::LEFT_VIEW:
					p.setY(p.y() - move_vec.x() / 20.0);
					p.setZ(p.z() + move_vec.y() / 20.0);
					break;
				case Painter::RIGHT_VIEW:
					p.setY(p.y() + move_vec.x() / 20.0);
					p.setZ(p.z() + move_vec.y() / 20.0);
					break;
				case Painter::FORNT_VIEW:
					p.setX(p.x() + move_vec.x() / 20.0);
					p.setZ(p.z() + move_vec.y() / 20.0);
					break;
				case Painter::BEHIND_VIEW:
					p.setX(p.x() - move_vec.x() / 20.0);
					p.setZ(p.z() + move_vec.y() / 20.0);
					break;
				default:
					break;
				}

			}
		}
		for (auto &v : points)
		{
			for (auto &p : v)
			{
				switch (view_log)
				{
				case Painter::TOP_VIEW:
					p.setX(p.x() + move_vec.x() / 20.0);
					p.setY(p.y() + move_vec.y() / 20.0);
					break;
				case Painter::UPWARD_VIEW:
					p.setX(p.x() + move_vec.x() / 20.0);
					p.setY(p.y() - move_vec.y() / 20.0);
					break;
				case Painter::LEFT_VIEW:
					p.setY(p.y() - move_vec.x() / 20.0);
					p.setZ(p.z() + move_vec.y() / 20.0);
					break;
				case Painter::RIGHT_VIEW:
					p.setY(p.y() + move_vec.x() / 20.0);
					p.setZ(p.z() + move_vec.y() / 20.0);
					break;
				case Painter::FORNT_VIEW:
					p.setX(p.x() + move_vec.x() / 20.0);
					p.setZ(p.z() + move_vec.y() / 20.0);
					break;
				case Painter::BEHIND_VIEW:
					p.setX(p.x() - move_vec.x() / 20.0);
					p.setZ(p.z() + move_vec.y() / 20.0);
					break;
				default:
					break;
				}

			}
		}

	}
	else if (t == ZOOMIN)
	{


		for (auto &v : path)
		{
			for (auto &p : v)
			{

				switch (view_log)
				{
				case Painter::TOP_VIEW:
					p.setX(p.x() - move_vec.x() / 20.0);
					p.setY(p.y() - move_vec.y() / 20.0);
					break;
				case Painter::UPWARD_VIEW:
					p.setX(p.x() - move_vec.x() / 20.0);
					p.setY(p.y() + move_vec.y() / 20.0);
					break;
				case Painter::LEFT_VIEW:
					p.setY(p.y() + move_vec.x() / 20.0);
					p.setZ(p.z() - move_vec.y() / 20.0);
					break;
				case Painter::RIGHT_VIEW:
					p.setY(p.y() - move_vec.x() / 20.0);
					p.setZ(p.z() - move_vec.y() / 20.0);
					break;
				case Painter::FORNT_VIEW:
					p.setX(p.x() - move_vec.x() / 20.0);
					p.setZ(p.z() - move_vec.y() / 20.0);
					break;
				case Painter::BEHIND_VIEW:
					p.setX(p.x() + move_vec.x() / 20.0);
					p.setZ(p.z() - move_vec.y() / 20.0);
					break;
				default:
					break;
				}

			}
		}

		for (auto &v : points)
		{
			for (auto &p : v)
			{

				switch (view_log)
				{
				case Painter::TOP_VIEW:
					p.setX(p.x() - move_vec.x() / 20.0);
					p.setY(p.y() - move_vec.y() / 20.0);
					break;
				case Painter::UPWARD_VIEW:
					p.setX(p.x() - move_vec.x() / 20.0);
					p.setY(p.y() + move_vec.y() / 20.0);
					break;
				case Painter::LEFT_VIEW:
					p.setY(p.y() + move_vec.x() / 20.0);
					p.setZ(p.z() - move_vec.y() / 20.0);
					break;
				case Painter::RIGHT_VIEW:
					p.setY(p.y() - move_vec.x() / 20.0);
					p.setZ(p.z() - move_vec.y() / 20.0);
					break;
				case Painter::FORNT_VIEW:
					p.setX(p.x() - move_vec.x() / 20.0);
					p.setZ(p.z() - move_vec.y() / 20.0);
					break;
				case Painter::BEHIND_VIEW:
					p.setX(p.x() + move_vec.x() / 20.0);
					p.setZ(p.z() - move_vec.y() / 20.0);
					break;
				default:
					break;
				}

			}
		}




	}
	
}

void Painter::axis_move(MOVE_TYPE t, const QPointF & move_vec)
{
	if (t == ZOOMOUT)
	{
		for (auto &p : axis_x)
		{
			switch (view_log)
			{
			case Painter::TOP_VIEW:
				p.setX(p.x() + move_vec.x() / 20.0);
				p.setY(p.y() + move_vec.y() / 20.0);
				break;
			case Painter::UPWARD_VIEW:
				p.setX(p.x() + move_vec.x() / 20.0);
				p.setY(p.y() - move_vec.y() / 20.0);
				break;
			case Painter::LEFT_VIEW:
				p.setY(p.y() - move_vec.x() / 20.0);
				p.setZ(p.z() + move_vec.y() / 20.0);
				break;
			case Painter::RIGHT_VIEW:
				p.setY(p.y() + move_vec.x() / 20.0);
				p.setZ(p.z() + move_vec.y() / 20.0);
				break;
			case Painter::FORNT_VIEW:
				p.setX(p.x() + move_vec.x() / 20.0);
				p.setZ(p.z() + move_vec.y() / 20.0);
				break;
			case Painter::BEHIND_VIEW:
				p.setX(p.x() - move_vec.x() / 20.0);
				p.setZ(p.z() + move_vec.y() / 20.0);
				break;
			default:
				break;
			}
		}
		for (auto &p : axis_y)
		{
			switch (view_log)
			{
			case Painter::TOP_VIEW:
				p.setX(p.x() + move_vec.x() / 20.0);
				p.setY(p.y() + move_vec.y() / 20.0);
				break;
			case Painter::UPWARD_VIEW:
				p.setX(p.x() + move_vec.x() / 20.0);
				p.setY(p.y() - move_vec.y() / 20.0);
				break;
			case Painter::LEFT_VIEW:
				p.setY(p.y() - move_vec.x() / 20.0);
				p.setZ(p.z() + move_vec.y() / 20.0);
				break;
			case Painter::RIGHT_VIEW:
				p.setY(p.y() + move_vec.x() / 20.0);
				p.setZ(p.z() + move_vec.y() / 20.0);
				break;
			case Painter::FORNT_VIEW:
				p.setX(p.x() + move_vec.x() / 20.0);
				p.setZ(p.z() + move_vec.y() / 20.0);
				break;
			case Painter::BEHIND_VIEW:
				p.setX(p.x() - move_vec.x() / 20.0);
				p.setZ(p.z() + move_vec.y() / 20.0);
				break;
			default:
				break;
			}
		}
		for (auto &p : axis_z)
		{
			switch (view_log)
			{
			case Painter::TOP_VIEW:
				p.setX(p.x() + move_vec.x() / 20.0);
				p.setY(p.y() + move_vec.y() / 20.0);
				break;
			case Painter::UPWARD_VIEW:
				p.setX(p.x() + move_vec.x() / 20.0);
				p.setY(p.y() - move_vec.y() / 20.0);
				break;
			case Painter::LEFT_VIEW:
				p.setY(p.y() - move_vec.x() / 20.0);
				p.setZ(p.z() + move_vec.y() / 20.0);
				break;
			case Painter::RIGHT_VIEW:
				p.setY(p.y() + move_vec.x() / 20.0);
				p.setZ(p.z() + move_vec.y() / 20.0);
				break;
			case Painter::FORNT_VIEW:
				p.setX(p.x() + move_vec.x() / 20.0);
				p.setZ(p.z() + move_vec.y() / 20.0);
				break;
			case Painter::BEHIND_VIEW:
				p.setX(p.x() - move_vec.x() / 20.0);
				p.setZ(p.z() + move_vec.y() / 20.0);
				break;
			default:
				break;
			}
		}

	}
	else if (t == ZOOMIN)
	{
		for (auto &p : axis_x)
		{
			switch (view_log)
			{
			case Painter::TOP_VIEW:
				p.setX(p.x() - move_vec.x() / 20.0);
				p.setY(p.y() - move_vec.y() / 20.0);
				break;
			case Painter::UPWARD_VIEW:
				p.setX(p.x() - move_vec.x() / 20.0);
				p.setY(p.y() + move_vec.y() / 20.0);
				break;
			case Painter::LEFT_VIEW:
				p.setY(p.y() + move_vec.x() / 20.0);
				p.setZ(p.z() - move_vec.y() / 20.0);
				break;
			case Painter::RIGHT_VIEW:
				p.setY(p.y() - move_vec.x() / 20.0);
				p.setZ(p.z() - move_vec.y() / 20.0);
				break;
			case Painter::FORNT_VIEW:
				p.setX(p.x() - move_vec.x() / 20.0);
				p.setZ(p.z() - move_vec.y() / 20.0);
				break;
			case Painter::BEHIND_VIEW:
				p.setX(p.x() + move_vec.x() / 20.0);
				p.setZ(p.z() - move_vec.y() / 20.0);
				break;
			default:
				break;
			}
		}
		for (auto &p : axis_y)
		{
			switch (view_log)
			{
			case Painter::TOP_VIEW:
				p.setX(p.x() - move_vec.x() / 20.0);
				p.setY(p.y() - move_vec.y() / 20.0);
				break;
			case Painter::UPWARD_VIEW:
				p.setX(p.x() - move_vec.x() / 20.0);
				p.setY(p.y() + move_vec.y() / 20.0);
				break;
			case Painter::LEFT_VIEW:
				p.setY(p.y() + move_vec.x() / 20.0);
				p.setZ(p.z() - move_vec.y() / 20.0);
				break;
			case Painter::RIGHT_VIEW:
				p.setY(p.y() - move_vec.x() / 20.0);
				p.setZ(p.z() - move_vec.y() / 20.0);
				break;
			case Painter::FORNT_VIEW:
				p.setX(p.x() - move_vec.x() / 20.0);
				p.setZ(p.z() - move_vec.y() / 20.0);
				break;
			case Painter::BEHIND_VIEW:
				p.setX(p.x() + move_vec.x() / 20.0);
				p.setZ(p.z() - move_vec.y() / 20.0);
				break;
			default:
				break;
			}
		}
		for (auto &p : axis_z)
		{
			switch (view_log)
			{
			case Painter::TOP_VIEW:
				p.setX(p.x() - move_vec.x() / 20.0);
				p.setY(p.y() - move_vec.y() / 20.0);
				break;
			case Painter::UPWARD_VIEW:
				p.setX(p.x() - move_vec.x() / 20.0);
				p.setY(p.y() + move_vec.y() / 20.0);
				break;
			case Painter::LEFT_VIEW:
				p.setY(p.y() + move_vec.x() / 20.0);
				p.setZ(p.z() - move_vec.y() / 20.0);
				break;
			case Painter::RIGHT_VIEW:
				p.setY(p.y() - move_vec.x() / 20.0);
				p.setZ(p.z() - move_vec.y() / 20.0);
				break;
			case Painter::FORNT_VIEW:
				p.setX(p.x() - move_vec.x() / 20.0);
				p.setZ(p.z() - move_vec.y() / 20.0);
				break;
			case Painter::BEHIND_VIEW:
				p.setX(p.x() + move_vec.x() / 20.0);
				p.setZ(p.z() - move_vec.y() / 20.0);
				break;
			default:
				break;
			}
		}





	}
}

void Painter::reset_axis()
{
	axis_x = { QVector3D(0.0,0.0,0.0) , QVector3D(axis_length,0.0,0.0) };
	axis_y = { QVector3D(0.0,0.0,0.0) ,QVector3D(0.0, -axis_length,0.0) };
	axis_z = { QVector3D(0.0,0.0,0.0) ,QVector3D(0.0,0.0,axis_length) };
}

