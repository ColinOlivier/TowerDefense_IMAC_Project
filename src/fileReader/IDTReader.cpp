#include "fileReader/IDTReader.hpp"
#include <regex>
#include <iostream> 

std::vector<std::string> IDTReader::readIDTFile(std::string filename) {

    std::ifstream inputFile(filename);

    // Check if the file is successfully opened 
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return {};
    }

    std::string line;
    std::vector<std::string> vectorLine;
    // Read each line of the file 
    while (getline(inputFile, line)) {
        vectorLine.push_back(line);
    }

    // Close the file 
    inputFile.close();

    return vectorLine;
}

std::vector<std::pair<Color, TileType>> IDTReader::getColorCorrespondence(std::string idtFilename) {

    std::vector<std::pair<Color, TileType>> colorCorrespondence;
    std::vector<std::string> fileLines = readIDTFile(idtFilename);
    for (std::string& line : fileLines)
    {
        // Check if line is empty => Skip
        if (line.empty())
            continue;

        // Check if line start with "#" => Skip
        if (line[0] == '#')
            continue;

        // Check if line start with "graph" => Stop
        if (line.find("graph") != std::string::npos)
            return colorCorrespondence;

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
        colorCorrespondence.push_back({ currentColor, getTileTypeByName(lineSplitSpace[0]) });
    }
    return colorCorrespondence;
}

TileType IDTReader::getTileTypeByName(std::string str) {
    if (str == "path")
        return TileType::PATH_CROSSROAD_DOWN;
    else if (str == "in")
        return TileType::IN;
    else if (str == "out")
        return TileType::OUT;
    else
        return TileType::GRASS;



}
