#include "Game.h"
#include <fmt/core.h>
#include <iostream>
#include <cstdlib>
#include "SoundManager.h"
#include <SFML/Graphics.hpp>
#include <fstream>

extern std::string MainPath;
extern sf::Font ChosenFont;
extern sf::Font menuFont;
extern sf::Color ChosenColor;
extern int ChosenSize;

extern bool gameStopped;
extern bool gameIsLose;
extern bool gameStarted;

void Game::setGameMode(GameMode mode) {
    switch(mode){
        case GameMode::EASY:
            wordSpeed = 0.05f;
            spawnTime = 3.11f;
            multiplier = wordSpeed*(10-spawnTime);
            spawnTimeMultipler = 0.01f;
            break;
        case GameMode::NORMAL:
            wordSpeed = 0.09f;
            spawnTime = 2.27f;
            multiplier = wordSpeed*(10-spawnTime);
            spawnTimeMultipler = 0.015f;
            break;
        case GameMode::HARD:
            wordSpeed = 0.13f;
            spawnTime = 1.13f;
            multiplier = wordSpeed*(10-spawnTime);
            spawnTimeMultipler = 0.02f;
            break;
    }
}

void Game::reset(){
    lostWords = 0;
    points=0;
    wordsOnScreen.clear();
    gameClock.restart();
    elapsedTime = 0;
    pauseTime = 0;
    inputWord = "";
    lostWordsDisplay.setString("Lost words:" + std::to_string(lostWords));
    pointsDisplay.setString("Points:" + std::to_string(points));
    inputWordDisplay.setString("Word: " + inputWord);
    timeDisplay.setString("Time:" + std::to_string(elapsedTime));
    gameIsLose= true;
    gameStarted = false;
    gameStopped = false;
}

Game::Game(std::vector<std::string>& words) : wordList(words){
    savedGames = loadSlots("SavedGames.txt");

    lostWordsDisplay.setString("Lost words:" + std::to_string(lostWords));
    lostWordsDisplay.setFont(menuFont);
    lostWordsDisplay.setCharacterSize(45);
    lostWordsDisplay.setPosition(sf::Vector2f(900,1000));
    lostWordsDisplay.setFillColor(sf::Color::White);
    lostWords=0;

    inputWordDisplay.setString("Word:" + inputWord);
    inputWordDisplay.setFont(menuFont);
    inputWordDisplay.setCharacterSize(45);
    inputWordDisplay.setPosition(sf::Vector2f(1300,1000));
    lostWordsDisplay.setFillColor(sf::Color::White);

    pointsDisplay.setString("Points:" + std::to_string(points));
    pointsDisplay.setFont(menuFont);
    pointsDisplay.setCharacterSize(45);
    pointsDisplay.setPosition(sf::Vector2f(400,1000));
    pointsDisplay.setFillColor(sf::Color::White);

    gameClock.restart();
    elapsedTime = 0;
}

void Game::saveGame(const std::string &filename) {
    std::ofstream saveFile(filename);
    if (saveFile.is_open()) {
        saveFile << lostWords << std::endl;
        saveFile << points << std::endl;
        saveFile << wordSpeed << std::endl;
        saveFile << spawnTime << std::endl;
        saveFile << multiplier << std::endl;
        saveFile << ChosenSize << std::endl;
        saveFile << elapsedTime << std::endl;
        saveFile << spawnTimeMultipler << std::endl;
        saveFile << wordsOnScreen.size() << std::endl;
        for (auto &word: wordsOnScreen) {
            saveFile << word.getString().getSize() << std::endl;
            saveFile << word.getString().toAnsiString() << std::endl;
            saveFile << word.getPosition().x << std::endl;
            saveFile << word.getPosition().y << std::endl;
        }
        saveFile.close();
    } else {
        fmt::println("Nie udalo sie otworzyc pliku zapisu {}", filename);
    }
}

