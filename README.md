# MUSIC PLAYER MIPT

## Концептуальная модель:
![](https://github.com/fl4cko11/Music_Player_MIPT/blob/main/INTRODUCE/conceptual_model.png)

Определим сущности, **определяющие** плеер:
1) Структура **DurationT** длительность трека
2) Класс **Track** для треков
3) Класс **Playlist** для плейлистов
4) Класс **Player** для плеера
5) Класс **Interface** для визуального взаимодействия с логикой классов выше
6) База Данных **TrackDB** для хранения путей до аудиофайлов, обложек треков, кол-ва прослушиваний

## Логическая модель:
![](https://github.com/fl4cko11/Music_Player_MIPT/blob/main/INTRODUCE/logic_model.png)

## Структура Проекта:
1)  [Декларация и Реализация всех сущностей](https://github.com/fl4cko11/Music_Player_MIPT/tree/main/CPP_classes)
2)  [SQL запросы и файлы для коммуникации программы с базой данных](https://github.com/fl4cko11/Music_Player_MIPT/tree/main/SQL)
3)  [Тесты методов сущностей](https://github.com/fl4cko11/Music_Player_MIPT/tree/main/CPP_tests)
4)  [Интерфейс и Файлы сборки](https://github.com/fl4cko11/Music_Player_MIPT/tree/main/QTInterface)

## Зависимости:
QT6 Widgets, QT6 Multimedia, QT6 Core, Cmake, psql

## Сборка:
```
cd Music_Player_MIPT/QTInterface
mkdir build
cd build
cmake ..
cmake --build .
./QTInterface
