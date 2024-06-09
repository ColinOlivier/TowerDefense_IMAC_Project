#pragma once

#include "map/tile/TileData.hpp"
#include "fileReader/IDTReader.hpp"

struct MapDataReader
{
    std::vector<TileType> getVectorofTileType(std::string filename, std::vector<std::pair<Color, TileType>> correspTileType);
};
