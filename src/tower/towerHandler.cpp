#include "tower/towerHandler.hpp"
#include "tower/tower.hpp"

#include "GameManager.hpp"

TowerHandler::TowerHandler(GameManager *gameManager_ptr)
{
    _gameManager_ptr = gameManager_ptr;
}

void TowerHandler::setup()
{
    _towerDrawer.setup();
    _attackHandler.setup();
}

void TowerHandler::update()
{
    _attackHandler.update();

    for (int i{0}; i < listTowers.size(); i++)
    {

        if (_attackHandler.listAttacks.size() > 6)
            return;

        // Can't shot
        if (!listTowers[i].canShot())
            continue;

        if (_gameManager_ptr->_enemyHandler.listEnemies.empty())
            continue;

        Enemy *target = &_gameManager_ptr->_enemyHandler.listEnemies[0];

        _attackHandler.listAttacks.push_back(listTowers[i].shot(target));
    }
}

void TowerHandler::render()
{
    _towerDrawer.drawTowers(listTowers);
    _attackHandler.render();
}

Tower TowerHandler::generateTower(TowerType type)
{
    float x = 0.f;
    float y = 0.f;
    Tower tower{};
    if (type == TowerType::basicTower)
    {
        tower = {{x, y}, type, 20, 5, 25, 0.5};
    }
    else if (type == TowerType::pineappleTower)
    {
        tower = {{x, y}, type, 30, 15, 10, 2};
    }
    // else if (type == TowerType::hiveTower)
    // {
    //     tower = {x, y, 30, 20, 15, 0.25};
    // }
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

bool TowerHandler::canBuild(Position clickPos)
{
    if (listTowers.size() >= 5)
        return false;

    clickPos.x = clickPos.x * 10;
    clickPos.y = clickPos.y * -10 + 10;

    int X = (int)std::roundf(clickPos.x);
    int Y = (int)std::roundf(clickPos.y);
    std::cout << X << "/" << Y << std::endl;

    TileData tile = _gameManager_ptr->_mapData.tilesArray[X + Y * GRID_SIZE];

    std::cout << (int)tile.type << std::endl;

    if (tile.type != TileType::TOWER_BASE)
        return false;

    return true;
}
