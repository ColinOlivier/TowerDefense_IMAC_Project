#include "App.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>

#include <sstream>
#include <iostream>

#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"
#include "Tile.hpp"
#include "IDTReader.hpp"
#include "MapDataReader.hpp"

#include "towerDrawer.hpp"
#include "towerHandler.hpp"
#include "tower.hpp"

TowerDrawer drawTower{};
TowerHandler towerHandler{};

App::App() : _previousTime(0.0), _viewSize(2.0)
{
    // load what needs to be loaded here (for example textures)

    img::Image test{img::load(make_absolute_path("images/level.png", true), 4, true)};

    _texture = loadTexture(test);

    enemyHandler = EnemyHandler();
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

    IDTReader idtReader;
    MapDataReader mapDataReader;

    std::vector<std::pair<Color, TileType>> colorCorrespondences = idtReader.getColorCorrespondence("../../data/map.idt");
    vecTileType = mapDataReader.getVectorofTileType("../../images/map.png", colorCorrespondences);

    tileDrawer.setup();
    drawTower.setup();
    enemyHandler.setup();
}

void App::update()
{

    const double currentTime{glfwGetTime()};
    const double elapsedTime{currentTime - _previousTime};
    _previousTime = currentTime;

    _angle += 10.0f * elapsedTime;
    // float time{(float)glfwGetTime()};

    // // _angle = std::fmod(_angle, 360.0f);
    enemyHandler.update();

    render();
}

void App::render()
{
    // Clear the color and depth buffers of the frame buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glLoadIdentity();

    // render exemple quad
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    // glPushMatrix();
    // glScalef(0.8f, 0.8f, 0.8f);
    // glRotatef(_angle, 0.0f, 0.0f, 1.0f);
    // draw_quad_with_texture(_texture);
    // glPopMatrix();

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            tileDrawer.drawTile(Tile{{(float)i, (float)j}, vecTileType[j * 10 + i]});
        }
    }

    drawTower.render();

    TextRenderer.Label("Example of using SimpleText library", _width / 2, 20, SimpleText::CENTER);

    // Without set precision
    // const std::string angle_label_text { "Angle: " + std::to_string(_angle) };
    // With c++20 you can use std::format
    // const std::string angle_label_text { std::format("Angle: {:.2f}", _angle) };

    // Using stringstream to format the string with fixed precision
    std::string angle_label_text{};
    std::stringstream stream{};
    stream << std::fixed << "Angle: " << std::setprecision(2) << _angle;
    angle_label_text = stream.str();

    TextRenderer.Label(angle_label_text.c_str(), _width / 2, _height - 4, SimpleText::CENTER);

    TextRenderer.Render();

    enemyHandler.render();
}

void App::key_callback(int /*key*/, int /*scancode*/, int /*action*/, int /*mods*/)
{
}

void App::mouse_button_callback(int button, int action, int mods)
{
    if (button != GLFW_MOUSE_BUTTON_LEFT || action != GLFW_PRESS)
    {
        return;
    }
    if (drawTower.vecTower.size() >= 6)
    {
        return;
    }
    Position positionTower;
    positionTower.x = _xPosCur / _width;
    positionTower.y = _yPosCur / _height;
    // std::cout << positionTower.x << " ; " << positionTower.y << std::endl;
    std::cout << (_xPosCur / _width) * 10 << " ; " << (_yPosCur / _height) * 10 << std::endl;

    Tower newTower{};
    newTower.positionTower = positionTower;
    drawTower.vecTower.push_back(newTower);
}

void App::scroll_callback(double /*xoffset*/, double /*yoffset*/)
{
}

void App::cursor_position_callback(double /*xpos*/, double /*ypos*/)
{
}

void App::size_callback(int width, int height)
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
