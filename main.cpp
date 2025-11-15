#include <iostream>
#include <SFML/Graphics.hpp>
#include <fmt/core.h>
#include "Background.h"
#include "Game.h"
#include "MainMenu.h"
#include <vector>
#include <fstream>
#include "SoundManager.h"

auto MainPath = std::string("D:\\Studia\\MonkeyTyper\\");

void wordsAssign(std::vector<std::string>& vec){
    auto currentpath = std::string(MainPath+"assets\\Words.txt");
    std::fstream file(currentpath);
    if(file.is_open()){
        std::string line;
        while(std::getline(file,line)){
            vec.push_back(line);
        }
        file.close();
    }else{
        fmt::println("Nie udalo sie otworzyc pliku tekstowego");
    }
}

bool gameStarted = false;
bool gameStopped = false;
bool gameIsLose = false;

auto main() -> int {
    auto window = sf::RenderWindow(
            sf::VideoMode({1920,1080}), "MonkeyTyper",
            sf::Style::Default,sf::ContextSettings(0,0,8)
            );
    //background
    auto  backgroundsPath = std::string(MainPath + "assets\\bg");
    auto backgroundsNames = std::vector<std::string>{
        backgroundsPath+"1.png",backgroundsPath+"2.png", backgroundsPath+"3.png",backgroundsPath+"4.png"
    };

    auto background = Background();
    background.loadTextures(backgroundsNames);

    auto wordsPL = std::vector<std::string>();
    auto wordsANG = std::vector<std::string>();

    wordsAssign(wordsANG);

    auto game = Game(wordsANG);
    auto menu = mainMenu();
    auto soundManager = SoundManager();

    while(window.isOpen()){
        auto event = sf::Event();
        while(window.pollEvent(event)) {
            menu.handleInput(window,event, game);
        }

        window.clear();

        background.draw(window);
        background.update();

        menu.draw(window);

        if(!gameStarted) {
            menu.draw(window);
        }else if(!gameIsLose){
            game.update();
            game.handleWordInput(event);
            game.draw(window);
        }else if(gameIsLose){
            menu.draw(window);
            gameStarted = false;
            game.update();
        }

        menu.draw(window);

        window.display();
    }
}

