#ifndef MEDIAPLAYERCONTROLLER.H
#define MEDIAPLAYERCONTROLLER.H

#include <iostream>
#include <string>
#include <vector>
#include <pqxx/pqxx>
#include <QMediaPlayer>  // Подключаем класс QMediaPlayer для работы с аудиофайлами
#include <QUrl>          // Подключаем класс QUrl для работы с URL-адресами (включая локальные файлы)
#include <QObject>       // Подключаем базовый класс QObject для работы с механизмом сигналов и слотов
#include <QApplication>  // Подключаем класс QApplication для создания графического интерфейса приложений Qt
#include <QAudioOutput> // Для управления громкостью и выводом звука

class DurationT {
    private:
        int hours;
        int minutes;
        int seconds;
    public:
        DurationT(int hours, int minutes, int seconds): hours(hours), minutes(minutes), seconds(seconds) {}
        int GetHours() {}
        int GerMinutes() {}
        int GetSeconds() {}
};

class Track {
    private:
        std::string trackName;
        std::string artistName;
        DurationT duration;
        int trackIndex;
    public:
        Track(std::string trackName, std::string artistName, int hours, int minutes, int seconds): trackName(trackName), artistName(artistName), trackIndex(0), duration(hours, minutes, seconds) {} // при создании задаём имя трека и артиста
        
        std::string GetAudioPathFromDb() {} 
        std::string GetImagePathFromDb() {}
        DurationT GetDuration() {} // через БД получаем путь до файла с треком и файла с обложкой
        std::string GetTrackName() {}
        std::string GetArtistName() {}
        int GetTrackIndex() {}
        void SetTrackIndex(int index) {}
};

class Playlist {
    private:
        std::string playlistName;
        std::vector<Track> tracks;
    public:
        Playlist(std::string playlistName): playlistName(playlistName), tracks() {} // при создании задаётся имя плейлиста, но сам плейлист пустой с помощью кнопки можно добавить трек в плейлист
        
        void AddTrackToPlaylist(Track &track) {}
        std::string GetPlaylistName() {}
        Track GetLastTrack() {}
        std::vector<Track> GetTracks() {}
};

class Player {
    private:
        QMediaPlayer *player; // Указатель на экземпляр QMediaPlayer, используемый для воспроизведения аудио
        QAudioOutput *audioOutput; // Добавляем аудиовыход
        Track curTrack;
        Track specialTrack;
        Playlist curPlaylist;
        bool isPlaying;

    public:
        Player(Playlist playlist): 
            curTrack(playlist.GetLastTrack()), // Используйте переданный playlist, а не curPlaylist
            specialTrack("freestulya", "SaByte", 0, 1, 0),
            curPlaylist(playlist),  // Инициализируем curPlaylist переданным playlist
            isPlaying(false) {
                player = new QMediaPlayer();
                audioOutput = new QAudioOutput();
                player->setAudioOutput(audioOutput); // Связываем player и audioOutput
                audioOutput->setVolume(1.0);  // Устанавливаем громкость по умолчанию (от 0.0 до 1.0)
                QString qPath = QString::fromStdString(curTrack.GetAudioPathFromDb()); // Преобразование std::string в QString
                player->setSource(QUrl::fromLocalFile(qPath));
            }
        
        void SetCurTrack(Track &track) {}
        void SetSpecialTrackAsCur() {}
        void SetNextTrack() {}
        void SetPrevTrack() {}
        void Play() {}
        void Pause() {}
};
#endif
