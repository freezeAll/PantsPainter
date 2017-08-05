#include "pantspainter.h"

PantsPainter::PantsPainter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	std::ifstream inp("bestmatchpnts-1.txt", std::ios::in);
	QVector<QVector3D> pnts;
	while (!inp.eof())
	{
		
		double x, y, z;
		inp >> x  >> y  >> z;
		QVector3D tmp(x , y,z );
		pnts.push_back(tmp);

	}
	pnts.erase(pnts.end() - 1);
	ui.openGLWidget->add_path(pnts);
}

PantsPainter::~PantsPainter()
{

}
