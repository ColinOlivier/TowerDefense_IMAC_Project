#include "enemy/enemyDrawer.hpp"
#include "App.hpp"

#include <glad/glad.h>
#include <img/img.hpp>

#include <sstream>
#include <iostream>

#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"

void EnemyDrawer::loadEnemyTexture()
{
    img::Image test{img::load(make_absolute_path("images/milan.png", true), 4, true)};
    _texture = loadTexture(test);
}

void EnemyDrawer::setup()
{
    loadEnemyTexture();
    // Setup the text renderer with blending enabled and white text color
}

void EnemyDrawer::drawEnemy(Enemy &enemy)
{
    glPushMatrix();
    glTranslatef(
        enemy.position.x,
        enemy.position.y,
        0.f);
    glScalef(0.1f, 0.2f, 0.1f);
    draw_quad_with_texture(_texture);
    glPopMatrix();
}
