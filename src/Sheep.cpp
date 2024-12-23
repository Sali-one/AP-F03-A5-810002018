#include "Sheep.h"
#include <iostream>
using namespace std;
const string Path = "resources/";
Sheep::Sheep(int type) : type(type) {

    if (type == 0) { 
        power = 10; 
        damage = 5; 
        health = 50;
        speed = 100; 
        if (!texture.loadFromFile(Path+"small_sheep.png")) {
            std::cerr << "Error loading small_sheep.png" << std::endl;
        }
    } else if (type == 1) {
        power = 20;
        damage = 10; 
        health = 75;
        speed = 75;  
        if (!texture.loadFromFile(Path+"medium_sheep.png")) {
            std::cerr << "Error loading medium_sheep.png" << std::endl;
        }
    } else if (type == 2) {
        power = 30; 
        damage = 20; 
        health = 100; 
        speed = 50;  
        if (!texture.loadFromFile(Path+"heavy_sheep.png")) {
            std::cerr << "Error loading heavy_sheep.png" << std::endl;
        }
    }

    sprite.setTexture(texture);
}

sf::Vector2f Sheep::getPosition() const {
    return sprite.getPosition();
}

void Sheep::setPosition(sf::Vector2f position) {
    sprite.setPosition(position);
}

void Sheep::move(sf::Vector2f offset) {
    sprite.move(offset);
}

float Sheep::getSpeed() const {
    return speed;
}

int Sheep::getPower() const {
    return power;
}

int Sheep::getDamage() const {
    return damage;
}

void Sheep::takeDamage(int amount) {
    health -= amount;
}

bool Sheep::isDead() const {
    return health <= 0;
}

void Sheep::render(sf::RenderWindow& window, sf::Vector2f position) {
    sprite.setPosition(position);
    window.draw(sprite);
}

