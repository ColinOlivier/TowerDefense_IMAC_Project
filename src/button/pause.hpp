#pragma once
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include "utils.hpp"

struct PauseButton
{
    Position positionPauseButton;
    void loadPauseButtonTexture();
    GLuint _texture{};
    void setup();
    void update();
    void render();
};