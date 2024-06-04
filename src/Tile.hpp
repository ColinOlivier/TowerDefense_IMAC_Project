#pragma once

#include "utils.hpp"

enum class TileType {
    GRASS,
    PATH_STAIGHT_V,
    PATH_STAIGHT_H,
    PATH_TURN_UR, // UP RIGHT
    PATH_TURN_UL, // UP LEFT
    PATH_TURN_DR, // DOWN RIGHT
    PATH_TURN_DL, // DOWN LEFT
    PATH_CROSSROAD_UP,
    PATH_CROSSROAD_DOWN,
    PATH_CROSSROAD_RIGHT,
    PATH_CROSSROAD_LEFT,
    PATH_CROSSROAD_FULL,
    IN,
    OUT
};


struct Tile
{
    Position pos;
    TileType type{ TileType::GRASS };
};