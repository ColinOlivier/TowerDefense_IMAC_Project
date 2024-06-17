#include "map/MapData.hpp"

#include <iostream>

TileData& MapData::getTileDataAt(size_t x, size_t y) {
    return tilesArray[x + y * GRID_SIZE];
}

void MapData::setupGraph() {

}

MapData generateMap(std::array<TileType, GRID_SIZE* GRID_SIZE>& mapTileTypeArray) {
    MapData map{};

    for (size_t x = 0; x < GRID_SIZE; x++)
    {
        for (size_t y = 0; y < GRID_SIZE; y++)
        {
            map.getTileDataAt(x, y).pos = { (float)x, (float)y };
            map.getTileDataAt(x, y).type = mapTileTypeArray[x + y * GRID_SIZE];

            if (map.getTileDataAt(x, y).isPathType()) {

                // Check up tile
                if (y < GRID_SIZE - 1)
                    if (isPathType(mapTileTypeArray[(x + 0) + (y + 1) * GRID_SIZE]))
                        map.getTileDataAt(x, y).up_ptr = &map.getTileDataAt(x, y + 1);

                // Check right tile
                if (x < GRID_SIZE - 1)
                    if (isPathType(mapTileTypeArray[(x + 1) + (y + 0) * GRID_SIZE]))
                        map.getTileDataAt(x, y).right_ptr = &map.getTileDataAt(x + 1, y);

                // Check down tile
                if (y > 0)
                    if (isPathType(mapTileTypeArray[(x + 0) + (y - 1) * GRID_SIZE]))
                        map.getTileDataAt(x, y).down_ptr = &map.getTileDataAt(x, y - 1);

                // Check left tile
                if (x > 0)
                    if (isPathType(mapTileTypeArray[(x - 1) + (y + 0) * GRID_SIZE]))
                        map.getTileDataAt(x, y).left_ptr = &map.getTileDataAt(x - 1, y);
            }
        }
    }
    return map;
}
