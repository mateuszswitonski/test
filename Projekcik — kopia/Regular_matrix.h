#ifndef REGULAR_MATRIX_H
#define REGULAR_MATRIX_H

#pragma once
#include "Enemy.h"

// Klasa przeciwnika - zwykła macierz (średnia prędkość i siła)
class Regular_matrix : public Enemy {
public:
    Regular_matrix(float x, float y);
};

#endif // REGULAR_MATRIX_H
