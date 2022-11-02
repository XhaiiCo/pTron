#include "GameState.h"
#include <SFML/System.hpp>

GameState::GameState()
{
    //ctor
}

GameState::~GameState()
{
    //dtor
}

GameState::GameState(const GameState& other)
{
    //copy ctor
}

GameState& GameState::operator=(const GameState& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
