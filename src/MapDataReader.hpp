#pragma once

#include "Tile.hpp"
#include "IDTReader.hpp"

struct MapDataReader
{
    std::vector<TileType> getVectorofTileType(std::string filename, std::vector<std::pair<Color, TileType>> correspTileType);
};
