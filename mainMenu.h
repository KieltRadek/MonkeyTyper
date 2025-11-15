
#ifndef PROJEKTPJC_MAINMENU_H
#define PROJEKTPJC_MAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "SoundManager.h"
#include <fmt/core.h>

class mainMenu {
public:
    mainMenu();
    void draw(sf::RenderWindow &window);
    void handleInput(sf::RenderWindow &window, sf::Event event, Game& game);
private:
    sf::Texture startButtonTexture;
    sf::Texture exitButtonTexture;
    sf::Texture menuInGameTexture;
    sf::Texture resumeButtonTexture;
    sf::Texture saveButtonTexture;
    sf::Texture soundOnTexture;
    sf::Texture soundOffTexture;
    sf::Texture homeButtonTexture;
    sf::Texture newButtonTexture;
    sf::Texture loadButtonTexture;
    sf::Texture easyButtonTexture;
    sf::Texture normalButtonTexture;
    sf::Texture hardButtonTexture;
    sf::Texture playButtonTexture;
    sf::Texture saveLoadMenuTexture;
    sf::Texture saveLoadButton1Texture;
    sf::Texture saveLoadButton2Texture;
    sf::Texture saveLoadButton3Texture;
    sf::Texture saveLoadButton4Texture;
    sf::Texture saveLoadButton5Texture;
    sf::Texture optionsTexture;
    sf::Texture optionsWindowTexture;
    sf::Texture fontTexture;
    sf::Texture sizeTexture;
    sf::Texture smallButton;
    sf::Texture bigButton;
    sf::Texture BPDots;
    sf::Texture Coolvetica;
    sf::Texture Aller;
    sf::Texture DropDown;
    sf::Texture Green;
    sf::Texture Aqua;
    sf::Texture Purple;
    sf::Texture Color;
    sf::Texture WordSize;

    sf::Sprite startButton;
    sf::Sprite exitButton;
    sf::Sprite menuInGame;
    sf::Sprite resumeButton;
    sf::Sprite exitButtonInGame;
    sf::Sprite saveButton;
    sf::Sprite soundButton;
    sf::Sprite homeButton;
    sf::Sprite newButton;
    sf::Sprite loadButton;
    sf::Sprite easyButton;
    sf::Sprite normalButton;
    sf::Sprite hardButton;
    sf::Sprite playButton;
    sf::Sprite soundButtonAtStart;
    sf::Sprite saveLoadMenu;
    sf::Sprite saveLoadButton1;
    sf::Sprite saveLoadButton2;
    sf::Sprite saveLoadButton3;
    sf::Sprite saveLoadButton4;
    sf::Sprite saveLoadButton5;
    sf::Sprite optionsButton;
    sf::Sprite optionWindow;
    sf::Sprite fontButton;
    sf::Sprite sizeButton;
    sf::Sprite fontCheckButton;
    sf::Sprite BPDotsButton;
    sf::Sprite CoolveticaButton;
    sf::Sprite AllerButton;
    sf::Sprite DropDownButton;
    sf::Sprite DropDownColorButton;
    sf::Sprite ColorButton;
    sf::Sprite GreenButton;
    sf::Sprite AquaButton;
    sf::Sprite PurpleButton;
    sf::Sprite WordSizeButton;
    sf::Sprite SmallButton;

    sf::Text fontChecker;
    sf::Text sizeChecker;

    bool startButtonActive = true;
    bool exitButtonActive = true;
    bool resumeButtonActive = true;
    bool exitButtonInGameActive = false;
    bool saveButtonActive = false;
    bool soundButtonActive = false;
    bool homeButtonActive =false;
    bool newButtonActive = false;
    bool loadButtonActive = false;
    bool easyButtonActive = false;
    bool normalButtonActive = false;
    bool hardButtonActive = false;
    bool playButtonActive = false;
    bool soundButtonAtStartActive = true;
    bool slot1ButtonActive = false;
    bool slot2ButtonActive = false;
    bool slot3ButtonActive = false;
    bool slot4ButtonActive = false;
    bool slot5ButtonActive = false;
    bool fontDropDownActive = false;
    bool fontButtonActive = false;
    bool colorButtonActive  = false;
    bool BPDotsActive = false;
    bool CoolveticaActive = false;
    bool AllerActive = false;
    bool DropDownColorActive = false;
    bool GreenButtonActive = false;
    bool AquaButtonActive = false;
    bool PurpleButtonActive = false;

    bool modeChosen = false;

    bool newButtonClicked = false;
    bool loadButtonClicked = false;
    bool startWasClicked = false;
    bool saveButtonClicked = false;
    bool gameSaved = false;

    bool soundOn = true;

    SoundManager soundManager;

    enum FileState {
        SAVE,
        LOAD
    };

    void updateSlotColors(Game& game, int R, int G, int B, FileState state){
        if(state == LOAD) {
            if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot1.txt") != game.savedGames.end()) {
                saveLoadButton1.setColor(sf::Color(R, G, B));
            } else {
                saveLoadButton1.setColor(sf::Color(255, 0, 0));
            }
            if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot2.txt") != game.savedGames.end()) {
                saveLoadButton2.setColor(sf::Color(R, G, B));
            } else {
                saveLoadButton2.setColor(sf::Color(255, 0, 0));
            }
            if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot3.txt") != game.savedGames.end()) {
                saveLoadButton3.setColor(sf::Color(R, G, B));
            } else {
                saveLoadButton3.setColor(sf::Color(255, 0, 0));
            }
            if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot4.txt") != game.savedGames.end()) {
                saveLoadButton4.setColor(sf::Color(R, G, B));
            } else {
                saveLoadButton4.setColor(sf::Color(255, 0, 0));
            }
            if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot5.txt") != game.savedGames.end()) {
                saveLoadButton5.setColor(sf::Color(R, G, B));
            } else {
                saveLoadButton5.setColor(sf::Color(255, 0, 0));
            }
        }else if(state == SAVE){
            if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot1.txt") != game.savedGames.end()) {
                saveLoadButton1.setColor(sf::Color(R, G, B));
            } else {
                saveLoadButton1.setColor(sf::Color(0, 255, 0));
            }
            if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot2.txt") != game.savedGames.end()) {
                saveLoadButton2.setColor(sf::Color(R, G, B));
            } else {
                saveLoadButton2.setColor(sf::Color(0, 255, 0));
            }
            if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot3.txt") != game.savedGames.end()) {
                saveLoadButton3.setColor(sf::Color(R, G, B));
            } else {
                saveLoadButton3.setColor(sf::Color(0, 255, 0));
            }
            if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot4.txt") != game.savedGames.end()) {
                saveLoadButton4.setColor(sf::Color(R, G, B));
            } else {
                saveLoadButton4.setColor(sf::Color(0, 255, 0));
            }
            if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot5.txt") != game.savedGames.end()) {
                saveLoadButton5.setColor(sf::Color(R, G, B));
            } else {
                saveLoadButton5.setColor(sf::Color(0, 255, 0));
            }
        }
    }
};


#endif //PROJEKTPJC_MAINMENU_H
