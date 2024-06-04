#include "App.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>

#include <sstream>

#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"
#include "enemyDrawer.hpp"
#include "App.hpp"

void enemyDrawer::drawEnemy()
{
    img::Image test{img::load(make_absolute_path("images/milan.png", true), 4, true)};

    _texture = loadTexture(test);
}

void enemyDrawer::setup()
{

    drawEnemy();

    // Setup the text renderer with blending enabled and white text color
}

void enemyDrawer::update()
{

    render();
}

void enemyDrawer::render()
{
    // Clear the color and depth buffers of the frame buffer
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();

    // render exemple quad
    // glBegin(GL_QUADS);
    glScalef(0.2f, 0.4f, 0.2f);

    glPushMatrix();
    draw_quad_with_texture(_texture);
    glPopMatrix();
}
