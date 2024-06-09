#include <img/img.hpp>
#include "map/MapDrawer.hpp"

void MapDrawer::displayMap(MapData map) {
    //
}

void MapDrawer::setupSprite(std::filesystem::path tileMapPath) {
    img::Image tileMap{ img::load(tileMapPath, 3, true) };

}
