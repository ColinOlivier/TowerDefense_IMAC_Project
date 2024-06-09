#pragma once

#include "map/MapData.hpp"
#include "map/tile/TileData.hpp"

#include <fstream> 
#include <vector> 
#include <string>
#include <unordered_map>

struct Color {
    float _R{ 0.f };
    float _G{ 0.f };
    float _B{ 0.f };

    bool operator==(const Color&) const = default;
};


struct IDTReader
{
    std::vector<std::string> readIDTFile(std::string idtFilename);
    std::vector<std::pair<Color, TileType>> getColorCorrespondence(std::string idtFilename);
    TileType getTileTypeByName(std::string str);
};
