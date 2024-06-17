#pragma once
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include "utils.hpp"

struct GameOver
{
    Position positionGameOver{0, 0};
    bool IsVisible = false;
    void loadGameOverTexture();
    GLuint _textureGameOver{};
    void setup();
    void update();
    void render();
};