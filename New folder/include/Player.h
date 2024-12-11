#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Sheep.h"
#include <queue>

class Player {
public:
    Player(int id);

    void handleInput(const sf::Event& event, int playerId);
    void render(sf::RenderWindow& window, sf::Font& font, bool isLeft, sf::Sprite& arrowSprite);

    int getHealth() const;
    void reduceHealth(int damage);

    Sheep getNextSheep();
    void setSelectedLine(int line);
    int getSelectedLine() const;

private:
    int id;
    int health;
    int selectedLine; 
    std::queue<Sheep> sheepQueue;

    void generateSheepQueue();
};

#endif