#include <SFML/Graphics.hpp>
#include "Enemy_waves.h".h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");

    Enemy_waves waves;
    waves.spawnWave(1);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time dt = clock.restart();

        waves.update(dt);

        window.clear();
        waves.render(window);
        window.display();
    }

    return 0;
}
