#pragma once

#include "utils/utils.hpp"

#include "map/MapData.hpp"
#include "map/tile/TileData.hpp"

#include "fileReader/TextFileReader.hpp"

#include <fstream> 
#include <string>
#include <unordered_map>

struct IDTFileReader : TextFileReader
{
    std::unordered_map<std::string, TileType> _tileTypeNameMap{
        {"path", TileType::PATH},
        {"tower_base", TileType::TOWER_BASE},
        {"in", TileType::IN},
        {"out", TileType::OUT}
    };

    std::unordered_map<Color, TileType> getColorMap(const std::vector<std::string>& idtFileContent);
};
