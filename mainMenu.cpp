#include "mainMenu.h"
#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include "Game.h"

extern std::string MainPath;

extern bool gameStarted;
extern bool gameStopped;
extern bool gameIsLose;

sf::Font ChosenFont;
sf::Font menuFont;
sf::Color ChosenColor;
int ChosenSize = 4;

mainMenu::mainMenu() {
    if (!ChosenFont.loadFromFile(MainPath + "assets\\Fonts\\BPdots.otf")) {
        fmt::println("Nie udało się załadować czcionki Głównej");
    }
    if (!menuFont.loadFromFile(MainPath + "assets\\Fonts\\BPdots.otf")) {
        fmt::println("Nie udało się załadować czcionki FontButton");
    }
    if (!startButtonTexture.loadFromFile(MainPath + "assets\\Buttons\\Start.png")) {
        fmt::println("Nie udało się załadować tekstury Start");
    }
    if (!exitButtonTexture.loadFromFile(MainPath + "assets\\Buttons\\Exit.png")) {
        fmt::println("Nie udało się załadować tekstury Exit");
    }
    if (!menuInGameTexture.loadFromFile(MainPath + "assets\\Buttons\\ClearMenu.png")) {
        fmt::println("Nie udało się załadować tekstury Menu");
    }
    if (!resumeButtonTexture.loadFromFile(MainPath + "assets\\Buttons\\Resume.png")) {
        fmt::println("Nie udało się załadować tekstury Resume");
    }
    if(!saveButtonTexture.loadFromFile(MainPath + "assets\\Buttons\\Save.png")) {
        fmt::println("Nie udało się załadować tekstury Save");
    }
    if(!soundOnTexture.loadFromFile(MainPath + "assets\\Buttons\\SoundOn.png")) {
        fmt::println("Nie udało się załadować tekstury SoundOn");
    }
    if(!soundOffTexture.loadFromFile(MainPath + "assets\\Buttons\\SoundOff.png")) {
        fmt::println("Nie udało się załadować tekstury SoundOff");
    }
    if(!homeButtonTexture.loadFromFile(MainPath + "assets\\Buttons\\Home.png")) {
        fmt::println("Nie udało się załadować tekstury Home");
    }
    if(!newButtonTexture.loadFromFile(MainPath + "assets\\Buttons\\New.png")) {
        fmt::println("Nie udało się załadować tekstury New");
    }
    if(!loadButtonTexture.loadFromFile(MainPath + "assets\\Buttons\\Load.png")) {
        fmt::println("Nie udało się załadować tekstury Load");
    }
    if(!easyButtonTexture.loadFromFile(MainPath + "assets\\Buttons\\Easy.png")) {
        fmt::println("Nie udało się załadować tekstury Easy");
    }
    if(!normalButtonTexture.loadFromFile(MainPath + "assets\\Buttons\\Normal.png")) {
        fmt::println("Nie udało się załadować tekstury Normal");
    }
    if(!hardButtonTexture.loadFromFile(MainPath + "assets\\Buttons\\Hard.png")) {
        fmt::println("Nie udało się załadować tekstury Hard");
    }
    if(!playButtonTexture.loadFromFile(MainPath + "assets\\Buttons\\Play.png")) {
        fmt::println("Nie udało się załadować tekstury Play");
    }
    if(!saveLoadMenuTexture.loadFromFile(MainPath + "assets\\Buttons\\ClearMenu.png")) {
        fmt::println("Nie udało się załadować tekstury SaveLoadMenu");
    }
    if(!saveLoadButton1Texture.loadFromFile(MainPath + "assets\\Buttons\\SaveLoadButton1.png")) {
        fmt::println("Nie udało się załadować tekstury SaveLoadButton1");
    }
    if(!saveLoadButton2Texture.loadFromFile(MainPath + "assets\\Buttons\\SaveLoadButton2.png")) {
        fmt::println("Nie udało się załadować tekstury SaveLoadButton2");
    }
    if(!saveLoadButton3Texture.loadFromFile(MainPath + "assets\\Buttons\\SaveLoadButton3.png")) {
        fmt::println("Nie udało się załadować tekstury SaveLoadButton3");
    }
    if(!saveLoadButton4Texture.loadFromFile(MainPath + "assets\\Buttons\\SaveLoadButton4.png")) {
        fmt::println("Nie udało się załadować tekstury SaveLoadButton4");
    }
    if(!saveLoadButton5Texture.loadFromFile(MainPath + "assets\\Buttons\\SaveLoadButton5.png")) {
        fmt::println("Nie udało się załadować tekstury SaveLoadButton5");
    }
    if(!optionsTexture.loadFromFile(MainPath + "assets\\Buttons\\OptionsTextureForMenu.png")) {
        fmt::println("Nie udało się załadować tekstury Options");
    }
    if(!optionsWindowTexture.loadFromFile(MainPath + "assets\\Buttons\\SaveLoadMenu.png")) {
        fmt::println("Nie udało się załadować tekstury OptionsWindow");
    }
    if(!fontTexture.loadFromFile(MainPath + "assets\\Buttons\\FontButton.png")) {
        fmt::println("Nie udało się załadować tekstury Font");
    }
    if(!Color.loadFromFile(MainPath + "assets\\Buttons\\Color.png")) {
        fmt::println("Nie udało się załadować tekstury Color");
    }
    if(!bigButton.loadFromFile(MainPath + "assets\\Buttons\\BigButton.png")) {
        fmt::println("Nie udało się załadować tekstury SmallButton");
    }
    if(!BPDots.loadFromFile(MainPath + "assets\\Buttons\\BPdotsButton.png")) {
        fmt::println("Nie udało się załadować tekstury BPDots");
    }
    if(!Coolvetica.loadFromFile(MainPath + "assets\\Buttons\\CoolveticaButton.png")) {
        fmt::println("Nie udało się załadować tekstury Coolvetica");
    }
    if(!Aller.loadFromFile(MainPath + "assets\\Buttons\\AllerButton.png")) {
        fmt::println("Nie udało się załadować tekstury Aller");
    }
    if(!DropDown.loadFromFile(MainPath + "assets\\Buttons\\DropDown.png")) {
        fmt::println("Nie udało się załadować tekstury DropDown");
    }
    if(!Green.loadFromFile(MainPath + "assets\\Buttons\\Green.png")) {
        fmt::println("Nie udało się załadować tekstury Green");
    }
    if(!Aqua.loadFromFile(MainPath + "assets\\Buttons\\Aqua.png")) {
        fmt::println("Nie udało się załadować tekstury Aqua");
    }
    if(!Purple.loadFromFile(MainPath + "assets\\Buttons\\Purple.png")) {
        fmt::println("Nie udało się załadować tekstury Purple");
    }
    if(!WordSize.loadFromFile(MainPath + "assets\\Buttons\\WordSize.png")) {
        fmt::println("Nie udało się załadować tekstury WordSize");
    }
    if(!smallButton.loadFromFile(MainPath + "assets\\Buttons\\SmallButton.png")) {
        fmt::println("Nie udało się załadować tekstury SmallButton");
    }


    startButton.setTexture(startButtonTexture);
    startButton.setPosition(750, 500);
    startButton.setScale(10, 10);

    soundButtonAtStart.setTexture(soundOnTexture);
    soundButtonAtStart.setPosition(1050, 490);
    soundButtonAtStart.setScale(10, 10);

    exitButton.setTexture(exitButtonTexture);
    exitButton.setPosition(30, 30);
    exitButton.setScale(5, 5);

    menuInGame.setTexture(menuInGameTexture);
    menuInGame.setPosition(800, 300);
    menuInGame.setScale(7, 7);

    resumeButton.setTexture(resumeButtonTexture);
    resumeButton.setPosition(845, 400);
    resumeButton.setScale(5, 5);

    saveButton.setTexture(saveButtonTexture);
    saveButton.setPosition(845, 500);
    saveButton.setScale(5, 5);

    exitButtonInGame.setTexture(exitButtonTexture);
    exitButtonInGame.setPosition(845, 600);
    exitButtonInGame.setScale(5, 5);

    soundButton.setTexture(soundOnTexture);
    soundButton.setPosition(1000, 495);
    soundButton.setScale(5, 5);

    homeButton.setTexture(homeButtonTexture);
    homeButton.setPosition(1000, 595);
    homeButton.setScale(5, 5);

    newButton.setTexture(newButtonTexture);
    newButton.setPosition(800, 500);
    newButton.setScale(7, 7);

    loadButton.setTexture(loadButtonTexture);
    loadButton.setPosition(800, 650);
    loadButton.setScale(7, 7);

    easyButton.setTexture(easyButtonTexture);
    easyButton.setPosition(800, 450);
    easyButton.setScale(7, 7);

    normalButton.setTexture(normalButtonTexture);
    normalButton.setPosition(750, 550);
    normalButton.setScale(7, 7);

    hardButton.setTexture(hardButtonTexture);
    hardButton.setPosition(800, 650);
    hardButton.setScale(7, 7);

    playButton.setTexture(playButtonTexture);
    playButton.setPosition(800, 800);
    playButton.setScale(7, 7);

    saveLoadMenu.setTexture(saveLoadMenuTexture);
    saveLoadMenu.setPosition(730, 250);
    saveLoadMenu.setScale(8, 7);

    saveLoadButton1.setTexture(saveLoadButton1Texture);
    saveLoadButton1.setPosition(800, 300);
    saveLoadButton1.setScale(5, 5);
    saveLoadButton1.setColor(sf::Color(255, 255, 255, 255));

    saveLoadButton2.setTexture(saveLoadButton2Texture);
    saveLoadButton2.setPosition(800, 375);
    saveLoadButton2.setScale(5, 5);
    saveLoadButton2.setColor(sf::Color(255, 255, 255, 255));

    saveLoadButton3.setTexture(saveLoadButton3Texture);
    saveLoadButton3.setPosition(800, 450);
    saveLoadButton3.setScale(5, 5);
    saveLoadButton1.setColor(sf::Color(255, 255, 255, 255));

    saveLoadButton4.setTexture(saveLoadButton4Texture);
    saveLoadButton4.setPosition(800, 525);
    saveLoadButton4.setScale(5, 5);
    saveLoadButton1.setColor(sf::Color(255, 255, 255, 255));

    saveLoadButton5.setTexture(saveLoadButton5Texture);
    saveLoadButton5.setPosition(800, 600);
    saveLoadButton5.setScale(5, 5);
    saveLoadButton1.setColor(sf::Color(255, 255, 255, 255));

    optionsButton.setTexture(optionsTexture);
    optionsButton.setPosition(357.5, 400);
    optionsButton.setScale(7.5, 7.5);

    optionWindow.setTexture(saveLoadMenuTexture);
    optionWindow.setPosition(300, 350);
    optionWindow.setScale(10, 6);

    fontButton.setTexture(fontTexture);
    fontButton.setPosition(365, 525);
    fontButton.setScale(5.5, 5.5);

    ColorButton.setTexture(Color);
    ColorButton.setPosition(535, 525);
    ColorButton.setScale(5.5, 5.5);

    fontCheckButton.setTexture(bigButton);
    fontCheckButton.setPosition(365, 625);
    fontCheckButton.setScale(7.2, 5.5);

    BPDotsButton.setTexture(BPDots);
    BPDotsButton.setPosition(275, 590);
    BPDotsButton.setScale(5, 5);

    CoolveticaButton.setTexture(Coolvetica);
    CoolveticaButton.setPosition(275, 660);
    CoolveticaButton.setScale(5, 5);

    AllerButton.setTexture(Aller);
    AllerButton.setPosition(275, 730);
    AllerButton.setScale(5, 5);

    DropDownButton.setTexture(DropDown);
    DropDownButton.setPosition(255, 560);
    DropDownButton.setScale(8.5, 8.5);

    //chooseDefaultFont();
    ChosenColor = sf::Color::Green;
    fontChecker.setFont(ChosenFont);
    fontChecker.setFillColor(ChosenColor);
    fontChecker.setString(L"Przykładowe zdanie");
    fontChecker.setCharacterSize(27);
    fontChecker.setPosition(380, 645);

    WordSizeButton.setTexture(WordSize);
    WordSizeButton.setPosition(365, 670);
    WordSizeButton.setScale(5.5, 5.5);

    SmallButton.setTexture(smallButton);
    SmallButton.setPosition(620, 520);
    SmallButton.setScale(2.75, 5.5);

    DropDownColorButton.setTexture(DropDown);
    DropDownColorButton.setPosition(535, 560);
    DropDownColorButton.setScale(8.5, 8.5);


    GreenButton.setTexture(Green);
    GreenButton.setPosition(560, 590);
    GreenButton.setScale(5, 5);

    AquaButton.setTexture(Aqua);
    AquaButton.setPosition(560, 660);
    AquaButton.setScale(5, 5);

    PurpleButton.setTexture(Purple);
    PurpleButton.setPosition(560, 730);
    PurpleButton.setScale(5, 5);

    soundManager.playMusic();
}

