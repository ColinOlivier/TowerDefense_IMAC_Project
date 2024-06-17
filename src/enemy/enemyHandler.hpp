#pragma once

#include "enemy/enemy.hpp"
#include "enemy/enemyDrawer.hpp"

#include <vector>

struct GameManager;

struct EnemyHandler
{
    GameManager *_gameManager_ptr;
    EnemyHandler(GameManager *gameManager_ptr);

    std::vector<Enemy> listEnemies{};
    std::vector<Enemy> listEnemies_second{};
    std::vector<Enemy> listEnemies_third{};

    double previousTime{0};
    EnemyDrawer enemyDrawer{};

    int waveCount{0};

    std::queue<Position> positionQueue{};
    std::queue<Position> positionQueue_second{};
    std::queue<Position> positionQueue_third;

    Enemy generateEnemy(Name name, Position initialOffset);
    std::vector<Enemy> generateEnemies(Name name, int numberEnemies, float offsetStep);

    void setup();
    void update();
    void render();
};