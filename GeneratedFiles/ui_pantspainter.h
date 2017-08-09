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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
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
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    QSpinBox *spinBox_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *comboBox;
    QLabel *label_15;
    QLineEdit *lineEdit;
    QLabel *label_16;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_12;
    QCheckBox *checkBox;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox_2;
    QLabel *label_9;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_11;
    QSpinBox *spinBox_4;
    QLabel *label_12;
    QSpinBox *spinBox_5;
    QLabel *label_13;
    QSpinBox *spinBox_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QLabel *label_17;
    QComboBox *comboBox_3;
    QLabel *label_14;
    QPushButton *pushButton_11;
    QSpinBox *spinBox_7;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PantsPainterClass)
    {
        if (PantsPainterClass->objectName().isEmpty())
            PantsPainterClass->setObjectName(QStringLiteral("PantsPainterClass"));
        PantsPainterClass->resize(1060, 786);
        centralWidget = new QWidget(PantsPainterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new Painter(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(0, 10, 1061, 400));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 420, 1041, 151));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 75, 23));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 110, 61, 21));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(80, 110, 89, 21));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(150, 100, 423, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        doubleSpinBox = new QDoubleSpinBox(horizontalLayoutWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));

        horizontalLayout->addWidget(doubleSpinBox);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(horizontalLayoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(255);

        horizontalLayout->addWidget(spinBox);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBox_2 = new QSpinBox(horizontalLayoutWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(255);

        horizontalLayout->addWidget(spinBox_2);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        spinBox_3 = new QSpinBox(horizontalLayoutWidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMaximum(255);

        horizontalLayout->addWidget(spinBox_3);

        pushButton_6 = new QPushButton(horizontalLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout->addWidget(pushButton_6);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(960, 110, 75, 23));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(100, 20, 54, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(163, 20, 651, 20));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 80, 75, 23));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(140, 80, 75, 23));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(90, 80, 41, 21));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(220, 80, 31, 21));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(260, 80, 69, 22));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 50, 71, 21));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 50, 141, 20));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(240, 50, 71, 21));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(320, 50, 141, 20));
        pushButton_12 = new QPushButton(groupBox);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(470, 50, 75, 23));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 590, 71, 21));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 630, 1041, 81));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 10, 75, 23));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(70, 40, 69, 22));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 41, 61, 21));
        horizontalLayoutWidget_2 = new QWidget(groupBox_2);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(150, 30, 423, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(horizontalLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_2->addWidget(label_10);

        doubleSpinBox_2 = new QDoubleSpinBox(horizontalLayoutWidget_2);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setValue(1);

        horizontalLayout_2->addWidget(doubleSpinBox_2);

        label_11 = new QLabel(horizontalLayoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_2->addWidget(label_11);

        spinBox_4 = new QSpinBox(horizontalLayoutWidget_2);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setMaximum(255);
        spinBox_4->setValue(255);

        horizontalLayout_2->addWidget(spinBox_4);

        label_12 = new QLabel(horizontalLayoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_2->addWidget(label_12);

        spinBox_5 = new QSpinBox(horizontalLayoutWidget_2);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setMaximum(255);
        spinBox_5->setValue(255);

        horizontalLayout_2->addWidget(spinBox_5);

        label_13 = new QLabel(horizontalLayoutWidget_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_2->addWidget(label_13);

        spinBox_6 = new QSpinBox(horizontalLayoutWidget_2);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setMaximum(255);
        spinBox_6->setValue(255);

        horizontalLayout_2->addWidget(spinBox_6);

        pushButton_7 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout_2->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(960, 40, 75, 23));
        pushButton_9 = new QPushButton(groupBox_2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(850, 10, 91, 23));
        pushButton_10 = new QPushButton(groupBox_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(950, 10, 81, 23));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(100, 10, 54, 21));
        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(160, 10, 69, 22));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(90, 590, 61, 21));
        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(230, 590, 91, 21));
        spinBox_7 = new QSpinBox(centralWidget);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setGeometry(QRect(150, 590, 61, 22));
        PantsPainterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PantsPainterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1060, 23));
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
        groupBox->setTitle(QApplication::translate("PantsPainterClass", "\345\257\271\346\257\224\346\250\241\345\274\217", 0));
        pushButton->setText(QApplication::translate("PantsPainterClass", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", 0));
        radioButton->setText(QApplication::translate("PantsPainterClass", "\346\250\241\345\236\213\344\270\200", 0));
        radioButton_2->setText(QApplication::translate("PantsPainterClass", "\346\250\241\345\236\213\344\272\214", 0));
        label_4->setText(QApplication::translate("PantsPainterClass", "\347\202\271/\347\272\277\345\244\247\345\260\217\357\274\232", 0));
        label->setText(QApplication::translate("PantsPainterClass", "R:", 0));
        label_2->setText(QApplication::translate("PantsPainterClass", "G:", 0));
        label_3->setText(QApplication::translate("PantsPainterClass", "B:", 0));
        pushButton_6->setText(QApplication::translate("PantsPainterClass", "\351\200\211\346\213\251\351\242\234\350\211\262", 0));
        pushButton_2->setText(QApplication::translate("PantsPainterClass", "\345\272\224\347\224\250", 0));
        label_5->setText(QApplication::translate("PantsPainterClass", "\345\275\223\345\211\215\347\233\256\345\275\225\357\274\232", 0));
        label_6->setText(QString());
        pushButton_4->setText(QApplication::translate("PantsPainterClass", "\344\270\212\344\270\200\347\273\204", 0));
        pushButton_5->setText(QApplication::translate("PantsPainterClass", "\344\270\213\344\270\200\347\273\204", 0));
        label_7->setText(QString());
        label_8->setText(QApplication::translate("PantsPainterClass", "\346\255\245\350\277\233\357\274\232", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("PantsPainterClass", "1", 0)
         << QApplication::translate("PantsPainterClass", "5", 0)
         << QApplication::translate("PantsPainterClass", "10", 0)
        );
        label_15->setText(QApplication::translate("PantsPainterClass", "\346\226\207\344\273\266\345\220\215\345\211\215\347\274\2001\357\274\232", 0));
        label_16->setText(QApplication::translate("PantsPainterClass", "\346\226\207\344\273\266\345\220\215\345\211\215\347\274\2002\357\274\232", 0));
        pushButton_12->setText(QApplication::translate("PantsPainterClass", "\350\256\276\345\256\232", 0));
        checkBox->setText(QApplication::translate("PantsPainterClass", "\345\257\271\346\257\224\346\250\241\345\274\217", 0));
        groupBox_2->setTitle(QString());
        pushButton_3->setText(QApplication::translate("PantsPainterClass", "\346\267\273\345\212\240\346\250\241\345\236\213", 0));
        label_9->setText(QApplication::translate("PantsPainterClass", "\345\275\223\345\211\215\346\250\241\345\236\213\357\274\232", 0));
        label_10->setText(QApplication::translate("PantsPainterClass", "\347\202\271/\347\272\277\345\244\247\345\260\217\357\274\232", 0));
        label_11->setText(QApplication::translate("PantsPainterClass", "R:", 0));
        label_12->setText(QApplication::translate("PantsPainterClass", "G:", 0));
        label_13->setText(QApplication::translate("PantsPainterClass", "B:", 0));
        pushButton_7->setText(QApplication::translate("PantsPainterClass", "\351\200\211\346\213\251\351\242\234\350\211\262", 0));
        pushButton_8->setText(QApplication::translate("PantsPainterClass", "\345\272\224\347\224\250", 0));
        pushButton_9->setText(QApplication::translate("PantsPainterClass", "\346\270\205\351\231\244\345\275\223\345\211\215\346\250\241\345\236\213", 0));
        pushButton_10->setText(QApplication::translate("PantsPainterClass", "\346\270\205\351\231\244\346\211\200\346\234\211\346\250\241\345\236\213", 0));
        label_17->setText(QApplication::translate("PantsPainterClass", "\346\267\273\345\212\240\347\261\273\345\236\213\357\274\232", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("PantsPainterClass", "\347\202\271", 0)
         << QApplication::translate("PantsPainterClass", "\347\272\277", 0)
        );
        label_14->setText(QApplication::translate("PantsPainterClass", "\346\227\213\350\275\254\351\200\237\345\272\246\357\274\232", 0));
        pushButton_11->setText(QApplication::translate("PantsPainterClass", "\351\200\211\346\213\251\350\203\214\346\231\257\351\242\234\350\211\262", 0));
    } // retranslateUi

};

namespace Ui {
    class PantsPainterClass: public Ui_PantsPainterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTSPAINTER_H
