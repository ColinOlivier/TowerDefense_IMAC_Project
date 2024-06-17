#include "tower/attack/attack.hpp"
#include "tower/tower.hpp"
#include "enemy/enemy.hpp"

Attack::Attack(Position position, Tower *towerAttacker, Enemy *enemyTarget)
{
    positionAttack = position;
    _towerAttacker = towerAttacker;
    _enemyTarget = enemyTarget;
}

// Position Attack::move(Position begin, Position end, float distanceToTravel /*temps parcours / distance*/)
// {
//     Position vecBeginEnd = end - begin;
//     float distance = sqrt(vecBeginEnd.x * vecBeginEnd.x + vecBeginEnd.y * vecBeginEnd.y);

//     if (distanceToTravel >= distance)
//     {
//         return end;
//     }

//     float ratio = distanceToTravel / distance;
//     Position newPos = {
//         begin.x + vecBeginEnd.x * ratio,
//         begin.y + vecBeginEnd.y * ratio };

//     return newPos;
// }

void Attack::move(float advancement)
{
    if (_enemyTarget == nullptr)
        return;

    // Vecteur de la position actuelle de l'attaque à la position de l'ennemi cible
    Position vecToTarget = _enemyTarget->position - positionAttack;
    float distanceToTarget = std::sqrt(vecToTarget.x * vecToTarget.x + vecToTarget.y * vecToTarget.y);

    if (distanceToTarget == 0)
        return;

    // Normaliser le vecteur de direction
    Position direction = vecToTarget * (1.0f / distanceToTarget);

    // Calculer la nouvelle position potentielle
    Position newPosition = positionAttack + direction * advancement;

    // Vérifier si la nouvelle position dépasse la cible
    float advancementToTarget = advancement - distanceToTarget;
    if (advancementToTarget >= 0)
    {
        // Si la nouvelle position dépasse la cible, définir la position directement sur la cible
        positionAttack = _enemyTarget->position;
    }
    else
    {
        // Sinon, mettre à jour la position normalement
        positionAttack = newPosition;
    }
}

void Attack::checkHit()
{
    Position vecBeginEnd = _enemyTarget->position - positionAttack;

    float distance = sqrt(vecBeginEnd.x * vecBeginEnd.x + vecBeginEnd.y * vecBeginEnd.y);

    if (distance < 0.01f)
    {
        _enemyTarget->hurt(_towerAttacker->power);
        // std::cout << "Boulet x : " << positionAttack.x << " Boulet y : " << positionAttack.y << std::endl;
    }
}
