#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Track specialTrack{"praise", "asap", 0, 1, 0};
    Playlist ATMO{"ATMO"};
    ATMO.AddTrackToPlaylist(specialTrack);
    Player player{ATMO};
    Player &player_ref = player;

    QApplication a(argc, argv);
    MainWindow w{nullptr, player_ref};

    // Устанавливаем жесткий размер окна 800x650
    w.setFixedSize(800, 650);

    w.show();
    return a.exec();
}
