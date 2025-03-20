#include "MediaPlayerController.hpp"

std::condition_variable cv;
std::mutex cv_m;
std::atomic<bool> ready(false); 
std::atomic<bool> running(true); // Флаг для управления потоком

Player::Player(Playlist playlist):
    curTrack(playlist.GetLastTrack()),
    specialTrack("freestulya", "SaByte", 0, 1, 0),
    curPlaylist(playlist),  // Инициализируем curPlaylist переданным playlist
    isPlaying(false) {
        
        player = new QMediaPlayer();
        audioOutput = new QAudioOutput();
        player->setAudioOutput(audioOutput); // Связываем player и audioOutput НА СТАНДАРТНЫЙ ВЫВОД
        audioOutput->setVolume(1.0);  // Устанавливаем громкость по умолчанию (от 0.0 до 1.0)
        player->setSource(QUrl::fromLocalFile(QString::fromStdString(curTrack.GetAudioPathFromDb())));
    }

void NotifyThread() {
    ready = true; // Устанавливаем флаг
    cv.notify_one(); // Уведомляем поток
}

void Player::Play() {
    player->play();
    NotifyThread(); // Добавляем прослушивание
    isPlaying = true;
}

void Player::Pause() {
    player->pause();
    isPlaying = false;
}

void Player::SetCurTrack(Track &track) {
    curTrack = track;
    player->setSource(QUrl::fromLocalFile(QString::fromStdString(curTrack.GetAudioPathFromDb())));
}

void Player::SetSpecialTrackAsCur() {
    Pause();
    curTrack = specialTrack;
    player->setSource(QUrl::fromLocalFile(QString::fromStdString(curTrack.GetAudioPathFromDb())));
    Play();
}

void Player::SetNextTrack() {
    if (isPlaying) {
        Pause();
        if (curTrack.GetTrackIndex() + 1 < curPlaylist.GetTracks().size()) {
            curTrack = curPlaylist.GetTracks()[curTrack.GetTrackIndex() + 1];
            player->setSource(QUrl::fromLocalFile(QString::fromStdString(curTrack.GetAudioPathFromDb())));
            Play();
        }
        else {}
    }
    else {
        if (curTrack.GetTrackIndex() + 1 < curPlaylist.GetTracks().size()) {
            curTrack = curPlaylist.GetTracks()[curTrack.GetTrackIndex() + 1];
            player->setSource(QUrl::fromLocalFile(QString::fromStdString(curTrack.GetAudioPathFromDb())));
            Play();
        }
        else {}
    }
}

void Player::SetPrevTrack() {
    if (isPlaying) {
        Pause();
        if (curTrack.GetTrackIndex() - 1 >= 0) {
            curTrack = curPlaylist.GetTracks()[curTrack.GetTrackIndex() - 1];
            player->setSource(QUrl::fromLocalFile(QString::fromStdString(curTrack.GetAudioPathFromDb())));
            Play();
        }
        else {}
    }
    else {
        if (curTrack.GetTrackIndex() - 1 >= 0) {
            curTrack = curPlaylist.GetTracks()[curTrack.GetTrackIndex() - 1];
            player->setSource(QUrl::fromLocalFile(QString::fromStdString(curTrack.GetAudioPathFromDb())));
            Play();
        }
        else {}
    }
}

void Player::CountListening() { // функция для потока
    while (running) {
        std::unique_lock<std::mutex> lk(cv_m);
        cv.wait(lk, [] { return ready.load(); }); // Ожидаем сигнал

        std::string command = "psql -U postgres -d music_player_project_mipt -c \"UPDATE tracks SET listening = listening + 1 WHERE track_name = '" + curTrack.GetTrackName() + "' AND artist_name = '" + curTrack.GetArtistName() + "';\"";    
        int result = system(command.c_str());
        if (result == 0) {
            std::cerr << "Команда выполнена успешно." << std::endl;
        } 
        else {
            std::cerr << "Ошибка при выполнении команды." << std::endl;
        }

        ready = false;
    }
}
