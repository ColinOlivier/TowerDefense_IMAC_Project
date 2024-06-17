#pragma once

#include "fileReader/IDTFileReader.hpp"
#include "fileReader/MapPNGReader.hpp"

#include "map/MapData.hpp"
#include "map/MapDrawer.hpp"

#include "enemy/enemyHandler.hpp"

#include "tower/towerHandler.hpp"
#include "button/exit.hpp"
#include "button/start.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define IDT_FILE_PATH "../../data/map.idt"
#define MAP_PNG_PATH "images/map.png"

struct GameManager
{
private:
    IDTFileReader _idtReader;
    MapPNGReader _mapPNGReader;

    MapData _mapData;
    MapDrawer _mapDrawer;
public:
    EnemyHandler _enemyHandler{ this };
    TowerHandler _towerHandler{ this };
    std::array<TileType, GRID_SIZE* GRID_SIZE> getMapTileTypeArray();

    ExitButton _exitButton{};
    StartButton _startButton{};
    void setup();
    void update();
    void render();
    void setupMapData();

    void clickForCreateTower(Position positionClick);

    void runWave();

    void clickForExit(Position positionClick, GLFWwindow *window);
    void clickForStart(Position positionClick);

    bool isPause = true;
};
