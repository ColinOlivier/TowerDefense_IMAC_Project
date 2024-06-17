#pragma once

#include <glad/glad.h>
#include <simpletext.h>
#include "GameManager.hpp"
#include "GLFW/glfw3.h"

class App
{
public:
    App();

    void setup();
    void update();

    // GLFW callbacks binding
    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
    void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
    void scroll_callback(double xoffset, double yoffset);
    void cursor_position_callback(double xpos, double ypos);
    void size_callback(int width, int height);
    double _xPosCur, _yPosCur;

    int _width{};
    int _height{};

private:
    void render();

    double _previousTime{};
    float _viewSize{};

    // Add your variables here
    GLuint _texture{};
    float _angle{};

    SimpleText TextRenderer{};

    GameManager _gameManager{this};
};