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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListView *Playlist;
    QPushButton *Play;
    QPushButton *Next;
    QPushButton *Prev;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1553, 975);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #508c60; /* Background color of the main window */\n"
"    border: 2px solid #a2b5cc; /* Border properties */\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Playlist = new QListView(centralwidget);
        Playlist->setObjectName("Playlist");
        Playlist->setGeometry(QRect(520, 170, 511, 651));
        Playlist->setStyleSheet(QString::fromUtf8("QListView {\n"
"    background-color: #f0f0f0; /* Background color of the QListView */\n"
"    border: 1px solid #cccccc; /* Border properties */\n"
"	border-radius: 20px;\n"
"    color: #333333; /* Text color */\n"
"    font-family: \"Segoe UI\"; /* Font family */\n"
"    font-size: 14px; /* Font size */\n"
"}"));
        Play = new QPushButton(centralwidget);
        Play->setObjectName("Play");
        Play->setGeometry(QRect(700, 720, 151, 61));
        Play->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #383d3a;\n"
"}"));
        Next = new QPushButton(centralwidget);
        Next->setObjectName("Next");
        Next->setGeometry(QRect(850, 720, 151, 61));
        Next->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #383d3a;\n"
"}"));
        Prev = new QPushButton(centralwidget);
        Prev->setObjectName("Prev");
        Prev->setGeometry(QRect(550, 720, 151, 61));
        Prev->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #383d3a;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(600, 270, 351, 311));
        label->setFrameShape(QFrame::Shape::Box);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Play->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        Next->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        Prev->setText(QCoreApplication::translate("MainWindow", "Prev", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#55ff7f;\">TextLabel</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
