#include "towerDrawer.hpp"
#include "App.hpp"
#include "utils.hpp"
#include "GLHelpers.hpp"
#include "simpletext.h"
#include <sstream>
#include <GLFW/glfw3.h>

void TowerDrawer::loadTowerTexture()
{
    img::Image tour{img::load(make_absolute_path("images/Tour1.png", true), 4, true)};
    _texture = loadTexture(tour);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void TowerDrawer::setup()
{
    loadTowerTexture();
}

void TowerDrawer::update()
{
    render();
}

void TowerDrawer::render()
{
    for (size_t i = 0; i < vecTower.size(); i++)
    {
        glPushMatrix();
        glScalef(0.2f, 0.27f, 0.4f);
        draw_quad_with_texture(_texture);
        glPopMatrix();
    }
}
