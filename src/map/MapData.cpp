#include "map/MapData.hpp"

MapData::MapData() {}

void MapData::setTilesArray(std::array<TileType, GRID_SIZE* GRID_SIZE> mapTileTypeArray) {
    for (size_t x = 0; x < GRID_SIZE; x++)
    {
        for (size_t y = 0; y < GRID_SIZE; y++)
        {
            TileData tile{};
            tile.pos = { (float)x, (float)y };
            tile.type = mapTileTypeArray[x + y * GRID_SIZE];

            if (mapTileTypeArray[x + y * GRID_SIZE] == TileType::PATH)
            {
                // Check up tile
                if (y < GRID_SIZE - 1)
                    if (mapTileTypeArray[(x + 0) + (y + 1) * GRID_SIZE] == TileType::PATH)
                        tile.up_connection = true;

                // Check right tile
                if (x < GRID_SIZE - 1)
                    if (mapTileTypeArray[(x + 1) + (y + 0) * GRID_SIZE] == TileType::PATH)
                        tile.rigth_connection = true;

                // Check down tile
                if (y > 0)
                    if (mapTileTypeArray[(x + 0) + (y - 1) * GRID_SIZE] == TileType::PATH)
                        tile.down_connection = true;

                // Check left tile
                if (x > 0)
                    if (mapTileTypeArray[(x - 1) + (y + 0) * GRID_SIZE] == TileType::PATH)
                        tile.left_connection = true;
            }

            tilesArray[x + y * GRID_SIZE] = tile;
        }
    }
}
