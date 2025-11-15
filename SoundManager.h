#ifndef PROJEKTPJC_SOUNDMANAGER_H
#define PROJEKTPJC_SOUNDMANAGER_H

#include <SFML/Audio.hpp>


class SoundManager {
public:
    SoundManager();
    void playMusic();
    void playMenuSound();
    void playLoseSound();
    void stopMusic();
private:
    sf::SoundBuffer MenuSoundBuffer;
    sf::SoundBuffer LoseSoundBuffer;
    sf::SoundBuffer musicBuffer;
    sf::Sound MenuSound;
    sf::Sound LoseSound;
    sf::Music music;
};


#endif //PROJEKTPJC_SOUNDMANAGER_H
