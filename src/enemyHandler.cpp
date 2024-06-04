#include "enemyHandler.hpp"
#include <GLFW/glfw3.h>
#include <ctime>
#include <iostream>

Enemy EnemyHandler::generateEnemy(Name name)
{
    Enemy enemy{};
    if (name == Name::Milan)
    {
        enemy = {name, {0, 0}, 10, 0.1f, 5};
    }

    if (name == Name::Guimiel)
    {
        enemy = {name, {0, 0}, 10, 5, 5};
    }

    if (name == Name::Elea)
    {
        enemy = {name, {0, 0}, 10, 5, 5};
    }
    return enemy;
};

std::vector<Enemy> EnemyHandler::generateEnemies(Name name, int numberEnemies)
{
    std::vector<Enemy> listEnemies{};
    for (int i{0}; i < numberEnemies; i++)
    {
        listEnemies.push_back(generateEnemy(name));
    }
    return listEnemies;
};

void EnemyHandler::setup()
{
    previousTime = 0.0;
    // enemyDrawer = EnemyDrawer();
    enemyDrawer.setup();
    listEnemies = generateEnemies(Name::Milan, 3);

    // positionQueue = données Colin
    positionQueue.push({0, 1.5});
    positionQueue.push({0., 0});
    positionQueue.push({-0.5, -0.25});
    positionQueue.push({0.25, 0.5});
    positionQueue.push({1.5, 1});
    positionQueue.push({-1, 0});
}

void EnemyHandler::update()
{
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    float random_value = rand();

    // Move
    const float currentTime{(float)glfwGetTime()};
    std::cout << currentTime << std::endl;
    double ellapsedTime{(currentTime - previousTime)};
    previousTime = currentTime;
    for (size_t i = 0; i < listEnemies.size(); i++)
    {
        float time = float(ellapsedTime) + std::rand() * 0.000001f;
        listEnemies[i].queueMove(time /*borne 0 et 1*/, positionQueue /*recup queue colin*/);
    }
}

void EnemyHandler::render()
{
    for (size_t i = 0; i < listEnemies.size(); i++)
    {
        enemyDrawer.drawEnemy(listEnemies[i]);
    }
}
