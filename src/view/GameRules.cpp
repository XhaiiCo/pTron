#include "GameRules.h"

GameRules::GameRules(GameContext* gameContext)
{
    this->gameContext = gameContext ;
}

GameRules::~GameRules()
{
    //dtor
}

GameRules::GameRules(const GameRules& other)
{
    //copy ctor
}

GameRules& GameRules::operator=(const GameRules& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void GameRules::init(){}

void GameRules::processInput(){}

void GameRules::update(){}

void GameRules::draw(){}

void GameRules::nextState(){}

GameRules* GameRules::clone(){
    return new GameRules(*this) ;
}
