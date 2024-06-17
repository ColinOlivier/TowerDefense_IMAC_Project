#pragma once

#include "utils.hpp"
#include <queue>

struct EnemyHandler;

enum class Name
{
    Milan,
    Guimiel,
    Elea
};

struct Enemy
{
    EnemyHandler *_enemyHandler;
    Name name;
    Position position{0, 0};
    float lifePoints{0};
    float velocity{0};
    unsigned int reward{0};
    bool isDead{false};

    std::queue<Position> positionQueue{};

    Position queueMove(float advancement /*temps parcours / distance*/, std::queue<Position> &queue);
    Position move(Position begin, Position end, float advancement /*temps parcours / distance*/);
    void hurt(float dammage);
    void die();
};
