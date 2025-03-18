#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Player &player): 
    QMainWindow(parent), 
    ui(new Ui::MainWindow),
    player(player)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Play_clicked()
{
    player.Play();
}


void MainWindow::on_Pause_clicked()
{
    player.Pause();
}

void MainWindow::on_Next_clicked()
{
    player.SetNextTrack();
}


void MainWindow::on_Prev_clicked()
{
    player.SetPrevTrack();
}
