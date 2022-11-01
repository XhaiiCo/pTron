#include "GameContext.h"

GameContext::GameContext(StateManager* stateManager, sf::RenderWindow* window, float windowWidth, float windowHeight): stateManager(stateManager), window(window), windowWidth(windowWidth), windowHeight(windowHeight)
{
    //ctor
}

GameContext::~GameContext()
{
}

GameContext::GameContext(const GameContext& other)
{
    this->stateManager = other.stateManager ;
    this->window = other.window ;
    this->windowWidth = other.windowWidth ;
    this->windowHeight = other.windowHeight ;

}

GameContext& GameContext::operator=(const GameContext& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->stateManager = rhs.stateManager ;
    this->window = rhs.window ;
    this->windowWidth = rhs.windowWidth ;
    this->windowHeight = rhs.windowHeight ;

    return *this;
}
