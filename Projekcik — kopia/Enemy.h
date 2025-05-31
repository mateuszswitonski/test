#ifndef ENEMY_H
#define ENEMY_H

#pragma once
#include <SFML/Graphics.hpp>

// Bazowa klasa przeciwnika w grze (macierz w formie prostokąta)
class Enemy {
public:
    Enemy(float startX, float startY, float speed, int health);
    virtual ~Enemy() = default;

    virtual void update(sf::Time dt);                 // Ruch
    virtual void render(sf::RenderWindow& window);    // Rysowanie

    bool isAlive() const;     // Czy wciąż żyje
    void takeDamage(int dmg); // Otrzymanie obrażeń

    sf::Vector2f getPosition() const; // Zwraca pozycję

protected:
    sf::RectangleShape shape;
    sf::Vector2f velocity;    // Prędkość ruchu
    int health;               // Punkty życia
};

#endif // ENEMY_H
