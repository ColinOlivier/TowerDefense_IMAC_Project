#pragma once
#include <iostream>
#include <glad/glad.h>
#include <vector>
#include "tower/attack/attack.hpp"

struct AttackDrawer
{
    GLuint _texture{};

    void loadAttackTexture();
    void setup();

    void drawAttacks(std::vector<Attack>& attacksVector);
};