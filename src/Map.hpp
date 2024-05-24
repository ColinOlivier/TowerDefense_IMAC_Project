#pragma once

#include <array>
#include "Tile.hpp"

#define GRID_SIZE  10

struct Map
{
    int gridSize{ GRID_SIZE * GRID_SIZE };
    int gridWeight{ GRID_SIZE };
    int gridHeight{ GRID_SIZE };
    std::array<Tile, GRID_SIZE* GRID_SIZE> tilesArray;

    Tile* getTile(int x, int y);

    void setup();
    void update();
    void render();
};
