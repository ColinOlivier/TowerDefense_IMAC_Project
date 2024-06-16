#include "enemyHandler.hpp"
#include "player/player.hpp"
#include "GameManager.hpp"
#include <GLFW/glfw3.h>
#include <ctime>
#include <iostream>
#include <cstdlib>

EnemyHandler::EnemyHandler(GameManager *gameManager_ptr)
{
    _gameManager_ptr = gameManager_ptr;
}

Enemy EnemyHandler::generateEnemy(Name name, Position initialOffset)
{
    Enemy enemy{name, initialOffset, 10, 0.1f, 5}; // Utiliser le décalage initial

    if (name == Name::Milan)
    {
        enemy = {name, initialOffset, 10, 0.1f, 5};
    }

    if (name == Name::Guimiel)
    {
        enemy = {name, initialOffset, 10, 5, 5};
    }

    if (name == Name::Elea)
    {
        enemy = {name, initialOffset, 10, 5, 5};
    }

    return enemy;
}

std::vector<Enemy> EnemyHandler::generateEnemies(Name name, int numberEnemies)
{
    std::vector<Enemy> listEnemies{};
    float offsetStep = 0.2f; // Distance entre les ennemis
    for (int i = 0; i < numberEnemies; i++)
    {
        Position offset{offsetStep * i, 0}; // Décaler chaque ennemi de 'offsetStep' sur l'axe x
        listEnemies.push_back(generateEnemy(name, offset));
    }
    return listEnemies;
}

void EnemyHandler::setup()
{
    previousTime = 0.0;
    // enemyDrawer = EnemyDrawer();
    enemyDrawer.setup();
    listEnemies = generateEnemies(Name::Milan, 3);

    // positionQueue = données Colin
    positionQueue.push({0, 0.5});
    positionQueue.push({0., 0});
    positionQueue.push({-0.5, -0.25});
    positionQueue.push({0.25, 0.5});
    positionQueue.push({1.5, 1});
    positionQueue.push({-1, 0});
}

void EnemyHandler::update()
{
    if (waveCount == 1)
    {
        listEnemies = generateEnemies(Name::Milan, 5);
    }
    if (waveCount == 2)
    {
        listEnemies = generateEnemies(Name::Milan, 7);
    }
    // Move
    const float currentTime{(float)glfwGetTime()};
    double ellapsedTime{currentTime - previousTime};
    previousTime = currentTime;

    std::vector<size_t> deadEnemiesIndices;

    for (size_t i = 0; i < listEnemies.size(); i++)
    {
        float time = static_cast<float>(ellapsedTime);
        listEnemies[i].queueMove(time, positionQueue);
        // Générer des dégâts aléatoires entre 0 et 1
        float randomDamage = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 0.05;
        listEnemies[0].hurt(randomDamage);
        if (listEnemies[i].isDead)
        {
            deadEnemiesIndices.push_back(i);
        }
    }

    // Supprimer les ennemis morts en partant de la fin pour éviter les problèmes d'indices
    for (auto it = deadEnemiesIndices.rbegin(); it != deadEnemiesIndices.rend(); ++it)
    {
        listEnemies.erase(listEnemies.begin() + *it);
    }
}

void EnemyHandler::render()
{
    for (size_t i = 0; i < listEnemies.size(); i++)
    {
        enemyDrawer.drawEnemy(listEnemies[i]);
    }
}
