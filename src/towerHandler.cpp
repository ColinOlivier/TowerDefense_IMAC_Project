#include "towerHandler.hpp"
#include "tower.hpp"

Tower TowerHandler::generateTower(TowerType type)
{
    Tower tower{};
    if(type == TowerType::basicTower)
    {
        tower = {5, 25, 0.5};
    }
    else if(type == TowerType::pineappleTower)
    {
        tower = {15, 10, 2};
    }
    else if(type == TowerType::hiveTower)
    {
        tower = {20, 15, 0.25};
    }
};

std::vector<Tower> TowerHandler::generateTowers(TowerType type, int numberTower)
{
    std::vector<Tower> listTowers{};
    for(int i{0}; i<numberTower; i++)
    {
        listTowers.push_back(generateTower(type));
    }
    return listTowers; 
};