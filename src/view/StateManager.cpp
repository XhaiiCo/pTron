#include "StateManager.h"

StateManager::StateManager()
{
    //ctor
}

StateManager::~StateManager()
{
    //delete this->state ;
}

StateManager::StateManager(const StateManager& other)
{
    //delete this->state ;

    this->state = other.state ;
}

StateManager& StateManager::operator=(const StateManager& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    //delete this->state ;
    this->state = rhs.state ;

    return *this;
}


void StateManager::setState(GameState* state){
    //delete this->state ;
    this->state = state->clone() ;
}

GameState* StateManager::getState(){
    return this->state ;
}
