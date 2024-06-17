#include "map/MapDrawer.hpp"

#include <img/img.hpp>
#include "GLHelpers.hpp"

void MapDrawer::displayMap(MapData& map) {
    for (size_t x = 0; x < GRID_SIZE; x++)
    {
        for (size_t y = 0; y < GRID_SIZE; y++)
        {
            TileData tile = map.tilesArray[x + y * GRID_SIZE];
            if (tile.type == TileType::PATH || tile.type == TileType::IN || tile.type == TileType::OUT)
                displayTile(tile, _connectionIndexTextureIDMap.at(tile.getConnectionIndex()), { (float)x, (float)y });
            else if (tile.type == TileType::GRASS)
                displayTile(tile, _connectionIndexTextureIDMap.at(0), { (float)x, (float)y });
            else if (tile.type == TileType::TOWER_BASE)
                displayTile(tile, towerBaseTexture, { (float)x, (float)y });
        }
    }
}

void MapDrawer::loadSpriteTexture() {
    for (const std::pair<int, std::string>& connectionIndexFilePath : connectionIndexFilePathMap)
    {
        img::Image texture{ img::load(make_absolute_path(connectionIndexFilePath.second, true), 4, true) };
        GLuint textureId = loadTexture(texture);

        if (_connectionIndexTextureIDMap.find(connectionIndexFilePath.first) == _connectionIndexTextureIDMap.end()) {
            _connectionIndexTextureIDMap.insert({ connectionIndexFilePath.first, textureId });
        }
    }

    img::Image texture{ img::load(make_absolute_path("images/Map/tilesCustom/base_00.png", true), 4, true) };
    towerBaseTexture = loadTexture(texture);
}

void MapDrawer::displayTile(TileData tile, GLuint textureID, Position position) {
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


