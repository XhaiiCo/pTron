#include "StateManager.h"

StateManager::StateManager()
{
    //ctor
}

StateManager::~StateManager()
{
    //dtor
}

StateManager::StateManager(const StateManager& other)
{
    //copy ctor
}

StateManager& StateManager::operator=(const StateManager& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
