#pragma once

#include <glad/glad.h>
#include <simpletext.h>
#include "GLFW/glfw3.h"

#include "fileReader/IDTFileReader.hpp"
#include "fileReader/MapPNGReader.hpp"

#include "map/MapData.hpp"
#include "map/MapDrawer.hpp"

#include "enemy/enemyHandler.hpp"
#include "points/points.hpp"

#include "tower/towerHandler.hpp"
#include "button/exit.hpp"
#include "button/start.hpp"
#include "button/pause.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define IDT_FILE_PATH "../../data/map.idt"
#define MAP_PNG_PATH "images/map.png"

struct App;

struct GameManager
{
private:
    App *_app;
    IDTFileReader _idtReader;
    MapPNGReader _mapPNGReader;

    MapData _mapData;
    MapDrawer _mapDrawer;

public:
    GameManager(App *app);
    EnemyHandler _enemyHandler{this};
    TowerHandler _towerHandler{this};

    SimpleText TextRenderer{};

    int score{0};
    void addPoints(int reward);

    std::array<TileType, GRID_SIZE * GRID_SIZE> getMapTileTypeArray();

    ExitButton _exitButton{};
    StartButton _startButton{};
    PauseButton _pauseButton{};
    Points _points{};
    void setup();
    void update();
    void render();
    void setupMapData();

    void clickForCreateTower(Position positionClick);

    void runWave();

    void clickForExit(Position positionClick, GLFWwindow *window);
    void clickForStart(Position positionClick);
    void clickForPause(Position positionClick);

    bool isPause = true;
};
