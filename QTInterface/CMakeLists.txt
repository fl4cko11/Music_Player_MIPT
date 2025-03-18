cmake_minimum_required(VERSION 3.16)

project(QTInterface VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Найдите необходимые модули: Widgets и Multimedia
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Multimedia)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Multimedia)

set(PROJECT_SOURCES
        ../CPP_classes/MediaPlayerController.hpp
        ../CPP_classes/PlayerController.cpp
        ../CPP_classes/PlaylistController.cpp
        ../CPP_classes/TrackController.cpp
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)

    qt_add_executable(QTInterface
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

else()

    if(ANDROID)
        add_library(QTInterface SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(QTInterface
            ${PROJECT_SOURCES}
        )
    endif()

endif()

# Подключите зависимости
target_link_libraries(QTInterface PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Multimedia)

# Дополнительные настройки для iOS и macOS
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QTInterface)
endif()

set_target_properties(QTInterface PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)

install(TARGETS QTInterface
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QTInterface)
endif()
