#include "StateManager.h"
#include <iostream>

StateManager::StateManager()
{
    this->state = nullptr ;
}

StateManager::~StateManager()
{
    delete this->state ;
}

StateManager::StateManager(const StateManager& other)
{

    this->state = other.state->clone() ;
}

StateManager& StateManager::operator=(const StateManager& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    delete this->state ;
    this->state = rhs.state->clone() ;

    return *this;
}


void StateManager::setState(GameState* state){
    if(this->state != nullptr)
        delete this->state ;

    this->state = state->clone() ;
}

GameState* StateManager::getState(){
    return this->state ;
}
