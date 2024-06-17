#include "map/tile/TileData.hpp"

int TileData::getConnectionIndex() const {
    int connectionIndex{ 0 };
    if (up_ptr != nullptr)
        connectionIndex += 1;
    if (right_ptr != nullptr)
        connectionIndex += 2;
    if (down_ptr != nullptr)
        connectionIndex += 4;
    if (left_ptr != nullptr)
        connectionIndex += 8;

    return connectionIndex;
}

bool TileData::isCorner() const {
    if (type != TileType::PATH)
        return false;

    if (up_ptr != nullptr && right_ptr != nullptr)
        return true;

    if (right_ptr != nullptr && down_ptr != nullptr)
        return true;

    if (down_ptr != nullptr && left_ptr != nullptr)
        return true;

    if (left_ptr != nullptr && up_ptr != nullptr)
        return true;

    return false;
}

bool TileData::isPathType() {
    return type == TileType::PATH || type == TileType::IN || type == TileType::OUT;
}

bool isPathType(TileType type) {
    return type == TileType::PATH || type == TileType::IN || type == TileType::OUT;
}