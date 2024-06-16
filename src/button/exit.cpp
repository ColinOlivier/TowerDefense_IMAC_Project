#include "button/exit.hpp"
#include "App.hpp"
#include "utils.hpp"
#include "GLHelpers.hpp"
#include "simpletext.h"
#include <sstream>
#include <GLFW/glfw3.h>

void ExitButton::loadExitButtonTexture()
{
    img::Image exit{img::load(make_absolute_path("images/bouton_exit.png", true), 4, true)};
    _texture = loadTexture(exit);
}

void ExitButton::setup()
{
    loadExitButtonTexture();
}

void ExitButton::render()
{
    ExitButton::positionExitButton;
    glPushMatrix();
    glTranslatef(
        positionExitButton.x = - 0.83,
        positionExitButton.y = 0.91,
        0.0f);
    glScalef(0.3f, 0.15f, 0.3f);
    draw_quad_with_texture(_texture);
    glPopMatrix();
}