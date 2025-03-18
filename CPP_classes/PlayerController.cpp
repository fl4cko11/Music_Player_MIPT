#include "MediaPlayerController.hpp"

Player::Player(Playlist playlist):
    curTrack(playlist.GetLastTrack()), // Используйте переданный playlist, а не curPlaylist
    specialTrack("freestulya", "SaByte", 0, 1, 0),
    curPlaylist(playlist),  // Инициализируем curPlaylist переданным playlist
    isPlaying(false) {
        player = new QMediaPlayer();
        audioOutput = new QAudioOutput();
        player->setAudioOutput(audioOutput); // Связываем player и audioOutput НА СТАНДАРТНЫЙ ВЫВОД
        audioOutput->setVolume(1.0);  // Устанавливаем громкость по умолчанию (от 0.0 до 1.0)
        player->setSource(QUrl::fromLocalFile(QString::fromStdString(curTrack.GetAudioPathFromDb())));
    }

void Player::SetCurTrack(Track &track) {
    curTrack = track;
    player->setSource(QUrl::fromLocalFile(QString::fromStdString(curTrack.GetAudioPathFromDb())));
}

void Player::SetSpecialTrackAsCur() {
    curTrack = specialTrack;

    player->setSource(QUrl::fromLocalFile(QString::fromStdString(curTrack.GetAudioPathFromDb())));
}

void Player::SetNextTrack() {
    if (curTrack.GetTrackIndex() + 1 < curPlaylist.GetTracks().size() - 1) {
        curTrack = curPlaylist.GetTracks()[curTrack.GetTrackIndex() + 1];
        player->setSource(QUrl::fromLocalFile(QString::fromStdString(curTrack.GetAudioPathFromDb())));
    }
    else {}
}

void Player::SetPrevTrack() {
    if (curTrack.GetTrackIndex() - 1 >= 0) {
        curTrack = curPlaylist.GetTracks()[curTrack.GetTrackIndex() + 1];
        player->setSource(QUrl::fromLocalFile(QString::fromStdString(curTrack.GetAudioPathFromDb())));
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
