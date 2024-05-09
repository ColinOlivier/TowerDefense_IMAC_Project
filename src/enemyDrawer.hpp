#pragma once

#include <glad/glad.h>
#include <simpletext.h>

struct enemyDrawer
{
    void drawEnemy();
    void setup();
    void update();
    void render();

    GLuint _texture{};
};