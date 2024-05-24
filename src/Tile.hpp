#pragma once

#include "utils.hpp"

enum class TileType {
    GRASS,
    PATH,
    IN,
    OUT
};


struct Tile
{
    Position pos;
    TileType type{ TileType::GRASS };
};