void mainMenu::handleInput(sf::RenderWindow &window, sf::Event event, Game& game) {
    if(startButtonActive){
        soundButtonAtStartActive = true;
        exitButtonActive = true;
        fontButtonActive = true;
        colorButtonActive = true;
    }
    if(event.type == sf::Event::MouseButtonPressed) {
        if (startButtonActive and !gameStarted and startButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(
                window)))) { //https://stackoverflow.com/questions/28256921/mouse-input-isnt-correct-to-world-coordinates
            startWasClicked = true;
            startButtonActive = false;
            newButtonActive = true;
            loadButtonActive = true;
            saveButtonClicked = false;
            soundButtonAtStartActive = false;
            gameSaved = false;
            fontDropDownActive = false;
            BPDotsActive = false;
            CoolveticaActive = false;
            AllerActive = false;

            soundManager.playMenuSound();
            return;
        }
        if (startButtonActive and soundButtonAtStartActive and
            soundButtonAtStart.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            if (soundOn) {
                soundButtonAtStart.setTexture(soundOffTexture);
                soundButton.setTexture(soundOffTexture);
                soundOn = false;
                soundManager.stopMusic();
                soundManager.playMenuSound();
            } else {
                soundButtonAtStart.setTexture(soundOnTexture);
                soundButton.setTexture(soundOnTexture);
                soundOn = true;
                soundManager.stopMusic();
                soundManager.playMenuSound();
            }
            return;
        }
        if (!startWasClicked and fontButtonActive and
            fontButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            fontDropDownActive = true;
            BPDotsActive = true;
            CoolveticaActive = true;
            AllerActive = true;
            soundManager.playMenuSound();
            return;

        }
        if (BPDotsActive and
            BPDotsButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            if (!ChosenFont.loadFromFile(MainPath + "assets\\Fonts\\BPdots.otf")) {
                fmt::println("Nie udało się załadować czcionki MinimalPixel");
            }
            fontChecker.setFont(ChosenFont);
            BPDotsActive = false;
            CoolveticaActive = false;
            AllerActive = false;

            fontDropDownActive = false;
            //fontChecker.setScale(1,1);
            fontChecker.setCharacterSize(27);
            fontChecker.setLetterSpacing(1);
            fontChecker.setPosition(380, 645);
            soundManager.playMenuSound();
            return;
        }
        if (CoolveticaActive and
            CoolveticaButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            if (!ChosenFont.loadFromFile(MainPath + "assets\\Fonts\\Coolvetica.otf")) {
                fmt::println("Nie udało się załadować czcionki Coolvetica");
            }
            fontChecker.setFont(ChosenFont);
            BPDotsActive = false;
            CoolveticaActive = false;
            AllerActive = false;
            fontDropDownActive = false;
            fontChecker.setCharacterSize(42);
            fontChecker.setLetterSpacing(3.3);
            fontChecker.setPosition(380, 635);
            soundManager.playMenuSound();
            return;
        }
        if (AllerActive and
            AllerButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            if (!ChosenFont.loadFromFile(MainPath + "assets\\Fonts\\Aller.ttf")) {
                fmt::println("Nie udało się załadować czcionki Aller");
            }
            fontChecker.setFont(ChosenFont);
            BPDotsActive = false;
            CoolveticaActive = false;
            AllerActive = false;
            fontDropDownActive = false;
            fontChecker.setCharacterSize(30);
            fontChecker.setLetterSpacing(2);
            fontChecker.setPosition(380, 640);
            soundManager.playMenuSound();
            return;
        }
        if (!startWasClicked and colorButtonActive and
            ColorButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            DropDownColorActive = true;
            GreenButtonActive = true;
            AquaButtonActive = true;
            PurpleButtonActive = true;
            soundManager.playMenuSound();
            return;
        }
        if (!startWasClicked and GreenButtonActive and
            GreenButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            fontChecker.setFillColor(sf::Color::Green);
            ChosenColor = sf::Color::Green;
            GreenButtonActive = false;
            AquaButtonActive = false;
            PurpleButtonActive = false;
            DropDownColorActive = false;
            soundManager.playMenuSound();
            return;
        }
        if (!startWasClicked and AquaButtonActive and
            AquaButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            fontChecker.setFillColor(sf::Color::Cyan);
            ChosenColor = sf::Color::Cyan;
            GreenButtonActive = false;
            AquaButtonActive = false;
            PurpleButtonActive = false;
            DropDownColorActive = false;
            soundManager.playMenuSound();
            return;
        }
        if (!startWasClicked and PurpleButtonActive and
            PurpleButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            fontChecker.setFillColor(sf::Color::Magenta);
            ChosenColor = sf::Color::Magenta;
            GreenButtonActive = false;
            AquaButtonActive = false;
            PurpleButtonActive = false;
            DropDownColorActive = false;
            soundManager.playMenuSound();
            return;
        }
        if ((!gameStarted or gameIsLose) and exitButtonActive and
            exitButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            window.close();
            soundManager.playMenuSound();
        }
        if (newButtonActive and loadButtonActive and
            newButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            newButtonClicked = true;
            newButtonActive = false;
            colorButtonActive = false;
            fontButtonActive = false;
            soundManager.playMenuSound();
            return;
        }
        if (loadButtonActive and newButtonActive and
            loadButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            loadButtonClicked = true;
            loadButtonActive = false;
            soundManager.playMenuSound();
            updateSlotColors(game, 0, 255, 0, LOAD);
            return;
        }
        if (newButtonClicked and !gameStarted and !gameStopped) {
            if (!newButtonActive and startWasClicked) {
                easyButtonActive = true;
                normalButtonActive = true;
                hardButtonActive = true;
                playButtonActive = true;
            }
            if (easyButtonActive and
                easyButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                game.setGameMode(GameMode::EASY);
                // easyButtonActive = false;
                playButtonActive = true;
                soundManager.playMenuSound();
                modeChosen = true;
                return;
            }
            if (normalButtonActive and
                normalButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                game.setGameMode(GameMode::NORMAL);
                // normalButtonActive = false;
                playButtonActive = true;
                soundManager.playMenuSound();
                modeChosen = true;
                return;
            }
            if (hardButtonActive and
                hardButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                game.setGameMode(GameMode::HARD);
                //hardButtonActive = false;
                playButtonActive = true;
                soundManager.playMenuSound();
                modeChosen = true;
                return;
            }
            if (modeChosen and playButtonActive and
                playButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                playButtonActive = false;;
                exitButtonActive = false;
                normalButtonActive = false;
                easyButtonActive = false;
                hardButtonActive = false;
                modeChosen = false;
                newButtonClicked = false;
                startWasClicked = false;
                colorButtonActive = false;
                fontButtonActive = false;

                game.reset();
                gameStarted = true;
                gameIsLose = false;
                soundManager.playMenuSound();
                startButtonActive = true;
                return;
            }
        }
        if (newButtonActive and loadButtonActive and
            loadButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            loadButtonClicked = true;
            loadButtonActive = false;
            soundManager.playMenuSound();
            return;
        }
        if (loadButtonClicked and !gameStarted and !gameStopped) {
            if (!loadButtonActive and startWasClicked) {
                {
                    slot1ButtonActive = true;
                    slot2ButtonActive = true;
                    slot3ButtonActive = true;
                    slot4ButtonActive = true;
                    slot5ButtonActive = true;

                }
                loadButtonActive = false;
                if (slot1ButtonActive and saveLoadButton1.getGlobalBounds().contains(
                        window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot1.txt") !=
                        game.savedGames.end()) {
                        game.loadGame("slot1.txt");
                        slot1ButtonActive = false;
                        fmt::println("Slot1 loaded");
                        gameStarted = true;
                        gameIsLose = false;
                        soundManager.playMenuSound();
                        return;
                    } else {
                        fmt::println("Slot1 not found");

                    }
                }
                if (slot2ButtonActive and saveLoadButton2.getGlobalBounds().contains(
                        window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot2.txt") !=
                        game.savedGames.end()) {
                        game.loadGame("slot2.txt");
                        slot2ButtonActive = false;
                        fmt::println("Slot2 loaded");
                        gameStarted = true;
                        gameIsLose = false;
                        game.reset();
                        startButtonActive = true;
                        soundManager.playMenuSound();
                        return;
                    } else {
                        fmt::println("Slot2 not found");

                    }
                }
                if (slot3ButtonActive and saveLoadButton3.getGlobalBounds().contains(
                        window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot3.txt") !=
                        game.savedGames.end()) {
                        game.loadGame("slot3.txt");
                        slot3ButtonActive = false;
                        fmt::println("Slot3 loaded");
                        gameStarted = true;
                        gameIsLose = false;
                        soundManager.playMenuSound();
                        return;
                    } else {
                        fmt::println("Slot3 not found");
                    }
                }
                if (slot4ButtonActive and saveLoadButton4.getGlobalBounds().contains(
                        window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot4.txt") !=
                        game.savedGames.end()) {
                        game.loadGame("slot4.txt");
                        slot4ButtonActive = false;
                        fmt::println("Slot4 loaded");
                        gameStarted = true;
                        gameIsLose = false;
                        soundManager.playMenuSound();
                        return;
                    } else {
                        fmt::println("Slot4 not found");
                    }
                }
                if (slot5ButtonActive and saveLoadButton5.getGlobalBounds().contains(
                        window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    if (std::find(game.savedGames.begin(), game.savedGames.end(), "slot5.txt") !=
                        game.savedGames.end()) {
                        game.loadGame("slot5.txt");
                        slot5ButtonActive = false;
                        fmt::println("Slot5 loaded");
                        gameStarted = true;
                        gameIsLose = false;
                        soundManager.playMenuSound();
                        return;
                    } else {
                        fmt::println("Slot5 not found");
                    }
                }
                {
                    slot1ButtonActive = false;
                    slot2ButtonActive = false;
                    slot3ButtonActive = false;
                    slot4ButtonActive = false;
                    slot5ButtonActive = false;
                }
            }
        }

        if (gameStarted and sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            gameStopped = true;
        }
        if (gameStopped) {
            if (!saveButtonClicked) {
                resumeButtonActive = true;
                exitButtonInGameActive = true;
                saveButtonActive = true;
                soundButtonActive = true;
                homeButtonActive = true;
            }
            if (resumeButtonActive and
                resumeButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                gameStopped = false;
                resumeButtonActive = false;
                soundManager.playMenuSound();
                return;
            }
            if (soundButtonActive and
                soundButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                if (soundOn) {
                    soundButton.setTexture(soundOffTexture);
                    soundButtonAtStart.setTexture(soundOffTexture);
                    soundOn = false;
                    soundManager.stopMusic();
                    soundManager.playMenuSound();
                } else {
                    soundButton.setTexture(soundOnTexture);
                    soundButtonAtStart.setTexture(soundOnTexture);
                    soundOn = true;
                    soundManager.stopMusic();
                    soundManager.playMenuSound();
                }
                soundButtonActive = false;
            }
            if (homeButtonActive and
                homeButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                gameIsLose = true;
                homeButtonActive = false;
                resumeButtonActive = false;
                exitButtonInGameActive = false;
                saveButtonActive = false;
                soundButtonActive = false;
                startButtonActive = true;
                soundButtonAtStartActive = true;
                exitButtonActive = true;
                newButtonActive = true;
                exitButtonActive = true;
                loadButtonActive = true;
                startWasClicked = false;
                loadButtonClicked = false;
                gameSaved = false;
                gameStarted = false;
                soundManager.playMenuSound();
                gameStopped = false;
                game.reset();
                return;
            }
            if (saveButtonActive and
                saveButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                saveButtonClicked = true;
                saveButtonActive = false;
                {
                    homeButtonActive = false;
                    resumeButtonActive = false;
                    saveButtonActive = false;
                    exitButtonInGameActive = false;
                    soundButtonActive = false;
                }
                soundManager.playMenuSound();
                updateSlotColors(game, 255, 0, 0, SAVE);

                return;
            }
            if (saveButtonClicked and gameStopped) {
                {
                    slot1ButtonActive = true;
                    slot2ButtonActive = true;
                    slot3ButtonActive = true;
                    slot4ButtonActive = true;
                    slot5ButtonActive = true;
                    startWasClicked = false;
                }
                if (slot1ButtonActive and saveLoadButton1.getGlobalBounds().contains(
                        window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    game.saveGame(MainPath + "Saves\\slot1.txt");
                    slot1ButtonActive = false;
                    fmt::println("Slot1 saved");
                    gameStopped = false;
                    gameStarted = false;
                    gameIsLose = true;
                    startWasClicked = false;
                    startButtonActive = true;
                    soundButtonAtStartActive = true;
                    exitButtonActive = true;
                    loadButtonClicked = false;
                    gameSaved = true;
                    saveButtonClicked = false;
                    loadButtonClicked = false;
                    soundManager.playMenuSound();
                    game.addSavedGame("slot1.txt");
                    game.reset();
                    return;
                }
                if (slot2ButtonActive and saveLoadButton2.getGlobalBounds().contains(
                        window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    game.saveGame(MainPath + "Saves\\slot2.txt");
                    slot2ButtonActive = false;
                    fmt::println("Slot2 saved");
                    gameStopped = false;
                    gameStarted = false;
                    gameIsLose = true;
                    startWasClicked = false;
                    startButtonActive = true;
                    soundButtonAtStartActive = true;
                    exitButtonActive = true;
                    loadButtonActive = false;
                    gameSaved = true;
                    saveButtonClicked = false;
                    loadButtonClicked = false;
                    soundManager.playMenuSound();
                    game.addSavedGame("slot2.txt");
                    game.reset();
                    return;
                }
                if (slot3ButtonActive and saveLoadButton3.getGlobalBounds().contains(
                        window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    game.saveGame(MainPath + "Saves\\slot3.txt");
                    slot3ButtonActive = false;
                    fmt::println("Slot3 saved");
                    gameStopped = false;
                    gameStarted = false;
                    gameIsLose = true;
                    startWasClicked = false;
                    startButtonActive = true;
                    soundButtonAtStartActive = true;
                    exitButtonActive = true;
                    loadButtonActive = false;
                    gameSaved = true;
                    saveButtonClicked = false;
                    loadButtonClicked = false;
                    soundManager.playMenuSound();
                    game.addSavedGame("slot3.txt");
                    game.reset();
                    return;
                }
                if (slot4ButtonActive and saveLoadButton4.getGlobalBounds().contains(
                        window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    game.saveGame(MainPath + "Saves\\slot4.txt");
                    slot4ButtonActive = false;
                    fmt::println("Slot4 saved");
                    gameStopped = false;
                    gameStarted = false;
                    gameIsLose = true;
                    startWasClicked = false;
                    startButtonActive = true;
                    soundButtonAtStartActive = true;
                    exitButtonActive = true;
                    loadButtonActive = false;
                    gameSaved = true;
                    saveButtonClicked = false;
                    loadButtonClicked = false;
                    soundManager.playMenuSound();
                    game.addSavedGame("slot4.txt");
                    game.reset();
                    return;
                }
                if (slot5ButtonActive and saveLoadButton5.getGlobalBounds().contains(
                        window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    game.saveGame(MainPath + "Saves\\slot5.txt");
                    slot5ButtonActive = false;
                    fmt::println("Slot5 saved");;
                    gameStopped = false;
                    gameStarted = false;
                    gameIsLose = true;
                    loadButtonClicked = false;
                    startButtonActive = true;
                    soundButtonAtStartActive = true;
                    exitButtonActive = true;
                    startWasClicked = false;
                    gameSaved = true;
                    saveButtonClicked = false;
                    loadButtonClicked = false;
                    soundManager.playMenuSound();
                    game.addSavedGame("slot5.txt");
                    game.reset();
                    return;
                }
            }
        }
        if (exitButtonInGameActive and
            exitButtonInGame.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            soundManager.playMenuSound();
            window.close();

        }
    }
}

void mainMenu::draw(sf::RenderWindow& window){
    if(!gameStarted and !startWasClicked){
        window.draw(startButton);
        window.draw(exitButton);
        window.draw(soundButtonAtStart);
        window.draw(optionWindow);
        window.draw(optionsButton);
        window.draw(fontButton);
        window.draw(ColorButton);
        window.draw(fontCheckButton);
        window.draw(fontChecker);
    }
    if(fontDropDownActive and !startWasClicked){
        window.draw(DropDownButton);
        window.draw(BPDotsButton);
        window.draw(CoolveticaButton);
        window.draw(AllerButton);
    }
    if(DropDownColorActive and !startWasClicked){
        window.draw(DropDownColorButton);
        window.draw(GreenButton);
        window.draw(AquaButton);
        window.draw(PurpleButton);
    }
    if(startWasClicked and !newButtonClicked and !gameStarted and !loadButtonClicked and !saveButtonClicked) {
        window.draw(exitButton);
        window.draw(newButton);
        window.draw(loadButton);
    }
    if(loadButtonClicked and !gameStarted and !gameStopped and startWasClicked and !saveButtonClicked and !gameSaved){
        window.draw(exitButton);
        window.draw(saveLoadMenu);
        window.draw(saveLoadButton1);
        window.draw(saveLoadButton2);
        window.draw(saveLoadButton3);
        window.draw(saveLoadButton4);
        window.draw(saveLoadButton5);
    }
    if(newButtonClicked and startWasClicked and !gameStarted and !gameStopped and !loadButtonClicked) {
        exitButtonActive = true;
        window.draw(exitButton);
        window.draw(easyButton);
        window.draw(normalButton);
        window.draw(hardButton);
        window.draw(playButton);
    }
    if(gameStopped and !saveButtonClicked){
        window.draw(menuInGame);
        window.draw(resumeButton);
        window.draw(exitButtonInGame);
        window.draw(saveButton);
        window.draw(soundButton);
        window.draw(homeButton);
    }
    if(gameStopped and saveButtonClicked){
        window.draw(saveLoadMenu);
        window.draw(saveLoadButton1);
        window.draw(saveLoadButton2);
        window.draw(saveLoadButton3);
        window.draw(saveLoadButton4);
        window.draw(saveLoadButton5);
    }
}


