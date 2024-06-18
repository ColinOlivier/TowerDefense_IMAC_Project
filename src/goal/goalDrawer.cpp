#include "goal/goalDrawer.hpp"
#include "App.hpp"

#include <glad/glad.h>
#include <img/img.hpp>

#include <sstream>
#include <iostream>

#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"

void GoalDrawer::loadGoalTexture()
{
    img::Image laurine{img::load(make_absolute_path("images/Characters/laurine.png", true), 4, true)};
    _textureLaurine = loadTexture(laurine);

    img::Image piano{img::load(make_absolute_path("images/piano.png", true), 4, true)};
    _texturePiano = loadTexture(piano);

    img::Image nolan{img::load(make_absolute_path("images/Characters/nolan.png", true), 4, true)};
    _textureNolan = loadTexture(nolan);
}

void GoalDrawer::setup()
{

    loadGoalTexture();
    // Setup the text renderer with blending enabled and white text color
}

void GoalDrawer::render(GoalDrawer &goal)
{
    drawGoal(goal);
}

void GoalDrawer::drawGoal(GoalDrawer &goal)
{
    GoalDrawer::positionGoal;
    glPushMatrix();
    glTranslatef(
        positionGoal.x = 0.95f,
        positionGoal.y = -0.88f,
        0.0f);
    glScalef(0.08f, 0.15f, 0.08f);
    if (goal.name == NameGoal::Laurine)
    {
        draw_quad_with_texture(_textureLaurine);
        glScalef(0.08f, 0.15f, 0.08f);
    }

    if (goal.name == NameGoal::Piano)
    {
        draw_quad_with_texture(_texturePiano);
        glScalef(0.2f, 0.015f, 0.2f);
    }

    if (goal.name == NameGoal::Nolan)
    {
        draw_quad_with_texture(_textureNolan);
        glScalef(0.08f, 0.15f, 0.08f);
    }

    glPopMatrix();
}
