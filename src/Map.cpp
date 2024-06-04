#include "Map.hpp"

Tile* Map::getTile(int x, int y) {
    return tilesArray.data() + x + y * gridWeight;
}
