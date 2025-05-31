#ifndef TOWER_H
#define TOWER_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
class Tower
{
protected:
    int Predkosc_ataku;
    int Obrazenia;
    int Cena;
public:
    Tower(int Predkosc_ataku,int Obrazenia, int Cena);
    virtual void Wyswietl(sf::RenderWindow& window)=0;
    virtual void Atakuj(sf::Vector2f cel)=0;
    virtual void Ulepsz()=0;
};

#endif // TOWER_H
