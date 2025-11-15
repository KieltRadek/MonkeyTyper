cmake_minimum_required(VERSION 3.28)
project(MonkeyTyper)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.2.1
)

FetchContent_MakeAvailable(SFML fmt)

add_executable(MonkeyTyper main.cpp
        Background.cpp
        Background.h
        mainMenu.cpp
        mainMenu.h
        Game.cpp
        Game.h
        SoundManager.cpp
        SoundManager.h
        GameMode.h
)
target_link_libraries(MonkeyTyper sfml-audio sfml-graphics fmt)

