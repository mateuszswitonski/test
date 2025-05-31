#include "Enemy_waves.h"
#include "Regular_matrix.h"
#include "Identity_matrix.h"
#include "Orthogonal_matrix.h"
#include "Schmidt_boss.h"
// #include inne typy wrogów, gdy będą gotowe

Enemy_waves::Enemy_waves() {}

void Enemy_waves::update(sf::Time dt) {
    for (auto& enemy : enemies) {
        if (enemy->isAlive()) {
            enemy->update(dt);
        }
    }

    // Usuwanie martwych przeciwników
    enemies.erase(
        std::remove_if(enemies.begin(), enemies.end(),
                       [](const std::shared_ptr<Enemy>& e) { return !e->isAlive(); }),
        enemies.end());
}

void Enemy_waves::render(sf::RenderWindow& window) {
    for (const auto& enemy : enemies) {
        if (enemy->isAlive()) {
            enemy->render(window);
        }
    }
}

void Enemy_waves::spawnWave(int waveNumber) {
    // Przykładowa fala – można rozbudować o losowość i różnorodność
    for (int i = 0; i < waveNumber * 3; ++i) {
        float x = -50.f * i; // poza ekranem, kolejni pojawiają się z odstępem
        float y = 100.f + (i % 5) * 50; // kilka ścieżek
        enemies.push_back(std::make_shared<Regular_matrix>(x, y));
    }

    // Można też dodać IdentityMatrixEnemy lub inne, zależnie od fali
}

int Enemy_waves::getEnemyCount() const {
    return static_cast<int>(enemies.size());
}
