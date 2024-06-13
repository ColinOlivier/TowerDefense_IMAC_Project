#include "map/MapDataReader.hpp"
#include <img/img.hpp>
#include <iostream>

std::vector<TileType> MapDataReader::getVectorofTileType(std::string filename, const std::unordered_map<Color, TileType>& colorTileTypeMap)
{
    std::vector<TileType> vectorofTileType;
    img::Image image = img::load(make_absolute_path("images/map.png", true), 4, true);

    for (size_t i = 0; i < image.data_size(); i += 3)
    {

        Color currentPixelColor{
            (float)*(image.data() + i),
            (float)*(image.data() + i + 1),
            (float)*(image.data() + i + 2),
        };

        if (currentPixelColor == Color{ 0, 0, 0 })
        {
            vectorofTileType.push_back(TileType::GRASS);
            continue;
        }

        if (colorTileTypeMap.find(currentPixelColor) != colorTileTypeMap.end())
            vectorofTileType.push_back(colorTileTypeMap.at(currentPixelColor));
    }
    return vectorofTileType;
}
