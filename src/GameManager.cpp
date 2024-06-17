#include "GameManager.hpp"
#include "App.hpp"
#include <sstream>

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
    _points.setup();
    _enemyHandler.setup();
    _towerHandler.setup();

    _gameOver.setup();
    _win.setup();

    _startButton.setup();
    _pauseButton.setup();

    _exitButton.setup(); // à laisser à la fin
}

void GameManager::update()
{
    if (isPause == false)
    {
        _enemyHandler.update();
        _towerHandler.update();
    }
    for (int i{0}; i < _enemyHandler.listEnemies.size(); i++)
    {
        if (_enemyHandler.listEnemies[i].positionQueue.empty())
        {
            // std::cout << "game over" << std::endl;
            _gameOver.IsVisible = true;
            _gameOver.render();
        }
        if(_enemyHandler.listEnemies.size() == 0 && _enemyHandler.waveCount == 3)
        {
            _win.IsVisible = true;
            _win.render();
        }
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

    _points.render();

    _startButton.render();
    _pauseButton.render();
    _exitButton.render(); // à garder à la fin

    std::string score_text{};
    std::stringstream stream{};

    stream << std::fixed << " " << score;
    score_text = stream.str();

    TextRenderer.Label(score_text.c_str(), (_app->_width / 2) + 30, _app->_height / 16, SimpleText::CENTER);
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
        if (!_towerHandler.canBuild(positionClick))
        {
            return;
        }

        Tower newTower{_towerHandler.generateTower(TowerType::pineappleTower)};
        // std::cout << positionClick.x << "/" << positionClick.y << std::endl;

        if (score >= newTower.price)
        {
            positionClick.x = positionClick.x * 10;
            positionClick.y = positionClick.y * 10;

            positionClick.x = std::round(positionClick.x) + 0.5;
            positionClick.y = std::round(positionClick.y) + 0.5;

            // std::cout << positionClick.x << "/" << positionClick.y << std::endl;

            positionClick.x = positionClick.x / 10;
            positionClick.y = positionClick.y / 10;

            for (int i{0}; i < _towerHandler.listTowers.size(); i++)
            {
                if (_towerHandler.listTowers[i].positionTower == positionClick)
                    return; // deux tours ne peuvent pas se superposer
            }
            newTower.positionTower = positionClick;
            _towerHandler.listTowers.push_back(newTower);
            score -= newTower.price;
        }
    }
}

void GameManager::runWave()
{
    size_t countPos{_enemyHandler.positionQueue.size()};
    _enemyHandler.waveCount++;

    std::queue<Position> positionQueue{};

    positionQueue.push({0, 0.5});
    positionQueue.push({0., 0});

    if (_enemyHandler.waveCount == 1)
    {
        _enemyHandler.listEnemies = _enemyHandler.generateEnemies(Name::Milan, 1, 0.15, positionQueue);
    }

    if (_enemyHandler.waveCount == 2)
    {
        std::vector<Enemy> secondWave = _enemyHandler.generateEnemies(Name::Milan, 4, 0.15, positionQueue);
        _enemyHandler.listEnemies.insert(_enemyHandler.listEnemies.end(), secondWave.begin(), secondWave.end());
    }

    if (_enemyHandler.waveCount == 3)
    {

        std::vector<Enemy> thirdWave = _enemyHandler.generateEnemies(Name::Milan, 6, 0.1, positionQueue);
        _enemyHandler.listEnemies.insert(_enemyHandler.listEnemies.end(), thirdWave.begin(), thirdWave.end());
    }

    // std::cout << _enemyHandler.waveCount << std::endl;
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

void GameManager::clickForPause(Position positionClick)
{
    if (
        0.73 < positionClick.x * 2 - 1 &&
        positionClick.x * 2 - 1 < 0.93 &&
        0.84 < positionClick.y * (-2) + 1 &&
        positionClick.y * (-2) + 1 < 0.94)
    {
        isPause = true;
        _startButton.IsVisible = true;
    }
}
