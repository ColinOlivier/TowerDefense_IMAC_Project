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
    void update();
   // void render(Attack &attack);
    void render(std::vector<Attack> &attacksVector);
    std::vector<Attack> vecAttack{};
};