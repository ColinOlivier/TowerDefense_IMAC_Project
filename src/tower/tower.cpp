#include "tower/tower.hpp"
#include "tower/attack/attackHandler.hpp"
#include "tower/attack/attackDrawer.hpp"
#include "tower/attack/attack.hpp"

Attack Tower::shot()
{
    AttackHandler attackHandler;
    attackHandler.setup();
    // tire sur les ennemis 
    attackHandler.update();
    attackHandler.render();
}

void Tower::render()
{
}

void Tower::setup()
{
}

void Tower::update()
{
}
