#pragma once

#include<array>
#include "map/tile/TileData.hpp"
#include "utils/Color.hpp"

#include "fileReader/IDTFileReader.hpp"

#define GRID_SIZE  10

struct MapPNGReader
{
    std::array<Color, GRID_SIZE* GRID_SIZE> getMapColorsArray(std::filesystem::path filepath) const;
    std::array<TileType, GRID_SIZE* GRID_SIZE> getMapTileTypeArray(std::array<Color, GRID_SIZE* GRID_SIZE>& colorsArray, std::unordered_map<Color, TileType> colorMap);
};
