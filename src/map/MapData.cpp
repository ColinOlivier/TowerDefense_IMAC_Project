#include "map/MapData.hpp"

#include <iostream>

TileData& MapData::getTileDataAt(size_t x, size_t y) {
    return tilesArray[x + y * GRID_SIZE];
}

void MapData::setupGraph() {
    TileData& visitTile = *inTile_ptr;
    std::cout << (int)visitTile.type << std::endl;
    // while (&visitTile != outTile_ptr)
    // {
    //     /* code */
    // }

}

MapData generateMap(std::array<TileType, GRID_SIZE* GRID_SIZE>& mapTileTypeArray) {
    MapData map{};

    for (size_t x = 0; x < GRID_SIZE; x++)
    {
        for (size_t y = 0; y < GRID_SIZE; y++)
        {
            map.getTileDataAt(x, y).pos = { (float)x, (float)y };
            map.getTileDataAt(x, y).type = mapTileTypeArray[x + y * GRID_SIZE];

            if (mapTileTypeArray[x + y * GRID_SIZE] == TileType::IN)
                map.inTile_ptr = &map.getTileDataAt(x, y);

            if (mapTileTypeArray[x + y * GRID_SIZE] == TileType::OUT)
                map.outTile_ptr = &map.getTileDataAt(x, y);

            if (map.getTileDataAt(x, y).type == TileType::PATH) {

                // Check up tile
                if (y < GRID_SIZE - 1)
                    if (mapTileTypeArray[(x + 0) + (y + 1) * GRID_SIZE] == TileType::PATH)
                        map.getTileDataAt(x, y).up_ptr = &map.getTileDataAt(x, y + 1);

                // Check right tile
                if (x < GRID_SIZE - 1)
                    if (mapTileTypeArray[(x + 1) + (y + 0) * GRID_SIZE] == TileType::PATH)
                        map.getTileDataAt(x, y).right_ptr = &map.getTileDataAt(x + 1, y);

                // Check down tile
                if (y > 0)
                    if (mapTileTypeArray[(x + 0) + (y - 1) * GRID_SIZE] == TileType::PATH)
                        map.getTileDataAt(x, y).down_ptr = &map.getTileDataAt(x, y - 1);

                // Check left tile
                if (x > 0)
                    if (mapTileTypeArray[(x - 1) + (y + 0) * GRID_SIZE] == TileType::PATH)
                        map.getTileDataAt(x, y).left_ptr = &map.getTileDataAt(x - 1, y);
            }
        }
    }
    return map;
}
