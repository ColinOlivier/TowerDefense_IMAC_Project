#pragma once
#include <iostream>
#include <vector>
#include "tower.hpp"
#include <glad/glad.h>


struct TowerDrawer
{
    void loadTowerTexture();
    void setup();
    void update();
    void render();

    GLuint _texture{};
    std::vector<Tower> vecTower{}; // Suppr
};