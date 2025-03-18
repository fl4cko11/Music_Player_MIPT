#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Track specialTrack{"freestulya", "SaByte", 0, 1, 0};
    Playlist ATMO{"ATMO"};
    ATMO.AddTrackToPlaylist(specialTrack);
    Player player{ATMO};
    
    QApplication a(argc, argv);
    MainWindow w{nullptr, };
    w.show();
    return a.exec();
}
