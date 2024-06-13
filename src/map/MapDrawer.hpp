#pragma once

#include <unordered_map>
#include <glad/glad.h>
#include <iostream>

#include "utils.hpp"
#include "map/MapData.hpp"

struct MapDrawer
{
private:
    std::unordered_map<int, std::string> connectionIndexFilePathMap{
        {0, "images/tilesCustom/path_00.png"},
        {1, "images/tilesCustom/path_01.png"},
        {2, "images/tilesCustom/path_02.png"},
        {3, "images/tilesCustom/path_03.png"},
        {4, "images/tilesCustom/path_04.png"},
        {5, "images/tilesCustom/path_05.png"},
        {6, "images/tilesCustom/path_06.png"},
        {7, "images/tilesCustom/path_07.png"},
        {8, "images/tilesCustom/path_08.png"},
        {9, "images/tilesCustom/path_09.png"},
        {10, "images/tilesCustom/path_10.png"},
        {11, "images/tilesCustom/path_11.png"},
        {12, "images/tilesCustom/path_12.png"},
        {13, "images/tilesCustom/path_13.png"},
        {14, "images/tilesCustom/path_14.png"},
        {15, "images/tilesCustom/path_15.png"}
    };
    std::unordered_map<int, GLuint> _connectionIndexTextureIDMap;
public:
    // std::unordered_map<std::pair<TileType, int>, GLuint> tileTypeSpriteTexMap;
    void loadSpriteTexture();
    void displayMap(MapData& map);
    void displayTile(TileData tile, GLuint textureID, Position position);
};
