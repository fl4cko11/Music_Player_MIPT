#ifndef MEDIAPLAYERCONTROLLER_HPP
#define MEDIAPLAYERCONTROLLER_HPP

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
        DurationT(int hours, int minutes, int seconds);
        int GetHours();
        int GerMinutes();
        int GetSeconds();
};

class Track {
    private:
        std::string trackName;
        std::string artistName;
        DurationT duration;
        int trackIndex;
    public:
        Track(std::string trackName, std::string artistName, int hours, int minutes, int seconds); // при создании задаём имя трека и артиста

        std::string GetAudioPathFromDb(); 
        std::string GetImagePathFromDb();
        DurationT GetDuration(); // через БД получаем путь до файла с треком и файла с обложкой
        std::string GetTrackName();
        std::string GetArtistName();
        int GetTrackIndex();
        void SetTrackIndex(int index);
};

class Playlist {
    private:
        std::string playlistName;
        std::vector<Track> tracks;
    public:
        Playlist(std::string playlistName); // при создании задаётся имя плейлиста, но сам плейлист пустой с помощью кнопки можно добавить трек в плейлист

        void AddTrackToPlaylist(Track &track);
        std::string GetPlaylistName();
        Track GetLastTrack();
        std::vector<Track> GetTracks();
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
        Player(Playlist playlist);
        
        void SetCurTrack(Track &track);
        void SetSpecialTrackAsCur();
        void SetNextTrack();
        void SetPrevTrack();
        void Play();
        void Pause();
};
#endif
