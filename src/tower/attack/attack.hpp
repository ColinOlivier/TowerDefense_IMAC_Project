#pragma once
#include "utils.hpp"
#include <vector>

struct Tower;
struct Enemy;

struct Attack
{
private:
    Tower* _towerAttacker;
    Enemy* _enemyTarget;
    float velocity{ 0 }; //vitesse
    bool attackInvisible = false;
public:
    Position positionAttack;
    Attack(Position position, Tower* towerAttacker, Enemy* enemyTarget);

    Position move(Position begin, Position end, float advancement /*temps parcours / distance*/);
    void move(float advancement);
};
