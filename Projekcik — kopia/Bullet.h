#pragma once
class Bullet {
public:
    void update(float, const std::vector<std::unique_ptr<class Enemy>>&) {}
    void draw(sf::RenderWindow&) {}
};
