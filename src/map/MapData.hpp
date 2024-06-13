#pragma once

#include <array>
#include "map/tile/TileData.hpp"

#define GRID_SIZE  10

struct MapData
{
    MapData();

    void setTilesArray(std::array<TileType, GRID_SIZE* GRID_SIZE> mapTileTypeArray);

    int gridSize{ GRID_SIZE * GRID_SIZE };
    int gridWeight{ GRID_SIZE };
    int gridHeight{ GRID_SIZE };
    std::array<TileData, GRID_SIZE* GRID_SIZE> tilesArray;

    // Tile* getTile(int x, int y);
};
