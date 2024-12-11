#include "Line.h"
#include <iostream>

Line::Line(int index) : index(index) {
    yPosition = 200 + index * 80; 
}

void Line::update(sf::Time deltaTime, Player& player1, Player& player2) {
    moveSheep(deltaTime);

    handleCollisions(player1, player2);
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

void Line::handleCollisions(Player& player1, Player& player2) {
    if (sheep.size() <= 1) return; 

    for (size_t i = 0; i < sheep.size(); ++i) {
        for (size_t j = i + 1; j < sheep.size(); ++j) {
            Sheep& sheep1 = sheep[i].first;
            Sheep& sheep2 = sheep[j].first;
            int player1Id = sheep[i].second;
            int player2Id = sheep[j].second;

            if (std::abs(sheep1.getPosition().x - sheep2.getPosition().x) < 30) {
                if (sheep1.getPower() > sheep2.getPower()) {
                    sheep2.takeDamage(sheep1.getDamage());
                    if (sheep2.isDead()) {
                        sheep.erase(sheep.begin() + j);
                        --j;
                    }
                } else {
                    sheep1.takeDamage(sheep2.getDamage());
                    if (sheep1.isDead()) {
                        sheep.erase(sheep.begin() + i);
                        --i;
                    }
                }
            }
        }
    }
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