#include "map/MapData.hpp"

Tile* MapData::getTile(int x, int y) {
    return tilesArray.data() + x + y * gridWeight;
}
