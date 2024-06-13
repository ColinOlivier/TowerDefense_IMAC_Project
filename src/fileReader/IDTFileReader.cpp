#include "fileReader/IDTFileReader.hpp"
#include <iostream> 

std::unordered_map<Color, TileType> IDTFileReader::getColorMap(const std::vector<std::string>& idtFileContent) {
    std::unordered_map<Color, TileType> colorMap;

    for (std::string line : idtFileContent)
    {
        // Check if line is empty => Skip
        if (line.empty())
            continue;

        // Check if line start with "#" => Skip
        if (line[0] == '#')
            continue;

        // Check if line start with "graph" => Stop
        if (line.find("graph") != std::string::npos)
            return colorMap;

        std::vector<std::string> lineSplitSpace;
        std::string::iterator lastSpace{ line.begin() };
        while (std::find(lastSpace, line.end(), ' ') != line.end())
        {
            lineSplitSpace.push_back(std::string(lastSpace, std::find(lastSpace, line.end(), ' ')));
            lastSpace = std::find(lastSpace, line.end(), ' ') + 1;
        }
        lineSplitSpace.push_back(std::string(lastSpace, std::find(lastSpace, line.end(), ' ')));

        if (lineSplitSpace.size() != 4)
            continue;

        Color currentColor = Color{
            std::stof(lineSplitSpace[1]),
            std::stof(lineSplitSpace[2]),
            std::stof(lineSplitSpace[3])
        };

        if (colorMap.find(currentColor) == colorMap.end()) {
            TileType tileType{ TileType::GRASS };
            if (_tileTypeNameMap.find(lineSplitSpace[0]) != _tileTypeNameMap.end())
                tileType = _tileTypeNameMap.at(lineSplitSpace[0]);

            colorMap.insert({ currentColor, tileType });
        }
    }
    return colorMap;
}