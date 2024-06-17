#include "button/pause.hpp"
#include "App.hpp"
#include "utils.hpp"
#include "GLHelpers.hpp"
#include "simpletext.h"
#include <sstream>
#include <GLFW/glfw3.h>

void PauseButton::loadPauseButtonTexture()
{
    img::Image pause{img::load(make_absolute_path("images/Button/pause.png", true), 4, true)};
    _texture = loadTexture(pause);
}

void PauseButton::setup()
{
    loadPauseButtonTexture();
}

void PauseButton::render()
{
    PauseButton::positionPauseButton;
    glPushMatrix();
    glTranslatef(
        positionPauseButton.x = 0.83,
        positionPauseButton.y = 0.91,
        0.0f);
    glScalef(0.3f, 0.15f, 0.3f);
    draw_quad_with_texture(_texture);
    glPopMatrix();
}