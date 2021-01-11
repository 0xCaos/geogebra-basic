/********************************************************************************
** Form generated from reading UI file 'geogebra1.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEOGEBRA1_H
#define UI_GEOGEBRA1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Geogebra1
{
public:
    QAction *actionChiudi;
    QAction *actionImporta;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Geogebra1)
    {
        if (Geogebra1->objectName().isEmpty())
            Geogebra1->setObjectName(QString::fromUtf8("Geogebra1"));
        Geogebra1->resize(1277, 719);
        actionChiudi = new QAction(Geogebra1);
        actionChiudi->setObjectName(QString::fromUtf8("actionChiudi"));
        actionImporta = new QAction(Geogebra1);
        actionImporta->setObjectName(QString::fromUtf8("actionImporta"));
        centralwidget = new QWidget(Geogebra1);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Geogebra1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Geogebra1);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1277, 22));
        Geogebra1->setMenuBar(menubar);
        statusbar = new QStatusBar(Geogebra1);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Geogebra1->setStatusBar(statusbar);

        retranslateUi(Geogebra1);

        QMetaObject::connectSlotsByName(Geogebra1);
    } // setupUi

    void retranslateUi(QMainWindow *Geogebra1)
    {
        Geogebra1->setWindowTitle(QCoreApplication::translate("Geogebra1", "Geogebra1", nullptr));
        actionChiudi->setText(QCoreApplication::translate("Geogebra1", "Salva", nullptr));
        actionImporta->setText(QCoreApplication::translate("Geogebra1", "Importa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Geogebra1: public Ui_Geogebra1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEOGEBRA1_H
