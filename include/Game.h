#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Line.h"
using namespace sf;
class Game {
public:
    Game();
    void run();
    sf::RenderWindow windowa;
    
    std::vector<Line> lines;
    
    
private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render(Sprite& backgroundSprite, Sprite& arrowSprite);


    sf::Font font;

    Player player1;
    Player player2;


    bool isGameOver;
};

#endif