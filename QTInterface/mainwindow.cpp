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

// Обновление обложки трека
void MainWindow::updateCoverImage()
{
    // Получаем путь к изображению обложки текущего трека как std::string
    std::string currentTrackImagePath = player.curTrack.GetImagePathFromDb();
    QString imagePath = QString::fromStdString(currentTrackImagePath); // Преобразуем std::string в QString

    if (!imagePath.isEmpty()) {
        // Загружаем изображение как QImage
        QImage coverImage(imagePath);

        if (!coverImage.isNull()) {
            // Устанавливаем обложку и масштабируем под QLabel
            ui->label->setPixmap(QPixmap::fromImage(coverImage.scaled(ui->label->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));

            // Устанавливаем обложку также и в label_2, растягивая его на весь экран
            QPixmap scaledPixmap = QPixmap::fromImage(coverImage.scaled(ui->label_2->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect();
            blurEffect->setBlurRadius(10); // Устанавливаем радиус размытия

            // Устанавливаем размытое изображение на label_2
            ui->label_2->setPixmap(scaledPixmap);
            ui->label_2->setGraphicsEffect(blurEffect);
        } else {
            qWarning() << "Не удалось загрузить изображение из:" << imagePath;
            ui->label->clear(); // Очищаем QLabel, если изображение не доступно
            ui->label_2->clear(); // Очищаем label_2, если изображение не доступно
        }
    } else {
        // Удаляем обложку, если путь пуст
        ui->label->clear();
        ui->label_2->clear();
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
    ui->Play->setText("Pause");
}

void MainWindow::on_Prev_clicked()
{
    player.SetPrevTrack();
    updateCoverImage(); // Обновляем изображение на предыдущем треке
    ui->Play->setText("Pause");
}
