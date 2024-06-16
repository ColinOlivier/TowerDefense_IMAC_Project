#include "tower/attack/attack.hpp"
#include "tower/tower.hpp"
#include "enemy/enemy.hpp"

Attack::Attack(Position position, Tower* towerAttacker, Enemy* enemyTarget) {
    positionAttack = position;
    _towerAttacker = towerAttacker;
    _enemyTarget = enemyTarget;
}

Position Attack::move(Position begin, Position end, float distanceToTravel /*temps parcours / distance*/)
{
    Position vecBeginEnd = end - begin;
    float distance = sqrt(vecBeginEnd.x * vecBeginEnd.x + vecBeginEnd.y * vecBeginEnd.y);

    if (distanceToTravel >= distance)
    {
        return end;
    }

    float ratio = distanceToTravel / distance;
    Position newPos = {
        begin.x + vecBeginEnd.x * ratio,
        begin.y + vecBeginEnd.y * ratio };

    return newPos;
}

void Attack::move(float advancement) {
    if (_enemyTarget == nullptr)
        return;
    Position vecBeginEnd = _enemyTarget->position - _towerAttacker->positionTower;
    float distance = sqrt(vecBeginEnd.x * vecBeginEnd.x + vecBeginEnd.y * vecBeginEnd.y);

    positionAttack += (vecBeginEnd * (1 / distance)) * advancement;
}
