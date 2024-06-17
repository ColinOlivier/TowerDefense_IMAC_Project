#include "screen/win.hpp"
#include "App.hpp"
#include "utils.hpp"
#include "GLHelpers.hpp"
#include "simpletext.h"
#include <sstream>
#include <GLFW/glfw3.h>

void Win::loadWinTexture()
{
    img::Image exit{img::load(make_absolute_path("images/Button/win.png", true), 4, true)};
    _texture = loadTexture(exit);
}

void Win::setup()
{
    loadWinTexture();
}

void Win::render()
{
    if (IsVisible == true)
    {
        glPushMatrix();
        glTranslatef(
            positionWin.x,
            positionWin.y,
            0.0f);
        glScalef(2.5f, 2.5f, 2.5f);
        draw_quad_with_texture(_texture);
        glPopMatrix();
    }
}