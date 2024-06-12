#pragma once

#include "tower/attack/attack.hpp"
#include "tower/attack/attackDrawer.hpp"

#include <vector>

struct AttackHandler
{
    std::vector<Attack> listAttacks{};

    double previousTime{0};
    AttackDrawer attackDrawer{};

    std::queue<Position> positionQueue{};

    Attack generateAttack(Position positionAttack);
    std::vector<Attack> generateAttacks(int numberAttacks);

    void setup();
    void update();
    void render();
    
    // float moveX = 0.01f;
    // float moveY = 0.01f;
    // float maxX = 1.0f;
    // float maxY = 1.0f;
};