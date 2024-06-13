#pragma once
#include <iostream>
#include <vector>
#include "utils.hpp"

struct Tower
{
    Position positionTower;
    //int prix;
    int power; // si la tour est de puissance 5 elle enlève 5 vies à l'ennemi
    float rangeShot; // portée de tir = nombre de pixel ?
    float shootingRace; //cadence de tir = nombre de tir pour 1 seconde, exemple 1/2 pour un tir toutes les 2 sec
    void setup();
    void update();
    void render();
    int shot(); // tire sur les ennemis et renvoie le nombre de vie restant de l'ennemi
};

enum class TowerType
{
    basicTower,
    pineappleTower,
    hiveTower,
};