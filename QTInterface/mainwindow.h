#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "/home/vladh/git-repos/Music_Player_MIPT/CPP_classes/MediaPlayerController.hpp"
#include <QPropertyAnimation>
#include <QPixmap>
#include <QString>          
#include <QSize>            
#include <QLabel>
#include <QGraphicsBlurEffect>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, Player &player);
    ~MainWindow();
    void updateCoverImage();
    
private slots:
    void on_Play_clicked();

    void on_Next_clicked();

    void on_Prev_clicked();

private:
    Ui::MainWindow *ui;
    Player player;
};
#endif // MAINWINDOW_H
