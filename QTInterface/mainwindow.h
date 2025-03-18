#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "/home/vladh/git-repos/Music_Player_MIPT/CPP_classes/MediaPlayerController.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, Player &player);
    ~MainWindow();

private slots:
    void on_Play_clicked();

    void on_Pause_clicked();

    void on_Next_clicked();

    void on_Prev_clicked();

private:
    Ui::MainWindow *ui;
    Player player;
};
#endif // MAINWINDOW_H
