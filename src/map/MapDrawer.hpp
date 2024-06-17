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
        {0, "images/Map/tilesCustom/path_00.png"},
        {1, "images/Map/tilesCustom/path_01.png"},
        {2, "images/Map/tilesCustom/path_02.png"},
        {3, "images/Map/tilesCustom/path_03.png"},
        {4, "images/Map/tilesCustom/path_04.png"},
        {5, "images/Map/tilesCustom/path_05.png"},
        {6, "images/Map/tilesCustom/path_06.png"},
        {7, "images/Map/tilesCustom/path_07.png"},
        {8, "images/Map/tilesCustom/path_08.png"},
        {9, "images/Map/tilesCustom/path_09.png"},
        {10, "images/Map/tilesCustom/path_10.png"},
        {11, "images/Map/tilesCustom/path_11.png"},
        {12, "images/Map/tilesCustom/path_12.png"},
        {13, "images/Map/tilesCustom/path_13.png"},
        {14, "images/Map/tilesCustom/path_14.png"},
        {15, "images/Map/tilesCustom/path_15.png"}
    };
    std::unordered_map<int, GLuint> _connectionIndexTextureIDMap;
public:
    GLuint towerBaseTexture;

    void loadSpriteTexture();
    void displayMap(MapData& map);
    void displayTile(TileData tile, GLuint textureID, Position position);
};
