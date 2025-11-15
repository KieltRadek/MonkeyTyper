
#ifndef PROJEKTPJC_GAME_H
#define PROJEKTPJC_GAME_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include "GameMode.h"
#include "SoundManager.h"
#include <fstream>
#include <string>

class Game {
public:
    Game(std::vector<std::string>&);
    void update();
    void draw(sf::RenderWindow& window);
    void handleWordInput(sf::Event event);
    void setGameMode(GameMode);
    void reset();
    void saveGame(const std::string& filename);
    bool loadGame(const std::string& filename);
    void addSavedGame(const std::string& filename){savedGames.push_back(filename);};
    std::vector<std::string> savedGames;
    void saveSlots(const std::vector<std::string>&, const std::string&);
    std::vector<std::string> loadSlots(const std::string&);
    ~Game();
    void updateDisplay();
private:
    static std::string randomWord(std::vector<std::string>& vec, int size){
        auto random = std::string(vec[rand() % vec.size()]); //https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
        if(random.size() <= size){
            return random;
        }

        return randomWord(vec, size);
    }
    std::string path = "D:\\Studia\\MonkeyTyper";
    float wordSpeed = 0.05f;
    std::vector<sf::Text> wordsOnScreen;
    std::vector<std::string> wordList;
    float spawnTime = 1.0f;
    int characterSize=27;
    sf::Clock clock;
    int lostWords = 0;
    sf::Text lostWordsDisplay;
    std::string inputWord;
    sf::Text inputWordDisplay;
    sf::Color OtherColor = sf::Color::White;
    sf::Text timeDisplay;

    float multiplier = 1;
    float points = 0;
    sf::Text pointsDisplay;

    float spawnTimeMultipler;/* = 0.02f;*/
    sf::String inputWordString;

    SoundManager soundManager;

    sf::Clock gameClock;
    float elapsedTime;
    float pauseTime;
};


#endif //PROJEKTPJC_GAME_H
