#include "utils.hpp"
#include "enemy/enemy.hpp"
#include "GameManager.hpp"

#include <iostream>
#include <queue>

Position Enemy::queueMove(float advancement, std::queue<Position> &queue)
{
    if (queue.empty())
    {
        return position;
    }

    Position end = queue.front();

    while (advancement > 0 && !queue.empty())
    {
        float distanceToTravel = advancement * velocity;
        position = move(position, end, distanceToTravel);

        if (position == end)
        {
            queue.pop();
            if (!queue.empty())
            {
                end = queue.front();
            }
        }
        else
        {
            advancement = 0; // Stop the loop if we haven't reached the end
        }
    }

    return position;
}

Position Enemy::move(Position begin, Position end, float distanceToTravel)
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
        begin.y + vecBeginEnd.y * ratio};
    // std::cout << " Milan selon enemy x : " << newPos.x << " Milan selon enemy y : " << newPos.y << std::endl;
    return newPos;
}

void Enemy::hurt(float dammage)
{
    if (isDead)
        return;

    float currentLifePoints{lifePoints - dammage};
    if (currentLifePoints <= 0)
    {
        die();
        return;
    }
    lifePoints = currentLifePoints;
};

void Enemy::die()
{
    isDead = true;
    _enemyHandler->_gameManager_ptr->addPoints(reward);
}
