#include "points/points.hpp"
#include "App.hpp"
#include "utils.hpp"
#include "GLHelpers.hpp"
#include "simpletext.h"
#include <sstream>
#include <GLFW/glfw3.h>

void Points::loadPointsTexture()
{
    img::Image points{img::load(make_absolute_path("images/sous.png", true), 4, true)};
    _texturePoints = loadTexture(points);
}

void Points::setup()
{
    loadPointsTexture();
}

void Points::render()
{
    Points::positionPoints;
    glPushMatrix();
    glTranslatef(
        positionPoints.x = 0.f,
        positionPoints.y = 0.9f,
        0.0f);
    glScalef(0.075f, 0.075f, 0.075f);
    draw_quad_with_texture(_texturePoints);
    glPopMatrix();
}