#include "Background.h"
#include <fmt/core.h>
#include <iostream>

    void Background::loadTextures(const std::vector<std::string> &Paths) {
        if(!textureBg.loadFromFile(Paths[0])){
            fmt::println("Nie udalo sie wczytac sie grafiki tła: {}" , Paths[0]);
            exit(-1);
        }

        if(!textureMoon.loadFromFile(Paths[1])){
            fmt::println("Nie udalo sie wczytac sie grafiki tła: {}" , Paths[1]);
            exit(-1);
        }

        if(!textureClouds1.loadFromFile(Paths[2])){
            fmt::println("Nie udalo sie wczytac sie grafiki tła: {}" , Paths[2]);
            exit(-1);
        }

        if(!textureClouds2.loadFromFile(Paths[3])){
            fmt::println("Nie udalo sie wczytac sie grafiki tła: {}" , Paths[3]);
            exit(-1);
        }

        bgSprite.setTexture(textureBg);
        bgMoon.setTexture( textureMoon);
        bgClouds1.setTexture(textureClouds1);
        bgClouds2.setTexture(textureClouds2);
        bgSprite.setPosition(sf::Vector2f(0,0));

    }

    void Background::update() {
        bgClouds1.move(speed1, 0);

        if (bgClouds1.getPosition().x >= 0) {
            bgClouds1.setPosition(sf::Vector2f(-1920, 0));
        }

        bgClouds2.move(speed2, 0);

        if (bgClouds2.getPosition().x >= 0) {
            bgClouds2.setPosition(sf::Vector2f(-1920, 0));
        }
    }

    void Background::draw(sf::RenderWindow &window) {
        window.draw(bgSprite);
        window.draw(bgMoon);
        window.draw(bgClouds1);
        window.draw(bgClouds2);
    }

