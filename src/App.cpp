#include "App.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>

#include <sstream>
#include <iostream>
#include <unordered_map>

#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"
#include "fileReader/IDTFileReader.hpp"
#include "fileReader/MapPNGReader.hpp"

#include "player/player.hpp"
#include "GameManager.hpp"

App::App() : _previousTime(0.0), _viewSize(2.0)
{
    // load what needs to be loaded here (for example textures)

    img::Image test{img::load(make_absolute_path("images/level.png", true), 4, true)};

    _texture = loadTexture(test);

    _gameManager = GameManager();
}

void App::setup()
{
    // Set the clear color to a nice blue
    glClearColor(0.0f, 0.0f, 0.4f, 1.0f);

    // Setup the text renderer with blending enabled and white text color
    TextRenderer.ResetFont();
    TextRenderer.SetColor(SimpleText::TEXT_COLOR, SimpleText::Color::WHITE);
    TextRenderer.SetColorf(SimpleText::BACKGROUND_COLOR, 0.f, 0.f, 0.f, 0.f);
    TextRenderer.EnableBlending(true);

    _gameManager.setup();
}

void App::update()
{
    _gameManager.update();
}

void App::render()
{
    // // Clear the color and depth buffers of the frame buffer
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glMatrixMode(GL_MODELVIEW);

    // glEnable(GL_BLEND);
    // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // glLoadIdentity();

    // // render exemple quad
    // glColor3f(1.0f, 0.0f, 0.0f);
    // glBegin(GL_QUADS);
    // glVertex2f(-0.5f, -0.5f);
    // glVertex2f(0.5f, -0.5f);
    // glVertex2f(0.5f, 0.5f);
    // glVertex2f(-0.5f, 0.5f);
    // glEnd();

    // // glPushMatrix();
    // // glScalef(0.8f, 0.8f, 0.8f);
    // // glRotatef(_angle, 0.0f, 0.0f, 1.0f);
    // // draw_quad_with_texture(_texture);
    // // glPopMatrix();

    // TextRenderer.Label("Example of using SimpleText library", _width / 2, 20, SimpleText::CENTER);

    // // Without set precision
    // // const std::string angle_label_text { "Angle: " + std::to_string(_angle) };
    // // With c++20 you can use std::format
    // // const std::string angle_label_text { std::format("Angle: {:.2f}", _angle) };

    // // Using stringstream to format the string with fixed precision
    // std::string angle_label_text{};
    // std::stringstream stream{};
    // stream << std::fixed << "Angle: " << std::setprecision(2) << _angle;
    // angle_label_text = stream.str();

    // TextRenderer.Label(angle_label_text.c_str(), _width / 2, _height - 4, SimpleText::CENTER);

    // TextRenderer.Render();
}

void App::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
    if (key == GLFW_KEY_W && action == GLFW_PRESS)
    {
        _gameManager.runWave();
    }
}

void App::mouse_button_callback(int button, int action, int mods)
{
    if (button != GLFW_MOUSE_BUTTON_LEFT || action != GLFW_PRESS)
    {
        return;
    }

    Position positionTower{_xPosCur / _width, _yPosCur / _height};
    _gameManager.clickForCreateTower(positionTower);
}

void App::scroll_callback(double /*xoffset*/, double /*yoffset*/)
{
}

void App::cursor_position_callback(double xpos, double ypos)
{
    _xPosCur = xpos;
    _yPosCur = ypos;
}

void App::size_callback(int width, int height)
{
    _width = width;
    _height = height;

    // make sure the viewport matches the new window dimensions
    glViewport(0, 0, _width, _height);

    const float aspectRatio{_width / (float)_height};

    // Change the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (aspectRatio > 1.0f)
    {
        glOrtho(-_viewSize / 2.0f * aspectRatio, _viewSize / 2.0f * aspectRatio, -_viewSize / 2.0f, _viewSize / 2.0f, -1.0f, 1.0f);
    }
    else
    {
        if (aspectRatio > 1.0f)
        {
            glOrtho(-_viewSize / 2.0f * aspectRatio, _viewSize / 2.0f * aspectRatio, -_viewSize / 2.0f, _viewSize / 2.0f, -1.0f, 1.0f);
        }
        else
        {
            glOrtho(-_viewSize / 2.0f, _viewSize / 2.0f, -_viewSize / 2.0f / aspectRatio, _viewSize / 2.0f / aspectRatio, -1.0f, 1.0f);
        }
    }
}
