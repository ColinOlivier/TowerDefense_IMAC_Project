#pragma once

#include <unordered_map>
#include <glad/glad.h>
#include <iostream>

#include "utils.hpp"
#include "Map.hpp"

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RiGHT
};

struct MapDrawer
{
    std::unordered_map<std::pair<Tile, Direction>, GLuint> unmapTileSprite;
    void setupSprite(std::filesystem::path path);
    void displayMap(Map map);
};
