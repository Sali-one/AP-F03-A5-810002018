#ifndef SHEEP_H
#define SHEEP_H

#include <SFML/Graphics.hpp>

class Sheep {
public:
    Sheep(int type);

    sf::Vector2f getPosition() const;

    void setPosition(sf::Vector2f position);

    void move(sf::Vector2f offset);

    float getSpeed() const;

    int getPower() const;

    int getDamage() const;

    void takeDamage(int amount);

    bool isDead() const;

    void render(sf::RenderWindow& window, sf::Vector2f position);

    sf::Texture texture;     
    sf::Sprite sprite;    
    
private:
    int type;            
    int power;               
    int damage;            
    int health;            
    float speed;          
    
};
   

#endif