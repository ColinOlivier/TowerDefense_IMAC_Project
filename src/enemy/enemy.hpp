#pragma once

#include "utils.hpp"
#include <queue>

enum class Name
{
    Milan,
    Guimiel,
    Elea
};

struct Enemy
{
    Name name;
    Position position{0, 0};
    float lifePoints{0};
    float velocity{0};
    unsigned int reward{0};
    bool isDead{false};

    Position queueMove(float advancement /*temps parcours / distance*/, std::queue<Position> &queue);
    Position move(Position begin, Position end, float advancement /*temps parcours / distance*/);
    void hurt(float dammage);
    void die();
};
