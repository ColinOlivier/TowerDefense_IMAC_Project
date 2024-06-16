#pragma once

#include "enemy/enemy.hpp"
#include "enemy/enemyDrawer.hpp"

#include <vector>

struct GameManager;

struct EnemyHandler
{
private:
    GameManager *_gameManager_ptr;

public:
    EnemyHandler(GameManager *gameManager_ptr);

    std::vector<Enemy> listEnemies{};

    double previousTime{0};
    EnemyDrawer enemyDrawer{};

    int waveCount{0};

    std::queue<Position> positionQueue{};

    Enemy generateEnemy(Name name, Position initialOffset);
    std::vector<Enemy> generateEnemies(Name name, int numberEnemies, float offsetStep);

    void setup();
    void update();
    void render();
};