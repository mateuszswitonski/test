#include "Enemy.h"

Enemy::Enemy(float startX, float startY, float speed, int hp)
    : health(hp)
{
    shape.setSize(sf::Vector2f(40.f, 40.f));  // Kwadrat 40x40
    shape.setPosition(startX, startY);
    shape.setFillColor(sf::Color::Red);
    velocity = sf::Vector2f(speed, 0.f); // Ruch w prawo
}

void Enemy::update(sf::Time dt) {
    shape.move(velocity * dt.asSeconds());
}

void Enemy::render(sf::RenderWindow& window) {
    window.draw(shape);
}

bool Enemy::isAlive() const {
    return health > 0;
}

void Enemy::takeDamage(int dmg) {
    health -= dmg;
}

sf::Vector2f Enemy::getPosition() const {
    return shape.getPosition();
}
