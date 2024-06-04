#include <img/img.hpp>
#include "MapDrawer.hpp"

void MapDrawer::displayMap(Map map) {
    //
}

void MapDrawer::setupSprite(std::filesystem::path tileMapPath) {
    img::Image tileMap{ img::load(tileMapPath, 3, true) };

}
