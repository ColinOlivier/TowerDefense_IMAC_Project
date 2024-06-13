#pragma once

#include "utils.hpp"

enum class TileType {
    GRASS,
    PATH,
    IN,
    OUT
};


struct TileData
{
    Position pos;
    TileType type{ TileType::GRASS };

    int getConnectionIndex() const;
    bool up_connection{ false };
    bool rigth_connection{ false };
    bool down_connection{ false };
    bool left_connection{ false };

};