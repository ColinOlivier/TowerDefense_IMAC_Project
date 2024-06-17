#pragma once
#include <iostream>
#include <vector>
#include "tower/tower.hpp"
#include <glad/glad.h>

struct TowerDrawer
{
    void loadTowerTexture();
    void drawTowers(std::vector<Tower> &towersVector);

    void setup();

    GLuint _texture1{};
    GLuint _texture2{};
};