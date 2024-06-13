#pragma once
#include <iostream>
#include <vector>
#include "tower/tower.hpp"
#include <glad/glad.h>


struct TowerDrawer
{
    void loadTowerTexture();
    void drawTowers(std::vector<Tower>& towersVector);

    void setup();
    void update();
    void render();

    GLuint _texture{};
    std::vector<Tower> vecTower{}; // Suppr
};