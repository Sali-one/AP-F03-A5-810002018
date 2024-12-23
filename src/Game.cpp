#include "Game.h"
#include <iostream>
using namespace std;
const string Path = "resources/";


vector<Line> lines;
Game::Game()
    :windowa(sf::VideoMode(1080,800), "Sheep Fight"),
      player1(1), player2(2), isGameOver(false) {

    if (!font.loadFromFile(Path+"arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    
}

void Game::run() {
    sf::Clock clock;

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile(Path +"background.jpg")) {
        std::cerr << "Error loading background image!" << std::endl;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    sf::Texture arrowTexture;
    if (!arrowTexture.loadFromFile(Path+"arrow.png")) {
        std::cerr << "Error loading arrow image!" << std::endl;
    }
    sf::Sprite arrowSprite(arrowTexture);

    for(int i=0 ; i<5 ; i++){
        Line line1(i);
        line1.renderL(windowa);
        lines.push_back(line1);
    }

    
    while (windowa.isOpen()) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        if (!isGameOver) {
            update(deltaTime);
        }
        render(backgroundSprite, arrowSprite);
    }
}


void Game::processEvents() {
    sf::Event event;
    while (windowa.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            windowa.close();
        }

        player1.handleInput(windowa, event,  1);
        player2.handleInput(windowa, event,  2);
    }
}

void Game::update(sf::Time deltaTime) {
    for (auto& line : lines) {
        line.update(deltaTime);
    }

    if (player1.getHealth() <= 0 || player2.getHealth() <= 0) {
        isGameOver = true;
    }
}

void Game::render(sf::Sprite& backgroundSprite, sf::Sprite& arrowSprite) {
    windowa.clear();
    
    windowa.draw(backgroundSprite);
    
    
    
    for ( auto& line : lines) {
        line.renderL(windowa);
    }

    player1.render(windowa, font, true, arrowSprite);
    player2.render(windowa, font, false, arrowSprite);

    windowa.display();
}

