#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Player &player) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    player(player)
{
    ui->setupUi(this);
    updateCoverImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateCoverImage()
{
    QPixmap coverImage; // Declare a variable to hold the cover image

    // Get the current track's cover image path as std::string
    std::string currentTrackImagePath = player.curTrack.GetImagePathFromDb();

    std::cerr << currentTrackImagePath << std::endl;

    QString imagePath = QString::fromStdString(currentTrackImagePath); // Convert std::string to QString

    if (!imagePath.isEmpty()) {
        coverImage.load(imagePath); // Load the image
        ui->label->setPixmap(coverImage.scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation)); // Set the pixmap and scale to fit the label
    } 
    else {
        // Optionally handle the case where there is no cover image
        ui->label->clear(); // Clear the label if no image is available
    }
}

void MainWindow::on_Play_clicked()
{
    // Create the animations
    QPropertyAnimation *animation = new QPropertyAnimation(ui->Play, "size");
    animation->setDuration(20);
    animation->setStartValue(QSize(ui->Play->width(), ui->Play->height())); // Start size
    animation->setEndValue(QSize(ui->Play->width() + 10, ui->Play->height() + 10)); // End size (enlargement)

    // Creating the reverse animation
    QPropertyAnimation *reverseAnimation = new QPropertyAnimation(ui->Play, "size");
    reverseAnimation->setDuration(20);
    reverseAnimation->setStartValue(animation->endValue());
    reverseAnimation->setEndValue(QSize(ui->Play->width(), ui->Play->height())); // Return to original size

    // Connect the finished signal of the first animation to start the reverse animation using a lambda
    connect(animation, &QPropertyAnimation::finished, this, [reverseAnimation]() {
        reverseAnimation->start();
    });

    // Start the initial animation
    animation->start();

    // Perform the player action, if necessary
    if (player.isPlaying) {
        player.Pause();
        ui->Play->setText("Play");
    } else {
        player.Play();
        ui->Play->setText("Pause");
    }

    // Обновляем изображение обложки после действия
    updateCoverImage();
}

void MainWindow::on_Next_clicked()
{
    player.SetNextTrack();
    updateCoverImage(); // Обновляем изображение на следующем треке
}

void MainWindow::on_Prev_clicked()
{
    player.SetPrevTrack();
    updateCoverImage(); // Обновляем изображение на предыдущем треке
}
