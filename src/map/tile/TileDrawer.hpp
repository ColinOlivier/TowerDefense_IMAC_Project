#pragma once

#include <unordered_map>

#include "map/tile/TileData.hpp"
#include "utils.hpp"
#include "GLHelpers.hpp"


struct TileDrawer
{
    std::unordered_map<TileType, std::filesystem::path> tileTypeTextureFileName{
        {TileType::GRASS, make_absolute_path("images/Tiles/tile_0050.png", true)},
        {TileType::PATH, make_absolute_path("images/Tiles/tile_0052.png", true)},
        {TileType::IN, make_absolute_path("images/Tiles/tile_0051.png", true)},
        {TileType::OUT, make_absolute_path("images/Tiles/tile_0053.png", true)},
    };
    std::unordered_map<TileType, GLuint> tileTypeTextureID{};
    void drawTile(TileData tile);
    void drawTile(GLuint textureID, Position position);

    void setup();
};
