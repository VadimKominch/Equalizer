/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSlider *verticalSlider;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider_3;
    QSlider *verticalSlider_4;
    QSlider *verticalSlider_5;
    QSlider *verticalSlider_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 30, 311, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 400, 47, 13));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(250, 400, 47, 13));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(320, 400, 47, 13));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(390, 400, 47, 13));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(470, 400, 47, 13));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(550, 400, 47, 13));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(119, 171, 491, 221));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSlider = new QSlider(layoutWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setMinimum(-15);
        verticalSlider->setMaximum(15);
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider);

        verticalSlider_2 = new QSlider(layoutWidget);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setMinimum(-15);
        verticalSlider_2->setMaximum(15);
        verticalSlider_2->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_2);

        verticalSlider_3 = new QSlider(layoutWidget);
        verticalSlider_3->setObjectName(QString::fromUtf8("verticalSlider_3"));
        verticalSlider_3->setMinimum(-15);
        verticalSlider_3->setMaximum(15);
        verticalSlider_3->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_3);

        verticalSlider_4 = new QSlider(layoutWidget);
        verticalSlider_4->setObjectName(QString::fromUtf8("verticalSlider_4"));
        verticalSlider_4->setMinimum(-15);
        verticalSlider_4->setMaximum(15);
        verticalSlider_4->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_4);

        verticalSlider_5 = new QSlider(layoutWidget);
        verticalSlider_5->setObjectName(QString::fromUtf8("verticalSlider_5"));
        verticalSlider_5->setMinimum(-15);
        verticalSlider_5->setMaximum(15);
        verticalSlider_5->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_5);

        verticalSlider_6 = new QSlider(layoutWidget);
        verticalSlider_6->setObjectName(QString::fromUtf8("verticalSlider_6"));
        verticalSlider_6->setMinimum(-15);
        verticalSlider_6->setMaximum(15);
        verticalSlider_6->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_6);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 470, 181, 41));
        QFont font;
        font.setPointSize(20);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 470, 181, 41));
        pushButton_2->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), label_2, SLOT(setNum(int)));
        QObject::connect(verticalSlider_2, SIGNAL(valueChanged(int)), label_3, SLOT(setNum(int)));
        QObject::connect(verticalSlider_3, SIGNAL(valueChanged(int)), label_4, SLOT(setNum(int)));
        QObject::connect(verticalSlider_4, SIGNAL(valueChanged(int)), label_5, SLOT(setNum(int)));
        QObject::connect(verticalSlider_5, SIGNAL(valueChanged(int)), label_6, SLOT(setNum(int)));
        QObject::connect(verticalSlider_6, SIGNAL(valueChanged(int)), label_7, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Equalizer", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">EQUALIZER</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "APPLY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
