#include "map/tile/TileDrawer.hpp"
#include "GLHelpers.hpp"


void TileDrawer::setup() {
    for (const auto& [key, value] : tileTypeTextureFileName) {
        img::Image image{ img::load(value, 4, true) };
        tileTypeTextureID[key] = loadTexture(image);
    }
}

void TileDrawer::drawTile(Tile tile) {
    drawTile(tileTypeTextureID[tile.type], tile.pos);
    // std::string tilePath{};
    // if (tile.type == TileType::GRASS)
    //     tilePath = "images/Tiles/tile_0050.png";
    // else
    //     tilePath = "images/Tiles/tile_0075.png";

    // img::Image test{ img::load(make_absolute_path(tilePath, true), 3, true) };

    // GLuint _texture = loadTexture(test);
    // glPushMatrix();
    // glScalef(0.2f, 0.2f, 0.2f);
    // glTranslatef(tile.pos.x - 4.5f, tile.pos.y - 4.5f, 0.f);
    // draw_quad_with_texture(_texture);
    // glPopMatrix();
}

void TileDrawer::drawTile(GLuint textureID, Position position) {
    glPushMatrix();
    glTranslatef(-1.f, -1.f, 0.f);
    glScalef(0.2f, 0.2f, 0.2f);
    glTranslatef(position.x, position.y, 0.f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex2f(0.f, 0.f);

    glTexCoord2d(1, 0);
    glVertex2f(1.f, 0.f);

    glTexCoord2d(1, 1);
    glVertex2f(1.f, 1.f);

    glTexCoord2d(0, 1);
    glVertex2f(0.f, 1.f);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}