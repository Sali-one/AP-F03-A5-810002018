#ifndef LINE_H
#define LINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Sheep.h"

class Line {
public:
    Line(int index);

    void update(sf::Time deltaTime);

    void renderL(sf:: RenderWindow& windowa);

    
    void handleCollisions();

    float yPosition;
    
    std::vector<std::pair<Sheep, int>> sheep; 

private:
    int index; 
    


    void moveSheep(sf::Time deltaTime);
};

#endif