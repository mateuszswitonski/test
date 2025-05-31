#ifndef PROJECTILES_H
#define PROJECTILES_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "enemy.h"
class Projectiles
{
protected:
    sf::CircleShape pocisk;
    float predkosc;
    sf::Vector2f kierunek;
    bool aktywny = true;
public:
    Projectiles(float predkosc,sf::Vector2f startPos, sf::Vector2f cel);

    void lot(float dt);

    void Wyswietl(sf::RenderWindow& window);

    void Kolizja(const std::vector<Enemy>& enemies);

    bool isAktywny() const { return aktywny; }

    sf::FloatRect getBounds() const;
};

#endif // PROJECTILES_H
