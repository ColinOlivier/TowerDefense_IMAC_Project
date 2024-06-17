#pragma once
#include <iostream>
#include <vector>
#include "utils.hpp"
#include "tower/attack/attack.hpp"
#include "enemy/enemy.hpp"

enum class TowerType
{
    basicTower,
    pineappleTower,
    hiveTower,
};

struct Tower
{
    Position positionTower;
    TowerType type;
    int price;
    int power;               // puissance si la tour est de puissance 5 elle enlève 5 vies à l'ennemi
    float rangeShot;         // portée de tir = nombre de pixel ?
    float shootingRace{2.f}; // temps = cadence de tir = nombre de tir pour 1 seconde, exemple 1/2 pour un tir toutes les 2 sec
    double lastShotTime;
    int meter = 0; // compteur

    Attack shot(Enemy *enemyTarget);
    bool canShot();
};
