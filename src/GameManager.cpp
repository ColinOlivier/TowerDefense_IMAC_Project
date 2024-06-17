#include "GameManager.hpp"
#include "App.hpp"

GameManager::GameManager(App *app)
{
    _app = app;
}

void GameManager::setup()
{

    TextRenderer.ResetFont();
    TextRenderer.SetColor(SimpleText::TEXT_COLOR, SimpleText::Color::RED);
    TextRenderer.SetColorf(SimpleText::BACKGROUND_COLOR, 0.f, 0.f, 0.f, 0.f);
    TextRenderer.EnableBlending(true);

    setupMapData();

    _mapDrawer.loadSpriteTexture();

    _enemyHandler.setup();
    _towerHandler.setup();

    _startButton.setup();
    _exitButton.setup(); // à laisser à la fin
}

void GameManager::update()
{
    if (isPause == false)
    {
        _enemyHandler.update();
        _towerHandler.update();
    }
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

    _startButton.render();
    _exitButton.render(); // à garder à la fin
    std::string score_text{};
    std::stringstream stream{};

    stream << std::fixed << "Score: " << score;
    score_text = stream.str();

    TextRenderer.Label(score_text.c_str(), _app->_width / 2, _app->_height - 4, SimpleText::CENTER);
    TextRenderer.Render();
}

void GameManager::setupMapData()
{
    std::array<TileType, GRID_SIZE * GRID_SIZE> mapTileTypeArray = getMapTileTypeArray();
    _mapData = generateMap(mapTileTypeArray);
    // _mapData.setupGraph();
}

std::array<TileType, GRID_SIZE * GRID_SIZE> GameManager::getMapTileTypeArray()
{
    std::vector<std::string> idtFileContent = _idtReader.readTextFile(IDT_FILE_PATH);
    std::array<Color, GRID_SIZE * GRID_SIZE> mapColorsArray = _mapPNGReader.getMapColorsArray(make_absolute_path(MAP_PNG_PATH, true));

    std::unordered_map<Color, TileType> colorMap = _idtReader.getColorMap(idtFileContent);

    return _mapPNGReader.getMapTileTypeArray(mapColorsArray, colorMap);
}

void GameManager::addPoints(int reward)
{
    score += reward;
}

void GameManager::clickForCreateTower(Position positionClick)
{
    if (isPause == false)
    {
        if (_towerHandler.listTowers.size() >= 6)
        {
            return;
        }

    Tower newTower{_towerHandler.generateTower(TowerType::basicTower)};
    newTower.positionTower = positionClick;
    _towerHandler.listTowers.push_back(newTower);
    }
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
    if (
        -0.93 < positionClick.x * 2 - 1 &&
        positionClick.x * 2 - 1 < -0.73 &&
        0.80 < positionClick.y * (-2) + 1 &&
        positionClick.y * (-2) + 1 < 0.94)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void GameManager::clickForStart(Position positionClick)
{
    if (-0.80 < positionClick.x * 2 - 1 &&
        positionClick.x * 2 - 1 < 0.8 &&
        -0.20 < positionClick.y * (-2) + 1 &&
        positionClick.y * (-2) + 1 < 0.2)
    {
        _startButton.IsVisible = false;
        isPause = false;
    }
}