#pragma once
#include "SFML/Graphics/RenderWindow.hpp"
#include <memory>
class UI {
public:
    void update(float, const std::vector<std::unique_ptr<class Enemy>>&) {}
    void draw(sf::RenderWindow&) {}
};
