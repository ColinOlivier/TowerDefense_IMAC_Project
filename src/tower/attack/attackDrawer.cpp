#include "App.hpp"
#include "tower/attack/attackDrawer.hpp"

#include <glad/glad.h>
#include <img/img.hpp>

#include <sstream>
#include <iostream>

#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"

void AttackDrawer::loadAttackTexture()
{
    img::Image test{img::load(make_absolute_path("images/attack.png", true), 4, true)};
    _texture = loadTexture(test);
}

void AttackDrawer::setup()
{
    loadAttackTexture();
    // Setup the text renderer with blending enabled and white text color
}

void AttackDrawer::render(std::vector<Attack> &attacksVector) // render
{
    for (size_t i = 0; i < attacksVector.size(); i++)
    {
        glPushMatrix();
        glTranslatef(
            attacksVector[i].positionAttack.x,
            attacksVector[i].positionAttack.y,
            0.f);
        glScalef(0.4f, 0.4f, 0.4f); // remise à l'échelle
        draw_quad_with_texture(_texture);
        glPopMatrix();
    }
}

// void AttackDrawer::render(Attack &attack) // render
// {
//     glPushMatrix();
//     glTranslatef(
//         attack.positionAttack.x,
//         attack.positionAttack.y,
//         0.f);
//     glScalef(0.4f, 0.4f, 0.4f); // remise à l'échelle
//     draw_quad_with_texture(_texture);
//     glPopMatrix();
// }