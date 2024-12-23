#include "Player.h"
#include <iostream>

Player::Player(int id)
    : id(id), health(100), selectedLine(2) { 
    generateSheepQueue();
}

void Player::handleInput(const sf::Event& event, int playerId) {
    if (event.type == sf::Event::KeyPressed) {
        if (playerId == 1) {
            if (event.key.code == sf::Keyboard::Up) {
                selectedLine = (selectedLine > 0) ? selectedLine - 1 : 0;
            }
            if (event.key.code == sf::Keyboard::Down) {
                selectedLine = (selectedLine < 4) ? selectedLine + 1 : 4;
            }
        } else if (playerId == 2) {
            if (event.key.code == sf::Keyboard::W) {
                selectedLine = (selectedLine > 0) ? selectedLine - 1 : 0;
            }
            if (event.key.code == sf::Keyboard::S) {
                selectedLine = (selectedLine < 4) ? selectedLine + 1 : 4;
            }
        }
    }
}

void Player::render(sf::RenderWindow& window, sf::Font& font, bool isLeft, sf::Sprite& arrowSprite) {
    sf::Text healthText;
    healthText.setFont(font);
    healthText.setCharacterSize(24);
    healthText.setFillColor(sf::Color::Blue);

    healthText.setString("Health: " + std::to_string(health));
    healthText.setPosition(isLeft ? 10 : 650, 10);
    window.draw(healthText);

    arrowSprite.setPosition(isLeft ? 50 : 900, 200 + selectedLine * 80); // Adjust arrow position based on the line
    window.draw(arrowSprite);
}

int Player::getHealth() const {
    return health;
}

void Player::reduceHealth(int damage) {
    health -= damage;
}

Sheep Player::getNextSheep() {
    Sheep nextSheep = sheepQueue.front();
    sheepQueue.pop();
    return nextSheep;
}

void Player::setSelectedLine(int line) {
    selectedLine = line;
}

int Player::getSelectedLine() const {
    return selectedLine;
}

void Player::generateSheepQueue() {
    for (int i = 0; i < 3; ++i) {
        int type = rand() % 3; 
        sheepQueue.push(Sheep(type));
    }
}