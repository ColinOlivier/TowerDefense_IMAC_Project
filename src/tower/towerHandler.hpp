#pragma once
#include <iostream>
#include <vector>
#include "tower/tower.hpp"

struct TowerHandler
{
    std::vector<Tower> tower;
    void setup();
    void update();
    void render();
    Tower generateTower(TowerType type);
    std::vector<Tower> generateTowers(TowerType type, int numberTower);
};
