#include "utils.hpp"
#include "enemy.hpp"

#include <iostream>
#include <queue>

Position Enemy::queueMove(float advancement /*temps parcours / distance*/, std::queue<Position> &queue)
{
    // Position begin;
    Position end;
    if (queue.size() > 1)
    {
        end = queue.front();
        if (position.x == end.x && position.y == end.y)
        {
            queue.pop();
        }
        // end = queue.front();
        // std::cout << end.x << " " << end.y << ": " << position.x << " " << position.y << std::endl;
    }
    position = move(position, end, advancement * velocity);

    return position;
}

Position Enemy::move(Position begin, Position end, float advancement /*temps parcours / distance*/)
{
    Position vecBeginEnd = end - begin;
    Position newVec = vecBeginEnd * advancement;
    Position newPos = begin + newVec;
    return newPos;
}
// Calcul distance position actuelle - destination
// float distance = sqrt((end.x - begin.x, 2) * (end.x - begin.x, 2) + (end.y - begin.y, 2) * (end.y - begin.y, 2));
// if (position.x != end.x)
// {
//     position.x += advancement * velocity;
// }
// if (position.y != end.y)
// {
//     position.y += advancement * velocity;
// }
// if (advancement >= distance)
// {
// GAME OVER
// }
// void Enemy::hurt(int dammage)
// {
//     int currentLifePoints{lifePoints - dammage};
//     if (currentLifePoints <= 0)
//     {
//         die();
//         return;
//     }
//     lifePoints = currentLifePoints;
// };

// void Enemy::die()
// {
//     // TODO
//     // cagnotte = reward;
// }
