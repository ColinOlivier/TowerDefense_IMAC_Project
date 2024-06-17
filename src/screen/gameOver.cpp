#include "screen/gameOver.hpp"
#include "App.hpp"
#include "utils.hpp"
#include "GLHelpers.hpp"
#include "simpletext.h"
#include <sstream>
#include <GLFW/glfw3.h>

void GameOver::loadGameOverTexture()
{
    img::Image gameOver{img::load(make_absolute_path("images/Button/loose.png", true), 4, true)};
    _textureGameOver = loadTexture(gameOver);
}

void GameOver::setup()
{
    loadGameOverTexture();
}

void GameOver::render()
{
    if (IsVisible == true)
    {
        glPushMatrix();
        glTranslatef(
            GLfloat(positionGameOver.x),
            GLfloat(positionGameOver.y),
            0.0f);
        glScalef(2.5f, 2.5f, 2.5f);
        draw_quad_with_texture(_textureGameOver);
        glPopMatrix();
    }
}

// void GameOver::update()
// {
//     if (IsVisible == true)
//     {
//         render();
//     }
// }