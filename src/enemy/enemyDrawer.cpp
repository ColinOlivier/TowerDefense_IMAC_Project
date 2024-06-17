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
    img::Image milan{img::load(make_absolute_path("images/Characters/milan.png", true), 4, true)};
    _textureMilan = loadTexture(milan);

    img::Image elea{img::load(make_absolute_path("images/Characters/elea.png", true), 4, true)};
    _textureElea = loadTexture(elea);

    img::Image guimiel{img::load(make_absolute_path("images/Characters/guimiel.png", true), 4, true)};
    _textureGuimiel = loadTexture(guimiel);
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
    glScalef(0.08f, 0.15f, 0.08f);
    if (enemy.name == Name::Milan)
        draw_quad_with_texture(_textureMilan);

    if (enemy.name == Name::Elea)
        draw_quad_with_texture(_textureElea);

    if (enemy.name == Name::Guimiel)
        draw_quad_with_texture(_textureGuimiel);
    glPopMatrix();
}
