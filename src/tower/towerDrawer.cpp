#include "tower/towerDrawer.hpp"
#include "tower/towerHandler.hpp"
#include "App.hpp"
#include "utils.hpp"
#include "tower/tower.hpp"
#include "GLHelpers.hpp"
#include "simpletext.h"
#include <sstream>
#include <GLFW/glfw3.h>

void TowerDrawer::loadTowerTexture()
{
    img::Image tour{img::load(make_absolute_path("images/Tour1.png", true), 4, true)};
    _texture = loadTexture(tour);
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
    // generateTower(TowerType basicTower);
    for (size_t i = 0; i < vecTower.size(); i++)
    {
        glPushMatrix();
        glTranslatef(
            vecTower[i].positionTower.x * 2 - 1,
            vecTower[i].positionTower.y * (-2) + 1,
            0.0f);
        // glTranslatef(1.f, 1.f, 0.0f);
        glScalef(0.4f, 0.47f, 0.4f);
        vecTower[i].shot();
        draw_quad_with_texture(_texture);
        glPopMatrix();
    }
}
