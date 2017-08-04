/********************************************************************************
** Form generated from reading UI file 'pantspainter.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTSPAINTER_H
#define UI_PANTSPAINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <painter.hpp>

QT_BEGIN_NAMESPACE

class Ui_PantsPainterClass
{
public:
    QWidget *centralWidget;
    Painter *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PantsPainterClass)
    {
        if (PantsPainterClass->objectName().isEmpty())
            PantsPainterClass->setObjectName(QStringLiteral("PantsPainterClass"));
        PantsPainterClass->resize(600, 494);
        centralWidget = new QWidget(PantsPainterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new Painter(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(10, 10, 400, 400));
        PantsPainterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PantsPainterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        PantsPainterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PantsPainterClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PantsPainterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PantsPainterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PantsPainterClass->setStatusBar(statusBar);

        retranslateUi(PantsPainterClass);

        QMetaObject::connectSlotsByName(PantsPainterClass);
    } // setupUi

    void retranslateUi(QMainWindow *PantsPainterClass)
    {
        PantsPainterClass->setWindowTitle(QApplication::translate("PantsPainterClass", "PantsPainter", 0));
    } // retranslateUi

};

namespace Ui {
    class PantsPainterClass: public Ui_PantsPainterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTSPAINTER_H
