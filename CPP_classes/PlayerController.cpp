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

void Player::Play() {
    player->play();
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
        if (curTrack.GetTrackIndex() + 1 < curPlaylist.GetTracks().size() - 1) {
            curTrack = curPlaylist.GetTracks()[curTrack.GetTrackIndex() + 1];
            player->setSource(QUrl::fromLocalFile(QString::fromStdString(curTrack.GetAudioPathFromDb())));
            Play();
        }
        else {}
    }
    else {
        if (curTrack.GetTrackIndex() + 1 < curPlaylist.GetTracks().size() - 1) {
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
