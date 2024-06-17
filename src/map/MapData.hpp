#pragma once

#include <array>
#include "map/tile/TileData.hpp"

#include "graph/Graph.hpp"

#define GRID_SIZE  10

struct MapData
{
    std::array<TileData, GRID_SIZE* GRID_SIZE> tilesArray;

    Graph::Graph mapGraph;

    TileData* inTile_ptr{ nullptr };
    TileData* outTile_ptr{ nullptr };

    TileData& getTileDataAt(size_t x, size_t y);
    void setupGraph();
};

MapData generateMap(std::array<TileType, GRID_SIZE* GRID_SIZE>& mapTileTypeArray);
