#include "MediaPlayerController.hpp"

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
