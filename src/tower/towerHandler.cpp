#include "tower/towerHandler.hpp"
#include "tower/tower.hpp"


TowerHandler::TowerHandler(GameManager* gameManager_ptr) {
    _gameManager_ptr = gameManager_ptr;
}


void TowerHandler::setup() {
    _towerDrawer.setup();
}

void TowerHandler::update() {

}

void TowerHandler::render() {
    _towerDrawer.drawTowers(listTowers);
}


Tower TowerHandler::generateTower(TowerType type)
{
    float x = 0.f;
    float y = 0.f;
    Tower tower{};
    if (type == TowerType::basicTower)
    {
        tower = {x, y, 5, 25, 0.5};
    }
    else if (type == TowerType::pineappleTower)
    {
        tower = {x, y, 15, 10, 2};
    }
    else if (type == TowerType::hiveTower)
    {
        tower = {x, y, 20, 15, 0.25};
    }
    return tower;
}

std::vector<Tower> TowerHandler::generateTowers(TowerType type, int numberTower)
{
    std::vector<Tower> listTowers{};
    for (int i{0}; i < numberTower; i++)
    {
        listTowers.push_back(generateTower(type));
    }
    return listTowers;
}

