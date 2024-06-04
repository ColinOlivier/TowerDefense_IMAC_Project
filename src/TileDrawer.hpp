#pragma once

#include <map>

#include "Tile.hpp"
#include "utils.hpp"
#include "GLHelpers.hpp"


struct TileDrawer
{
    std::map<TileType, std::filesystem::path> tileTypeTextureFileName{
        {TileType::GRASS, make_absolute_path("images/Tiles/tile_0050.png", true)},
        {TileType::PATH_CROSSROAD_DOWN, make_absolute_path("images/Tiles/tile_0052.png", true)},
        {TileType::IN, make_absolute_path("images/Tiles/tile_0051.png", true)},
        {TileType::OUT, make_absolute_path("images/Tiles/tile_0053.png", true)},
    };
    std::map<TileType, GLuint> tileTypeTextureID{};
    void drawTile(Tile tile);
    void drawTile(GLuint textureID, Position position);

    void setup();
};
