#pragma once

#include "utils.hpp"
#include <glad/glad.h>

enum class NameGoal
{
    Laurine,
    Piano,
    Nolan
};

struct GoalDrawer
{
    NameGoal name{};

    GLuint _textureLaurine{};
    GLuint _texturePiano{};
    GLuint _textureNolan{};

    Position positionGoal;

    void loadGoalTexture();
    void setup();
    void update();
    void render(GoalDrawer &goal);

    void drawGoal(GoalDrawer &goal);
};