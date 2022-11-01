#include "GameSettings.h"

GameSettings::GameSettings()
{
    //ctor
}

GameSettings::~GameSettings()
{
    //dtor
}

GameSettings::GameSettings(const GameSettings& other)
{
    //copy ctor
}

GameSettings& GameSettings::operator=(const GameSettings& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
