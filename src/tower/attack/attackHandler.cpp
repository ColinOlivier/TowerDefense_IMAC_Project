#include "attackHandler.hpp"
#include "player/player.hpp"
#include "tower/attack/attack.hpp"
#include "tower/attack/attackDrawer.hpp"
#include "tower/tower.hpp"
#include <ctime>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <glad/glad.h>
#include <sstream>

#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"

Attack AttackHandler::generateAttack(AttackType type)
{
    Position positionTower;
    Position positionAttack;
    positionAttack.x = positionTower.x - 0.1;
    positionAttack.y = positionTower.y + 0.2;
    Attack attack{};
    if (type == AttackType::fast)
    {
        attack = {positionAttack.x, positionAttack.y, 0.15f};
    }
     if (type == AttackType::slow)
    {
        attack = {positionAttack.x, positionAttack.y, 0.15f};
    }
    return attack;
    // on peut changer la vitesse
}

std::vector<Attack> AttackHandler::generateAttacks(AttackType type, int numberAttacks)
{
    std::vector<Attack> listAttacks{};
    // float offsetStep = 0.2f; // distance entre chaque attaque
    for (int i{0}; i < numberAttacks; i++)
    {
        // Position offset{offsetStep * i, 0};
        listAttacks.push_back(generateAttack(type));
    }
    return listAttacks;
};

void AttackHandler::setup()
{
    previousTime = 0;

    attackDrawer.setup();
    listAttacks = generateAttacks(AttackType::fast, 1);
    positionQueue.push({-0.55, 0.45});

    // positionQueue.push({0.1, 0.3});
}

void AttackHandler::update() // à retravailler
{
    // Move
    const float currentTime{(float)glfwGetTime()};
    double ellapsedTime{(currentTime - previousTime)};
    previousTime = currentTime;

    std::vector<size_t> attackIndices;

    for (size_t i = 0; i < listAttacks.size(); i++)
    {
        float time = static_cast<float>(ellapsedTime);
        listAttacks[i].queueMove(time, positionQueue);
        if (listAttacks[i].attackInvisible)
        {
            attackIndices.push_back(i);
        }
    }

    for (auto it = attackIndices.rbegin(); it != attackIndices.rend(); ++it)
    {
        listAttacks.erase(listAttacks.begin() + *it);
    }
}

void AttackHandler::render()
{
    for (size_t i = 0; i < listAttacks.size(); i++)
    {
        attackDrawer.render(listAttacks);
    }
}