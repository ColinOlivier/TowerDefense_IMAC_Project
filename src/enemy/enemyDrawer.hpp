#pragma once

#include <glad/glad.h>

#include "enemy/enemy.hpp"

struct EnemyDrawer
{
    GLuint _textureMilan{};
    GLuint _textureGuimiel{};
    GLuint _textureElea{};

    void loadEnemyTexture();
    void drawEnemy(Enemy &enemy);
    void setup();
    void update();
    void render();
};