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

    img::Image tour{img::load(make_absolute_path("images/Towers/Tour1.png", true), 4, true)};
    _texture1 = loadTexture(tour);
    tour = {img::load(make_absolute_path("images/Towers/tour_ananas.png", true), 4, true)};
    _texture2 = loadTexture(tour);
}

void TowerDrawer::setup()
{
    loadTowerTexture();
}

void TowerDrawer::drawTowers(std::vector<Tower> &towersVector)
{
    for (size_t i = 0; i < towersVector.size(); i++)
    {
        glPushMatrix();
        glTranslatef(
            towersVector[i].positionTower.x * 2 - 1,
            towersVector[i].positionTower.y * (-2) + 1,
            0.0f);
        // glTranslatef(1.f, 1.f, 0.0f);
        glScalef(0.3f, 0.35f, 0.3f);
        if (towersVector[i].type == TowerType::basicTower)
            draw_quad_with_texture(_texture1);
        if (towersVector[i].type == TowerType::pineappleTower)
            draw_quad_with_texture(_texture2);
        glPopMatrix();
    }
}
