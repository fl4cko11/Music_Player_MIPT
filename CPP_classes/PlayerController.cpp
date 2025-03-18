#include "MediaPlayerController.hpp"

Player::Player(Playlist playlist):
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

void Player::SetCurTrack(Track &track) {
    curTrack = track;
    QString qPath = QString::fromStdString(curTrack.GetAudioPathFromDb()); // Преобразование std::string в QString
    player->setSource(QUrl::fromLocalFile(qPath));
}

void Player::SetSpecialTrackAsCur() {
    curTrack = specialTrack;
    QString qPath = QString::fromStdString(curTrack.GetAudioPathFromDb()); // Преобразование std::string в QString
    player->setSource(QUrl::fromLocalFile(qPath));
}

void Player::SetNextTrack() {
    if (curTrack.GetTrackIndex() + 1 < curPlaylist.GetTracks().size() - 1) {
        curTrack = curPlaylist.GetTracks()[curTrack.GetTrackIndex() + 1];
        QString qPath = QString::fromStdString(curTrack.GetAudioPathFromDb()); // Преобразование std::string в QString
        player->setSource(QUrl::fromLocalFile(qPath));
    }
    else {}
}

void Player::SetPrevTrack() {
    if (curTrack.GetTrackIndex() - 1 >= 0) {
        curTrack = curPlaylist.GetTracks()[curTrack.GetTrackIndex() + 1];
        QString qPath = QString::fromStdString(curTrack.GetAudioPathFromDb()); // Преобразование std::string в QString
        player->setSource(QUrl::fromLocalFile(qPath));
    }
    else {}
}

void Player::Play() {
    player->play();
    isPlaying = true;
}

void Player::Pause() {
    player->pause();
    isPlaying = false;
}
