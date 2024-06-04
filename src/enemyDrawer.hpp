#pragma once

#include <glad/glad.h>

#include "enemy.hpp"

struct EnemyDrawer
{
    GLuint _texture{};

    void loadEnemyTexture();
    void drawEnemy(Enemy &enemy);
    void setup();
    void update();
    void render();
};