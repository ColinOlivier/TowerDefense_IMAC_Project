#pragma once

#include "fileReader/IDTFileReader.hpp"
#include "fileReader/MapPNGReader.hpp"

#include "map/MapData.hpp"
#include "map/MapDrawer.hpp"

#include "enemy/enemyHandler.hpp"

#include "tower/towerHandler.hpp"

#define IDT_FILE_PATH "../../data/map.idt"
#define MAP_PNG_PATH "images/map.png"

struct GameManager
{
private:
    IDTFileReader _idtReader;
    MapPNGReader _mapPNGReader;

    MapData _mapData;
    MapDrawer _mapDrawer;

    EnemyHandler _enemyHandler{ this };
    TowerHandler _towerHandler{ this };
public:
    void setup();
    void update();
    void render();

    void setupMapData();
    void clickForCreateTower(Position positionClick);
};
