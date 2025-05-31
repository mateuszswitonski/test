#include "Schmidt_boss.h"

Schmidt_boss::Schmidt_boss(float x, float y)
    : Enemy(x, y, 50.f, 10) {
    shape.setFillColor(sf::Color::Magenta);
}
