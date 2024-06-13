#pragma once

#include "map/tile/TileData.hpp"
#include "fileReader/IDTFileReader.hpp"

struct MapDataReader
{
    std::vector<TileType> getVectorofTileType(std::string filename, const std::unordered_map<Color, TileType>& colorTileTypeMap);
};
