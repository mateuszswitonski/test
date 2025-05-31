#include "student.h"
#include <iostream>
#include <math.h>
using namespace std;

Student::Student(float Predkosc_ataku,int Obrazenia, int Cena):Tower(Predkosc_ataku,Obrazenia,Cena)
{   wiezyczka.setSize(sf::Vector2f(60, 60));
    wiezyczka.setPosition(375,300);
    wiezyczka.setFillColor(sf::Color::Blue);
    cooldown=Predkosc_ataku;

}
void Student::Wyswietl(sf::RenderWindow& window) {

    window.draw(wiezyczka);

    for (auto& p : pociski) {
        p.Wyswietl(window);
    }
}

void Student::Atakuj(sf::Vector2f cel) {
    pociski.emplace_back(500, wiezyczka.getPosition(), cel);
}

void Student::Ulepsz() {
    cout << "Student: Ulepszono" << endl;
}
void Student::update(float dt, const std::vector<Enemy>& enemies) {
    timer += dt;
    Enemy const* najblizszy = nullptr;
    float minDystans = 300;

    for (const auto& enemy : enemies) {
        float dystans = sqrt(pow(enemy.getPosition().x - wiezyczka.getPosition().x, 2) +
                             pow(enemy.getPosition().y - wiezyczka.getPosition().y, 2));
        if (dystans < minDystans) {
            minDystans = dystans;
            najblizszy = &enemy;
        }
    }


    if (najblizszy && timer >= cooldown) {
        Atakuj(najblizszy->getPosition());
        timer = 0.f;
    }

    for (auto& p : pociski) {
        p.lot(dt);
        p.Kolizja(enemies);
    }
    pociski.erase(std::remove_if(pociski.begin(), pociski.end(),
                                 [](const Projectiles& p) { return !p.isAktywny(); }),
                  pociski.end());
}