bool Game::loadGame(const std::string &filename) {
    std::ifstream loadFile( MainPath + "Saves\\" + filename);
    if (loadFile.is_open()) {
        loadFile >> lostWords;
        loadFile >> points;
        loadFile >> wordSpeed;
        loadFile >> spawnTime;
        loadFile >> multiplier;
        loadFile >> ChosenSize;
        loadFile >> elapsedTime;
        loadFile >> spawnTimeMultipler;
        auto wordsOnScreenSize = 0;
        loadFile >> wordsOnScreenSize;
        wordsOnScreen.clear();
        for (auto i = 0; i < wordsOnScreenSize; ++i) {
            auto wordLength = 0;
            loadFile >> wordLength;
            auto word = std::string(wordLength, ' ');
            loadFile >> word;
            sf::Text newText;
            newText.setString(word);
            newText.setFont(ChosenFont);
            newText.setCharacterSize(characterSize);
            sf::Vector2f position;
            loadFile >> position.x;
            loadFile >> position.y;
            newText.setPosition(position);
            wordsOnScreen.push_back(newText);
        }
        loadFile.close();
        gameClock.restart();
        updateDisplay();
        return true;
    } else {
        fmt::println("Nie udalo sie otworzyc pliku odczytu {}", filename);
        return false;
    }
}

void Game::saveSlots(const std::vector<std::string>& slots, const std::string& filename) {
    std::string path = MainPath + "Saves\\" + filename;
    std::vector<std::string> lines;
    std::string line;
    std::ifstream readFile(path);

    // Odczytanie całego pliku do pamięci
    while (std::getline(readFile, line)) {
        lines.push_back(line);
    }
    readFile.close();

    // Zaktualizowanie odpowiednich linii
    for (const auto& slot : slots) {
        bool found = false;
        for (auto& fileLine : lines) {
            if (fileLine == slot) {
                fileLine = slot;  // Nadpisuje linię
                found = true;
                break;
            }
        }
        // Jeśli slot nie został znaleziony, dodajemy go na końcu
        if (!found) {
            lines.push_back(slot);
        }
    }

    // Zapisanie zaktualizowanych danych z powrotem do pliku
    std::ofstream writeFile(path);
    for (const auto& fileLine : lines) {
        writeFile << fileLine << std::endl;
    }
    writeFile.close();
}

std::vector<std::string> Game::loadSlots(const std::string& filename) {
    std::vector<std::string> slots;
    std::ifstream loadFile(MainPath + "Saves\\" + filename);
    if (loadFile.is_open()) {
        std::string line;
        while (std::getline(loadFile, line)) {
            slots.push_back(line);
        }
        loadFile.close();
    } else {
        fmt::println("Nie udalo sie otworzyc pliku odczytu {}", filename);
    }
    return slots;
}

Game::~Game() {
    saveSlots(savedGames, "SavedGames.txt");
}

void Game::updateDisplay(){
    lostWordsDisplay.setString("Lost words:" + std::to_string(lostWords));
    pointsDisplay.setString("Points:" + std::to_string(points));
    inputWordDisplay.setString("Word:" + inputWord);
    timeDisplay.setString("Time:" + std::to_string(elapsedTime));
}

void Game::update(){
    if(!gameStopped) {
        elapsedTime += gameClock.getElapsedTime().asSeconds();
        gameClock.restart();
        pauseTime = 0;

        if (clock.getElapsedTime().asSeconds() > spawnTime) {
            if(spawnTime>=0.3f) {
                spawnTime -= spawnTimeMultipler;
            }
            auto newWord = std::string(randomWord(wordList, ChosenSize));
            auto newText = sf::Text();
            newText.setString(newWord);
            newText.setFont(ChosenFont);
            newText.setCharacterSize(characterSize);
            newText.setFillColor(sf::Color::White);
            newText.setPosition(sf::Vector2f(0, 50 + rand() % 850));
            bool isColliding;
            do {
                isColliding = false;
                for (auto &word: wordsOnScreen) {
                    if (newText.getGlobalBounds().intersects(word.getGlobalBounds())) {
                        newText.setPosition(sf::Vector2f(0, 50 + rand() % 850));//rand() https://gamefromscratch.com/sfml-c-tutorial-handling-keyboard-input-and-random-numbers/
                        isColliding = true;
                        break;
                    }
                }
            } while (isColliding);
            wordsOnScreen.push_back(newText);
            clock.restart();
        }

    }else{
        pauseTime += gameClock.getElapsedTime().asSeconds();
        gameClock.restart();
    }
}

