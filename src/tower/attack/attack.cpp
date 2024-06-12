#include "utils.hpp"
#include "tower/attack/attack.hpp"
#include "player/player.hpp"
#include "tower/tower.hpp"

#include <iostream>
#include <queue>

Position Attack::queueMove(float advancement /*temps parcours / distance*/, std::queue<Position> &queue)
{
    Position end = queue.front();

    while (advancement > 0 && !queue.empty())
    {
        float distanceToTravel = advancement * velocity;
        positionAttack = move(positionAttack, end, distanceToTravel);

        if (positionAttack == end)
        {
            queue.pop();
            attackInvisible = true;
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

    if (queue.empty())
    {
        return positionAttack;
    }

    return positionAttack;
}

Position Attack::move(Position begin, Position end, float distanceToTravel /*temps parcours / distance*/)
{
    // Position positionTower;
    // begin.x = positionTower.x;
    // begin.y = positionTower.y;
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

    return newPos;
}
