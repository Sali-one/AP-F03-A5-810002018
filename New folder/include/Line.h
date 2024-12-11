#ifndef LINE_H
#define LINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Sheep.h"
#include "Player.h"

class Line {
public:
    Line(int index);

    void update(sf::Time deltaTime, Player& player1, Player& player2);

    void renderL(sf:: RenderWindow& windowa);

    void addSheep(Sheep sheep, int playerId);

    float yPosition;

private:
    int index; 
    
    std::vector<std::pair<Sheep, int>> sheep; 

    void handleCollisions(Player& player1, Player& player2);

    void moveSheep(sf::Time deltaTime);
};

#endif