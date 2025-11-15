#ifndef PROJEKTPJC_BACKGROUND_H
#define PROJEKTPJC_BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Background{
public:
    void loadTextures(const std:: vector<std::string>& Paths);
    void update();
    void draw(sf::RenderWindow& window);
private:
    sf::Texture textureBg;
    sf::Texture textureMoon;
    sf::Texture textureClouds1;
    sf::Texture textureClouds2;
    sf::Sprite bgSprite;
    sf::Sprite bgMoon;
    sf::Sprite bgClouds1;
    sf::Sprite bgClouds2;
    float speed1=0.01f;
    float speed2=0.015f;
};


#endif //PROJEKTPJC_BACKGROUND_H
