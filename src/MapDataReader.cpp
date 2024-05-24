#include "MapDataReader.hpp"
#include <img/img.hpp>
#include <iostream>

std::vector<TileType> MapDataReader::getVectorofTileType(std::string filename, std::vector<std::pair<Color, TileType>> correspTileType) {
    std::vector<TileType> vectorofTileType;
    img::Image image = img::load(make_absolute_path("images/map.png", true), 3, true);

    for (size_t i = 0; i < image.data_size(); i += 3)
    {

        Color currentPixelColor{
            (int)*(image.data() + i),
            (int)*(image.data() + i + 1),
            (int)*(image.data() + i + 2),
        };

        if (currentPixelColor == Color{ 0, 0, 0 }) {
            vectorofTileType.push_back(TileType::GRASS);
            continue;
        }
        for (size_t i = 0; i < correspTileType.size(); i++)
        {
            if (correspTileType[i].first == currentPixelColor) {
                vectorofTileType.push_back(correspTileType[i].second);
                break;
            }
        }
    }
    return vectorofTileType;
}
