#pragma once
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include "utils.hpp"

struct Points
{
    Position positionPoints;
    void loadPointsTexture();
    GLuint _texturePoints{};
    void setup();
    void update();
    void render();
};