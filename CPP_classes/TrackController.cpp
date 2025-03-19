#include "MediaPlayerController.hpp"

DurationT::DurationT(int hours, int minutes, int seconds): hours(hours), minutes(minutes), seconds(seconds) {}

int DurationT::GetHours() {
    return hours;
}

int DurationT::GerMinutes() {
    return minutes;
}

int DurationT::GetSeconds() {
    return seconds;
}

Track::Track(std::string trackName, std::string artistName, int hours, int minutes, int seconds): trackName(trackName), artistName(artistName), trackIndex(0), duration(hours, minutes, seconds) {} // при создании задаём имя трека и артиста

std::string Track::GetAudioPathFromDb() {
    std::string command = "psql -U postgres -d music_player_project_mipt -c \"\\pset format unaligned\" -c \"\\t\" -c \"SELECT path_to_audio FROM tracks WHERE track_name = '" + trackName + "' AND artist_name = '" + artistName + "';\" -o /home/vladh/git-repos/Music_Player_MIPT/SQL/GetAudioPath.txt";    
    int result = system(command.c_str());
    if (result == 0) {
        std::cerr << "Команда выполнена успешно." << std::endl;
    } else {
        std::cerr << "Ошибка при выполнении команды." << std::endl;
    }

    std::ifstream inFile("/home/vladh/git-repos/Music_Player_MIPT/SQL/GetAudioPath.txt");
    std::string audioPath;

    if (inFile.is_open()) {
        std::getline(inFile, audioPath); // Читаем первую строку из файла
        inFile.close(); // Закрываем файл
    } else {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return ""; // Возвращаем пустую строку в случае ошибки
    }

    return audioPath; // Возвращаем полученный путь к аудио
}

std::string Track::GetImagePathFromDb() {
    std::string command = "psql -U postgres -d music_player_project_mipt -c \"\\pset format unaligned\" -c \"\\t\" -c \"SELECT path_to_image FROM tracks WHERE track_name = '" + trackName + "' AND artist_name = '" + artistName + "';\" -o /home/vladh/git-repos/Music_Player_MIPT/SQL/GetImagePath.txt";    
    int result = system(command.c_str()); // Пример команды для отображения содержимого каталога
    if (result == 0) {
        std::cerr << "Команда выполнена успешно." << std::endl;
    } else {
        std::cerr << "Ошибка при выполнении команды." << std::endl;
    }

    std::ifstream inFile("/home/vladh/git-repos/Music_Player_MIPT/SQL/GetImagePath.txt");
    std::string imagePath;

    if (inFile.is_open()) {
        std::getline(inFile, imagePath); // Читаем первую строку из файла
        inFile.close(); // Закрываем файл
    } else {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return ""; // Возвращаем пустую строку в случае ошибки
    }

    return imagePath; // Возвращаем полученный путь к аудио
}

DurationT Track::GetDuration() {
    return duration;
}

std::string Track::GetTrackName() {
    return trackName;
}

std::string Track::GetArtistName() {
    return artistName;
}

int Track::GetTrackIndex() {
    return trackIndex;
}

void Track::SetTrackIndex(int index) {
    trackIndex = index;
}
