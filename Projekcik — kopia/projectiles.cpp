#include "projectiles.h"
#include "enemy.h"
#include <math.h>
Projectiles::Projectiles(float predkosc,sf::Vector2f startPos, sf::Vector2f cel):predkosc(predkosc) {
    pocisk.setRadius(5);
    pocisk.setFillColor(sf::Color::Cyan);
    pocisk.setPosition(startPos);

    sf::Vector2f dir = cel - startPos;
    float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    kierunek = (len != 0) ? dir / len : sf::Vector2f(0.f, 0.f);
}
void Projectiles:: lot(float dt)
{pocisk.move(kierunek * predkosc * dt);}

void Projectiles:: Wyswietl(sf::RenderWindow& window) {
    window.draw(pocisk);
}

sf::FloatRect Projectiles::getBounds() const {
    return pocisk.getGlobalBounds();
}

void Projectiles:: Kolizja(const std::vector<Enemy>& enemies){
    for (const auto& enemy : enemies) {
        if (getBounds().intersects(enemy.getBounds())) {
            aktywny = false;
            break;
        }
    }

}
