#ifndef GAME_H
#define GAME_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy_waves.h"
class Game {
public:
    Game();
    void run();

private:
    Enemy_waves waves;
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void startNextWave();

    sf::RenderWindow window;
    sf::Time timePerFrame;
    bool isRunning;
};

#endif // GAME_H
