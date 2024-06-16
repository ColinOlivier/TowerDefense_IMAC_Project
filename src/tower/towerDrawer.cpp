#include "tower/towerDrawer.hpp"
#include "tower/towerHandler.hpp"
#include "App.hpp"
#include "utils.hpp"
#include "tower/tower.hpp"
#include "GLHelpers.hpp"
#include "simpletext.h"
#include <sstream>
#include <GLFW/glfw3.h>
#include "tower/attack/attackHandler.hpp"

void TowerDrawer::loadTowerTexture()
{
    img::Image tour{ img::load(make_absolute_path("images/Towers/Tour1.png", true), 4, true) };
    _texture = loadTexture(tour);
}

void TowerDrawer::setup()
{
    loadTowerTexture();
}

void TowerDrawer::drawTowers(std::vector<Tower>& towersVector) {
    for (size_t i = 0; i < towersVector.size(); i++)
    {
        glPushMatrix();
        glTranslatef(
            towersVector[i].positionTower.x * 2 - 1,
            towersVector[i].positionTower.y * (-2) + 1,
            0.0f);
        // glTranslatef(1.f, 1.f, 0.0f);
        glScalef(0.4f, 0.47f, 0.4f);
        draw_quad_with_texture(_texture);
        // Tower tower{};
        //  if(meter % (shootingRace*10)==0)
        //  {

        //  }
        //  meter ++;

        glPopMatrix();
    }
}

