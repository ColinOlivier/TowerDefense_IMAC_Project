#pragma once
#include "utils.hpp"
#include <queue>
#include <glad/glad.h>
#include <vector>

struct Attack
{
    Position positionAttack;
    float velocity{0}; //vitesse
    bool attackInvisible = false;
    Position queueMove(float advancement /*temps parcours / distance*/, std::queue<Position> &queue);
    Position move(Position begin, Position end, float advancement /*temps parcours / distance*/);
};
