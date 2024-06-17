#pragma once
#include <iostream>
#include <vector>
#include "tower/tower.hpp"
#include "tower/towerDrawer.hpp"
#include "tower/attack/attackHandler.hpp"

struct GameManager;

struct TowerHandler
{
private:
    GameManager* _gameManager_ptr;
    TowerDrawer _towerDrawer{};
    AttackHandler _attackHandler{ this };
public:
    TowerHandler(GameManager* gameManager_ptr);

    std::vector<Tower> listTowers;

    void setup();
    void update();
    void render();
    Tower generateTower(TowerType type);
    std::vector<Tower> generateTowers(TowerType type, int numberTower);

    bool canBuild(Position clickPos);
};
