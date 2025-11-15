#include "SoundManager.h"
#include <fmt/core.h>
#include <SFML/Audio.hpp>

extern std::string MainPath;

    SoundManager::SoundManager(){
        if(!MenuSoundBuffer.loadFromFile(MainPath + "assets\\Sounds\\MenuSound.wav")){
            fmt::print("Nie udalo sie zaladowac dzwieku menu");
        }
        if(!LoseSoundBuffer.loadFromFile(MainPath + "assets\\Sounds\\LoseSound.wav")){
            fmt::print("Nie udalo sie zaladowac dzwieku przegranej");
        }
        if(!music.openFromFile(MainPath + "assets\\Sounds\\Music.ogg")){
            fmt::print("Nie udalo sie zaladowac dzwieku muzyki");
        }
        MenuSound.setBuffer(MenuSoundBuffer);
        LoseSound.setBuffer(LoseSoundBuffer);
    }

    void SoundManager::stopMusic(){
        if(music.getStatus() == sf::Music::Paused || music.getStatus() == sf::Music::Stopped){
            music.play();
        }
        else if(music.getStatus() == sf::Music::Playing){
            music.pause();
        }
    }

    void SoundManager::playMusic(){
        music.setLoop(true);
        music.play();
    }

    void SoundManager::playMenuSound(){
        MenuSound.play();
    }

    void SoundManager::playLoseSound(){
        music.setVolume(0);
        LoseSound.play();
        music.setVolume(50);
    }

