#ifndef PANTSPAINTER_H
#define PANTSPAINTER_H

#include <QtWidgets/QMainWindow>
#include "ui_pantspainter.h"

class PantsPainter : public QMainWindow
{
	Q_OBJECT

public:
	PantsPainter(QWidget *parent = 0);
	~PantsPainter();

private:
	Ui::PantsPainterClass ui;
};

#endif // PANTSPAINTER_H
