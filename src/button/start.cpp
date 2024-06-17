#include "button/start.hpp"
#include "App.hpp"
#include "utils.hpp"
#include "GLHelpers.hpp"
#include "simpletext.h"
#include <sstream>
#include <GLFW/glfw3.h>

void StartButton::loadStartButtonTexture()
{
    img::Image exit{img::load(make_absolute_path("images/Button/start_fond.png", true), 4, true)};
    _texture = loadTexture(exit);
}

void StartButton::setup()
{
    loadStartButtonTexture();
}

void StartButton::render()
{
    if (IsVisible == true)
    {
        glPushMatrix();
        glTranslatef(
            positionStartButton.x,
            positionStartButton.y,
            0.0f);
        glScalef(2.5f, 2.5f, 2.5f);
        draw_quad_with_texture(_texture);
        glPopMatrix();
    }
}

void StartButton::update()
{
}