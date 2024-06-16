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
}