#include "attackHandler.hpp"
#include "tower/towerHandler.hpp"

AttackHandler::AttackHandler(TowerHandler *towerHandler_ptr)
{
    towerHandler_ptr = _towerHandler_ptr;
}

void AttackHandler::setup()
{
    _attackDrawer.setup();
}

void AttackHandler::update() // à retravailler
{
    for (size_t i = 0; i < listAttacks.size(); i++)
    {
        listAttacks[i].move(0.009f);
        listAttacks[i].checkHit();
    }
}

void AttackHandler::render()
{
    _attackDrawer.drawAttacks(listAttacks);
}