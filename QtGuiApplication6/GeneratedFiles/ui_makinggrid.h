/********************************************************************************
** Form generated from reading UI file 'makinggrid.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKINGGRID_H
#define UI_MAKINGGRID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_makinggridClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *makinggridClass)
    {
        if (makinggridClass->objectName().isEmpty())
            makinggridClass->setObjectName(QString::fromUtf8("makinggridClass"));
        makinggridClass->resize(600, 400);
        menuBar = new QMenuBar(makinggridClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        makinggridClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(makinggridClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        makinggridClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(makinggridClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        makinggridClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(makinggridClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        makinggridClass->setStatusBar(statusBar);

        retranslateUi(makinggridClass);

        QMetaObject::connectSlotsByName(makinggridClass);
    } // setupUi

    void retranslateUi(QMainWindow *makinggridClass)
    {
        makinggridClass->setWindowTitle(QApplication::translate("makinggridClass", "makinggrid", nullptr));
    } // retranslateUi

};

namespace Ui {
    class makinggridClass: public Ui_makinggridClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKINGGRID_H
