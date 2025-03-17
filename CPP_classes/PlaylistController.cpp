#include "MediaPlayerController.hpp"

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
