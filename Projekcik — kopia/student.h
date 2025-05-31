#ifndef STUDENT_H
#define STUDENT_H
#include "projectiles.h"
#include "tower.h"
#include "enemy.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Student : public Tower{
private:
    string nazwa;
    sf::RectangleShape wiezyczka;
    vector<Projectiles> pociski;
    float timer=0;
    float cooldown;
public:
    Student(float Predkosc_ataku,int Obrazenia, int Cena);
    virtual void Wyswietl(sf::RenderWindow& window) override;
    virtual void Atakuj(sf::Vector2f cel)override;
    virtual void Ulepsz()override;
    void update(float dt, const std::vector<Enemy>& enemies);
};

#endif // STUDENT_H
