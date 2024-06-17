#pragma once
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include "utils.hpp"

struct Win
{
    Position positionWin{0,0};
    bool IsVisible = false;
    void loadWinTexture();
    GLuint _texture{};
    void setup();
    void update();
    void render();
};