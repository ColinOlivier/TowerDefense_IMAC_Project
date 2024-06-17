#pragma once

#include "utils.hpp"

enum class TileType {
    GRASS,
    PATH,
    TOWER_BASE,
    IN,
    OUT
};


struct TileData
{
    Position pos;
    TileType type{ TileType::GRASS };

    TileData* up_ptr{ nullptr };
    TileData* right_ptr{ nullptr };
    TileData* down_ptr{ nullptr };
    TileData* left_ptr{ nullptr };

    int getConnectionIndex() const;
    bool isCorner() const;

};