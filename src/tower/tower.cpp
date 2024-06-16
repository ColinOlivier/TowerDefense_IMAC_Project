#include "tower/tower.hpp"
#include "tower/attack/attack.hpp"

#include <GLFW/glfw3.h>

bool Tower::canShot() {
    return (glfwGetTime() - lastShotTime) > shootingRace;
}

Attack Tower::shot(Enemy* enemyTarget)
{
    lastShotTime = glfwGetTime();
    return Attack(positionTower, this, enemyTarget);
}