void Game::handleWordInput(sf::Event event){
    if(event.type == sf::Event::TextEntered){
        if((event.text.unicode >= 'A' and event.text.unicode <= 'z')){//Zabezpieczenie przed tworzeniem dodatkowych znaków przy wciśnieciu np. shifta(Sprawdzanie czy znak jest znakiem AScii https://stackoverflow.com/questions/25320803/sfml-2-real-time-text-inputno-event-loop
            inputWord += (char)event.text.unicode; // 8 bo to backspace
            inputWordDisplay.setString("Word: " + inputWord);
        }else if(event.text.unicode == 8){
            if(!inputWord.empty()){
                inputWord.pop_back();
                inputWordDisplay.setString("Word: " + inputWord);
            }
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        for(auto it = wordsOnScreen.begin(); it != wordsOnScreen.end();){
            if(it->getString() == inputWord){
                wordsOnScreen.erase(it);
                inputWordDisplay.setString("Word: " + inputWord);
                points += multiplier*100;
                break;
            } else {
                ++it;
            }
        }
        inputWord.clear();
        inputWordDisplay.setString("Word: " + inputWord);
        pointsDisplay.setString("Points: " + std::to_string(points));

    }
    if(lostWords>=10){
        reset();
        soundManager.playLoseSound();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        gameStopped = true;
    }
}

void Game::draw(sf::RenderWindow& window){
    if(!gameStopped) {
        for (auto &word: wordsOnScreen) {
            std::string wordStr = word.getString().toAnsiString();
            if (wordStr.find(inputWord) == 0 and !inputWord.empty()) {
                sf::Text matchingPart;
                matchingPart.setString(wordStr.substr(0, inputWord.length()));
                matchingPart.setFont(ChosenFont);
                matchingPart.setCharacterSize(characterSize);
                matchingPart.setPosition(word.getPosition());
                matchingPart.setFillColor(ChosenColor);

                sf::Text remainingPart;
                remainingPart.setString(wordStr.substr(inputWord.length()));
                remainingPart.setFont(ChosenFont);
                remainingPart.setCharacterSize(characterSize);
                remainingPart.setPosition(word.getPosition().x + matchingPart.getGlobalBounds().width, word.getPosition().y);

                if(word.getPosition().x>1200){
                    remainingPart.setFillColor(sf::Color::Yellow);
                }
                if(word.getPosition().x>1680){
                    remainingPart.setFillColor(sf::Color::Red);
                }
                if(word.getPosition().x<=1200){
                    remainingPart.setFillColor(sf::Color::White);

                }
                word.setFillColor(sf::Color(0,0,0,0));

                window.draw(matchingPart);
                window.draw(remainingPart);
            }else{
                if(word.getPosition().x>1200){
                    word.setFillColor(sf::Color::Yellow);
                }
                if(word.getPosition().x>1680){
                    word.setFillColor(sf::Color::Red);
                }
                if(word.getPosition().x<=1200){
                    word.setFillColor(sf::Color::White);
                }
            }
        }

        for (auto it = wordsOnScreen.begin(); it != wordsOnScreen.end();) {
            it->move(wordSpeed, 0);
            if (it->getPosition().x> 1920) {
                it = wordsOnScreen.erase(it);
                lostWords++;
                lostWordsDisplay.setString("Lost words:" + std::to_string(lostWords));
            } else {
                window.draw(*it);
                ++it;
            }
        }
        timeDisplay.setString("Time:" + std::to_string(elapsedTime));
        timeDisplay.setFont(menuFont);
        timeDisplay.setCharacterSize(45);
        timeDisplay.setPosition(sf::Vector2f(20, 1000));
        timeDisplay.setFillColor(sf::Color::White);

        window.draw(lostWordsDisplay);
        window.draw(inputWordDisplay);
        window.draw(pointsDisplay);
        window.draw(timeDisplay);
    }
    if (gameIsLose ) {
        reset();
    }
}

