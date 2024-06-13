#include "map/tile/TileData.hpp"

int TileData::getConnectionIndex() const {
    int connectionIndex{ 0 };
    if (up_connection)
        connectionIndex += 1;
    if (rigth_connection)
        connectionIndex += 2;
    if (down_connection)
        connectionIndex += 4;
    if (left_connection)
        connectionIndex += 8;

    return connectionIndex;
}