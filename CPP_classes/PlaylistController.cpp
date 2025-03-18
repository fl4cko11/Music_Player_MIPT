#include "MediaPlayerController.hpp"

Playlist::Playlist(std::string playlistName): playlistName(playlistName), tracks() {} // при создании задаётся имя плейлиста, но сам плейлист пустой с помощью кнопки можно добавить трек в плейлист

void Playlist::AddTrackToPlaylist(Track &track) {
    track.SetTrackIndex(tracks.size());
    tracks.push_back(track);
}

std::string Playlist::GetPlaylistName() {
    return playlistName;
}

Track Playlist::GetLastTrack() {
    return tracks.back();
}

std::vector<Track> Playlist::GetTracks() {
    return tracks;
}
