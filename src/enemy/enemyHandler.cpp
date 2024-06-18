#include "enemyHandler.hpp"
#include "GameManager.hpp"
#include <GLFW/glfw3.h>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

EnemyHandler::EnemyHandler(GameManager *gameManager_ptr)
{
    _gameManager_ptr = gameManager_ptr;
}

Enemy EnemyHandler::generateEnemy(Name name, Position initialOffset, std::queue<Position> &queuePosition)
{
    Enemy enemy{this, name, initialOffset, 10, 0.1f, 5}; // Utiliser le décalage initial

    if (name == Name::Milan)
    {
        enemy = Enemy{this, name, initialOffset, 10, 0.1f, 5};
    }

    if (name == Name::Guimiel)
    {
        enemy = Enemy{this, name, initialOffset, 10, 0.3f, 5};
    }

    if (name == Name::Elea)
    {
        enemy = Enemy{this, name, initialOffset, 10, 0.6f, 5};
    }

    enemy.positionQueue = queuePosition;

    return enemy;
}

std::vector<Enemy> EnemyHandler::generateEnemies(Name name, int numberEnemies, float offsetStep, std::queue<Position> &queuePosition)
{
    std::vector<Enemy> listEnemies{};
    // float offsetStep = 0.2f;  Distance entre les ennemis
    for (int i = 0; i < numberEnemies; i++)
    {
        Position offset{offsetStep * i + -0.7f, offsetStep * i + 0.8f}; // Décaler chaque ennemi de 'offsetStep' sur l'axe x
        listEnemies.push_back(generateEnemy(name, offset, queuePosition));
    }
    return listEnemies;
}

void EnemyHandler::setup()
{
    previousTime = 0.0;
    // enemyDrawer = EnemyDrawer();
    enemyDrawer.setup();
}

void EnemyHandler::update()
{

    // Move
    const float currentTime{(float)glfwGetTime()};
    double ellapsedTime{currentTime - previousTime};
    previousTime = currentTime;

    std::vector<size_t> deadEnemiesIndices;

    // 1ERE VAGUE
    if (waveCount > 0)
    {
        for (size_t i = 0; i < listEnemies.size(); i++)
        {
            float time = static_cast<float>(ellapsedTime);
            listEnemies[i].queueMove(time, listEnemies[i].positionQueue);
            // Générer des dégâts aléatoires entre 0 et 1
            Position towerZone;
            Position towerSize;

            // float randomDamage = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 0.05;

            // listEnemies[i].hurt(randomDamage /*tower.power*/);

            if (listEnemies[i].isDead)
            {
                deadEnemiesIndices.push_back(i);
            }
        }
    }

    // 2EME VAGUE
    if (waveCount > 1)
    {
        for (size_t i = 0; i < listEnemies.size(); i++)
        {
            float time = static_cast<float>(ellapsedTime);
            listEnemies[i].queueMove(time, positionQueue);
            // Générer des dégâts aléatoires entre 0 et 1
            // float randomDamage = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 0.05;
            // listEnemies_second[0].hurt(randomDamage);
            if (listEnemies[i].isDead)
            {
                deadEnemiesIndices.push_back(i);
            }
        }
    }

    // 3EME VAGUE
    if (waveCount > 2)
    {
        for (size_t i = 0; i < listEnemies.size(); i++)
        {
            float time = static_cast<float>(ellapsedTime);
            listEnemies[i].queueMove(time, positionQueue);
            // Générer des dégâts aléatoires entre 0 et 1
            // float randomDamage = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 0.05;
            // listEnemies_third[0].hurt(randomDamage);
            if (listEnemies[i].isDead)
            {
                deadEnemiesIndices.push_back(i);
            }
        }
        // Supprimer les ennemis morts en partant de la fin pour éviter les problèmes d'indices
    }

    for (auto it = deadEnemiesIndices.rbegin(); it != deadEnemiesIndices.rend(); ++it)
    {
        if (*it < listEnemies.size())
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
