/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListView *listView;
    QPushButton *Play;
    QPushButton *Pause;
    QPushButton *Next;
    QPushButton *Prev;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1120, 624);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(10, 30, 511, 541));
        Play = new QPushButton(centralwidget);
        Play->setObjectName("Play");
        Play->setGeometry(QRect(630, 320, 151, 61));
        Pause = new QPushButton(centralwidget);
        Pause->setObjectName("Pause");
        Pause->setGeometry(QRect(840, 320, 151, 61));
        Next = new QPushButton(centralwidget);
        Next->setObjectName("Next");
        Next->setGeometry(QRect(840, 410, 151, 61));
        Prev = new QPushButton(centralwidget);
        Prev->setObjectName("Prev");
        Prev->setGeometry(QRect(630, 410, 151, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1120, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Play->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        Pause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        Next->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        Prev->setText(QCoreApplication::translate("MainWindow", "Prev", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
