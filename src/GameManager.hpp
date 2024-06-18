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
#include "screen/gameOver.hpp"
#include "screen/win.hpp"
#include "goal/goalDrawer.hpp"

#include "tower/towerHandler.hpp"
#include "button/exit.hpp"
#include "button/start.hpp"
#include "button/pause.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define IDT_FILE_PATH "../../data/map.idt"
#define MAP_PNG_PATH "images/map.png"

class App;

struct GameManager
{
private:
    App *_app;
    IDTFileReader _idtReader;
    MapPNGReader _mapPNGReader;

    MapDrawer _mapDrawer;

public:
    MapData _mapData;
    GameManager(App *app);
    EnemyHandler _enemyHandler{this};
    TowerHandler _towerHandler{this};

    SimpleText TextRenderer{};

    int score{30};
    void addPoints(int reward);

    std::array<TileType, GRID_SIZE * GRID_SIZE> getMapTileTypeArray();

    GameOver _gameOver{};
    Win _win{};

    GoalDrawer _goalDrawer{};
    ExitButton _exitButton{};
    StartButton _startButton{};
    PauseButton _pauseButton{};

    Points _points{};

    bool over{false};

    void setup();
    void update();
    void render();
    void setupMapData();

    void clickForCreateTower(Position positionClick);

    void runWave();

    void clickForExit(Position positionClick, GLFWwindow *window);
    void clickForStart(Position positionClick);
    void clickForPause(Position positionClick);

    void loadGameOver();

    bool isPause = true;
};
