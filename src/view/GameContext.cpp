#include "GameContext.h"

GameContext::GameContext(StateManager stateManager, sf::RenderWindow* window, float windowWidth, float windowHeight): windowWidth(windowWidth), windowHeight(windowHeight)
{
    this->stateManager = new StateManager(stateManager) ;
    this->window = window ;
}

GameContext::~GameContext()
{
    delete this->stateManager ;
    delete this->window ;
}

GameContext::GameContext(const GameContext& other)
{
    delete this->stateManager ;
    delete this->window ;

    this->stateManager = other.stateManager ;
    this->window = other.window ;
    this->windowWidth = other.windowWidth ;
    this->windowHeight = other.windowHeight ;

}

GameContext& GameContext::operator=(const GameContext& rhs)
{
    delete this->stateManager ;
    delete this->window ;

    if (this == &rhs) return *this; // handle self assignment

    this->stateManager = rhs.stateManager ;
    this->window = rhs.window ;
    this->windowWidth = rhs.windowWidth ;
    this->windowHeight = rhs.windowHeight ;

    return *this;
}
