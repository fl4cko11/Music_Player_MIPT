#include "mainwindow.h"
#include <thread>

int main(int argc, char *argv[])
{
    Track track1{"praise", "asap", 0, 0, 0};
    Track track2{"o_yeah", "in_yan", 0, 0, 0};
    Playlist ATMO{"ATMO"};
    ATMO.AddTrackToPlaylist(track1);
    ATMO.AddTrackToPlaylist(track2);
    Player player{ATMO};
    Player &player_ref = player;

    QApplication a(argc, argv);
    MainWindow w{nullptr, player_ref};

    // Устанавливаем жесткий размер окна 800x650
    w.setFixedSize(800, 650);

    std::thread countListeningThread(&Player::CountListening, &player);
    countListeningThread.detach(); // Отделяем поток, чтобы продолжить выполнение
    
    w.show();
    int result = a.exec();
    
    running = false; // Устанавливаем флаг для завершения работы потока
    
    return result;
}
