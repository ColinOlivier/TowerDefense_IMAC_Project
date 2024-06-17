#pragma once
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include "utils.hpp"

struct StartButton
{
    Position positionStartButton{0,0};
    bool IsVisible = true;
    void loadStartButtonTexture();
    GLuint _texture{};
    void setup();
    void update();
    void render();
};