#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Sheep.h"
#include <queue>
#include <vector>
#include "Line.h"
using namespace std;
class Player {
public:
    Player(int id);

    void handleInput(sf::RenderWindow& window, sf::Event& event, int playerId,vector<Line>&lines);
    void render(sf::RenderWindow& window, sf::Font& font, bool isLeft, sf::Sprite& arrowSprite);

    int getHealth() const;
    void reduceHealth(int damage);

    Sheep getNextSheep();
    void setSelectedLine(int line);
    int getSelectedLine() const;


    void addSheep(sf::RenderWindow& window,Sheep sheep, int playerId, int selectedLine);
    
    std::vector<Line> lines;

private:
    int id;
    int health;
    int selectedLine; 
    std::queue<Sheep> sheepQueue;

    void generateSheepQueue();
};

#endif