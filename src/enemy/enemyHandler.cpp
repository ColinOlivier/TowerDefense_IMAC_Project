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

Enemy EnemyHandler::generateEnemy(Name name, Position initialOffset)
{
    Enemy enemy{this,name, initialOffset, 10, 0.1f, 5}; // Utiliser le décalage initial

    if (name == Name::Milan)
    {
        enemy = Enemy{this,name, initialOffset, 10, 0.1f, 5};
    }

    if (name == Name::Guimiel)
    {
        enemy = Enemy{this,name, initialOffset, 10, 5, 5};
    }

    if (name == Name::Elea)
    {
        enemy = Enemy{this,name, initialOffset, 10, 5, 5};
    }

    return enemy;
}

std::vector<Enemy> EnemyHandler::generateEnemies(Name name, int numberEnemies, float offsetStep)
{
    std::vector<Enemy> listEnemies{};
    // float offsetStep = 0.2f;  Distance entre les ennemis
    for (int i = 0; i < numberEnemies; i++)
    {
        Position offset{offsetStep * i, offsetStep * i}; // Décaler chaque ennemi de 'offsetStep' sur l'axe x
        listEnemies.push_back(generateEnemy(name, offset));
    }
    return listEnemies;
}

void EnemyHandler::setup()
{
    previousTime = 0.0;
    // enemyDrawer = EnemyDrawer();
    enemyDrawer.setup();
    listEnemies = generateEnemies(Name::Milan, 3, 0.15);

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

    // Move
    const float currentTime{(float)glfwGetTime()};
    double ellapsedTime{currentTime - previousTime};
    previousTime = currentTime;

    std::vector<size_t> deadEnemiesIndices;
    std::vector<size_t> deadEnemiesIndices_second;
    std::vector<size_t> deadEnemiesIndices_third;

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

    for (auto it = deadEnemiesIndices.rbegin(); it != deadEnemiesIndices.rend(); ++it)
    {
        listEnemies.erase(listEnemies.begin() + *it);
    }

    // 2EME VAGUE
    if (waveCount > 0)
    {
        for (size_t i = 0; i < listEnemies_second.size(); i++)
        {
            float time = static_cast<float>(ellapsedTime);
            listEnemies_second[i].queueMove(time, positionQueue_second);
            // Générer des dégâts aléatoires entre 0 et 1
            float randomDamage = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 0.05;
            listEnemies_second[0].hurt(randomDamage);
            if (listEnemies_second[i].isDead)
            {
                deadEnemiesIndices_second.push_back(i);
            }
        }
        // Supprimer les ennemis morts en partant de la fin pour éviter les problèmes d'indices
        for (auto it = deadEnemiesIndices_second.rbegin(); it != deadEnemiesIndices_second.rend(); ++it)
        {
            listEnemies_second.erase(listEnemies_second.begin() + *it);
        }
    }

    // 3EME VAGUE
    if (waveCount > 1)
    {
        for (size_t i = 0; i < listEnemies_third.size(); i++)
        {
            float time = static_cast<float>(ellapsedTime);
            listEnemies_third[i].queueMove(time, positionQueue_third);
            // Générer des dégâts aléatoires entre 0 et 1
            float randomDamage = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 0.05;
            listEnemies_third[0].hurt(randomDamage);
            if (listEnemies_third[i].isDead)
            {
                deadEnemiesIndices_third.push_back(i);
            }
        }
        // Supprimer les ennemis morts en partant de la fin pour éviter les problèmes d'indices
        for (auto it = deadEnemiesIndices_third.rbegin(); it != deadEnemiesIndices_third.rend(); ++it)
        {
            listEnemies_third.erase(listEnemies_third.begin() + *it);
        }
    }
}

void EnemyHandler::render()
{
    for (size_t i = 0; i < listEnemies.size(); i++)
    {
        enemyDrawer.drawEnemy(listEnemies[i]);
    }
    for (size_t i = 0; i < listEnemies_second.size(); i++)
    {
        enemyDrawer.drawEnemy(listEnemies_second[i]);
    }
    for (size_t i = 0; i < listEnemies_third.size(); i++)
    {
        enemyDrawer.drawEnemy(listEnemies_third[i]);
    }
}
