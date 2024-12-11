#include "Line.h"
#include <iostream>

Line::Line(int index) : index(index) {
    yPosition = 200 + index * 80; 
}

void Line::update(sf::Time deltaTime) {
    moveSheep(deltaTime);

}



void Line::renderL(sf:: RenderWindow& windowa) {
        sf::RectangleShape lineShape(sf::Vector2f(1000, 60)); 
        lineShape.setFillColor(sf::Color::White);
        lineShape.setPosition(0, yPosition );
        windowa.draw(lineShape);

        for ( auto& sheepPair : sheep) {
            Sheep& currentSheep = sheepPair.first;
            sf::Vector2f position = currentSheep.getPosition();
            currentSheep.render(windowa, position);
        
    }
}

void Line::addSheep(Sheep newSheep, int playerId) {
    if (playerId == 1) {
        newSheep.setPosition(sf::Vector2f(50, yPosition - 10)); 
    } else if (playerId == 2) {
        newSheep.setPosition(sf::Vector2f(750, yPosition - 10)); 
    }

    sheep.emplace_back(newSheep, playerId);
}



void Line::moveSheep(sf::Time deltaTime) {
    for (auto& sheepPair : sheep) {
        Sheep& currentSheep = sheepPair.first;
        int playerId = sheepPair.second;

        if (playerId == 1) {
            currentSheep.move(sf::Vector2f(currentSheep.getSpeed() * deltaTime.asSeconds(), 0));
        } else if (playerId == 2) {
            currentSheep.move(sf::Vector2f(-currentSheep.getSpeed() * deltaTime.asSeconds(), 0));
        }
    }
}