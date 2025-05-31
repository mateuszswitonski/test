#ifndef ENEMY_WAVES_H
#define ENEMY_WAVES_H

#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Enemy.h"

// Zarządza przeciwnikami i ich falami
class Enemy_waves {
public:
    Enemy_waves();

    // Aktualizacja przeciwników
    void update(sf::Time dt);

    // Rysowanie przeciwników
    void render(sf::RenderWindow& window);

    // Inicjowanie nowej fali
    void spawnWave(int waveNumber);

    // Zwraca ilość żyjących przeciwników
    int getEnemyCount() const;

private:
    std::vector<std::shared_ptr<Enemy>> enemies; // Kontener na przeciwników
};

#endif // ENEMY_WAVES_H
