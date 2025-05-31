#include "Identity_matrix.h"

Identity_matrix::Identity_matrix(float x, float y)
    : Enemy(x, y, 60.f, 3) {
    shape.setFillColor(sf::Color::Yellow);
}
