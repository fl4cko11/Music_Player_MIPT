#include "MediaPlayerController.hpp"

int DurationT::GetHours() {
    return hours;
}

int DurationT::GerMinutes() {
    return minutes;
}

int DurationT::GetSeconds() {
    return seconds;
}

std::string Track::GetAudioPathFromDb() {
    try {
        pqxx::connection conn("dbname=music_player_project_mipt user=postgres");
        if (!conn.is_open()) {
            throw std::runtime_error("Can't open database");
        }

        // Подготовленный SQL запрос
        std::string sql = "SELECT path_to_audio FROM tracks WHERE track_name = " + conn.quote(trackName) + " AND artist_name = " + conn.quote(artistName) + ";";
        pqxx::work txn(conn);
        pqxx::result result = txn.exec(sql);

        // Проверка на существование результата
        if (result.size() > 0) {
            return result[0][0].as<std::string>(); // Возвращает путь
        } 
        else {
            return "Трек не найден"; // Обработка отсутствия результата
        }
        } 

    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return "Ошибка при извлечении пути";
    }
}

std::string Track::GetImagePathFromDb() {
    try {
        pqxx::connection conn("dbname=music_player_project_mipt user=postgres");
        if (!conn.is_open()) {
            throw std::runtime_error("Can't open database");
        }

        // Подготовленный SQL запрос
        std::string sql = "SELECT path_to_image FROM tracks WHERE track_name = " + conn.quote(trackName) + " AND artist_name = " + conn.quote(artistName) + ";";
        pqxx::work txn(conn);
        pqxx::result result = txn.exec(sql);

        // Проверка на существование результата
        if (result.size() > 0) {
            return result[0][0].as<std::string>(); // Возвращает путь
        } 
        else {
            return "Трек не найден"; // Обработка отсутствия результата
        }
        } 

    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return "Ошибка при извлечении пути";
    }
}

DurationT Track::GetDuration() {
    return duration;
}

std::string Track::GetTrackName() {
    return trackName;
}

std::string Track::GetTrackName() {
    return artistName;
}

int Track::GetTrackIndex() {
    return trackIndex;
}

void Track::SetTrackIndex(int index) {
    trackIndex = index;
}
