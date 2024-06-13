#include "fileReader/MapPNGReader.hpp"
#include <img/img.hpp>

std::array<Color, GRID_SIZE* GRID_SIZE> MapPNGReader::getMapColorsArray(std::filesystem::path filepath) const {

    std::array<Color, GRID_SIZE* GRID_SIZE> mapColorsArray;

    img::Image image = img::load(filepath, 3, true);
    for (size_t i = 0; i < image.data_size() / 3; i++) {
        Color currentPixelColor{
            (float)*(image.data() + i * 3),
            (float)*(image.data() + i * 3 + 1),
            (float)*(image.data() + i * 3 + 2),
        };
        mapColorsArray[i] = currentPixelColor;
    }

    return mapColorsArray;
}

std::array<TileType, GRID_SIZE* GRID_SIZE> MapPNGReader::getMapTileTypeArray(std::array<Color, GRID_SIZE* GRID_SIZE>& colorsArray, std::unordered_map<Color, TileType> colorMap) {
    std::array<TileType, GRID_SIZE* GRID_SIZE> mapTileTypeArray{};
    for (size_t i = 0; i < colorsArray.size(); i++)
    {
        TileType tileType{ TileType::GRASS };

        if (colorMap.find(colorsArray[i]) != colorMap.end())
            tileType = colorMap.at(colorsArray[i]);

        mapTileTypeArray[i] = tileType;
    }
    return mapTileTypeArray;
}