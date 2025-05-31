#include "Regular_matrix.h"

Regular_matrix::Regular_matrix(float x, float y)
    : Enemy(x, y, 60.f, 3) {
    shape.setFillColor(sf::Color::Yellow);
}
