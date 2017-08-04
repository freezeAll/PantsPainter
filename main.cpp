#include "pantspainter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PantsPainter w;
	w.show();
	return a.exec();
}
