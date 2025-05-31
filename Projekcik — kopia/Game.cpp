#include "Game.h"

Game::Game()
    : window(sf::VideoMode(800, 600), "Matrix Defense: Schmidt's Revenge"),
    timePerFrame(sf::seconds(1.f / 60.f)),
    isRunning(true)
{}

void Game::run() {
    sf::Clock clock;

    while (window.isOpen() && isRunning) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(sf::Time deltaTime) {
    waves.update(deltaTime);
}

void Game::render() {
    window.clear(sf::Color::Black);
    waves.render(window);
    window.display();
}

void Game::startNextWave() {
    waves.spawnWave(1);
}

