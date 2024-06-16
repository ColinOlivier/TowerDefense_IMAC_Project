#include "GameManager.hpp"

// GameManager::GameManager() {
//     _mapData = createMapData();
// }

void GameManager::setup()
{
    setupMapData();

    _mapDrawer.loadSpriteTexture();

    _enemyHandler.setup();
    _towerHandler.setup();

    _exitButton.setup();
}

void GameManager::update()
{

    _enemyHandler.update();
    _towerHandler.update();

    render();
}

void GameManager::render()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    _mapDrawer.displayMap(_mapData);

    _enemyHandler.render();
    _towerHandler.render();
    _exitButton.render();
}

void GameManager::setupMapData()
{
    std::vector<std::string> idtFileContent = _idtReader.readTextFile(IDT_FILE_PATH);
    std::array<Color, GRID_SIZE * GRID_SIZE> mapColorsArray = _mapPNGReader.getMapColorsArray(make_absolute_path(MAP_PNG_PATH, true));

    std::unordered_map<Color, TileType> colorMap = _idtReader.getColorMap(idtFileContent);

    _mapData.setTilesArray(_mapPNGReader.getMapTileTypeArray(mapColorsArray, colorMap));
}

void GameManager::clickForCreateTower(Position positionClick)
{
    if (_towerHandler.listTowers.size() >= 6)
    {
        return;
    }

    Tower newTower{_towerHandler.generateTower(TowerType::basicTower)};
    newTower.positionTower = positionClick;
    _towerHandler.listTowers.push_back(newTower);
}

void GameManager::runWave()
{
    _enemyHandler.waveCount++;
    if (_enemyHandler.waveCount == 1)
    {
        _enemyHandler.listEnemies_second = _enemyHandler.generateEnemies(Name::Milan, 5, 0.15);
        _enemyHandler.positionQueue_second.push({0, 0.5});
        _enemyHandler.positionQueue_second.push({0., 0});
        _enemyHandler.positionQueue_second.push({-0.5, -0.25});
        _enemyHandler.positionQueue_second.push({0.25, 0.5});
        _enemyHandler.positionQueue_second.push({1.5, 1});
        _enemyHandler.positionQueue_second.push({-1, 0});
    }

    if (_enemyHandler.waveCount == 2)
    {
        _enemyHandler.listEnemies_third = _enemyHandler.generateEnemies(Name::Milan, 7, 0.1);
        _enemyHandler.positionQueue_third.push({0, 0.5});
        _enemyHandler.positionQueue_third.push({0., 0});
        _enemyHandler.positionQueue_third.push({-0.5, -0.25});
        _enemyHandler.positionQueue_third.push({0.25, 0.5});
        _enemyHandler.positionQueue_third.push({1.5, 1});
        _enemyHandler.positionQueue_third.push({-1, 0});
    }

    std::cout << _enemyHandler.waveCount << std::endl;
}

void GameManager::clickForExit(Position positionClick, GLFWwindow *window)
{
    std::cout << positionClick.x * 2 - 1 << " " << positionClick.y * (-2) + 1;
    if (
        -0.93 < positionClick.x * 2 - 1 &&
        positionClick.x * 2 - 1 < -0.73 &&
        0.80 < positionClick.y * (-2) + 1 &&
        positionClick.y * (-2) + 1 < 0.94)
    {
        glfwSetWindowShouldClose(window, true);
    }
}