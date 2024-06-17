#pragma once
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include "utils.hpp"

struct ExitButton
{
    Position positionExitButton;
    void loadExitButtonTexture();
    GLuint _texture{};
    void setup();
    void update();
    void render();
};