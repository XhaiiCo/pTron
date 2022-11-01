#include "Game.h"
#include <iostream>

#include "GameLaunch.h"

Game::Game(){}

Game::~Game()
{
     delete gameContext ;
}


Game::Game(const Game& other)
{
    delete gameContext ;

    this->gameContext = other.gameContext ;
}

Game& Game::operator=(const Game& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    delete gameContext ;

    this->gameContext = rhs.gameContext ;

    return *this;
}

void Game::run(){
    this->initGameContext() ;
    StateManager* stateManager = this->gameContext->getStateManager() ;
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    GameLaunch gameLauch(this->gameContext) ;
    stateManager->setState(&gameLauch) ;
    stateManager->getState()->init() ;

    while(window->isOpen()){
        stateManager->getState()->processInput() ;
        stateManager->getState()->update() ;
        stateManager->getState()->draw() ;
    }
}

void Game::initGameContext(){
    int windowWidth = Playground::NB_COLUMN * (GamePlay::CASE_WIDTH + GamePlay::PADDING);
    int windowHeight = Playground::NB_LINE * (GamePlay::CASE_WIDTH + GamePlay::PADDING);

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "The Tron Game!");
    window->setFramerateLimit(12);

    StateManager stateManager = StateManager() ;

    this->gameContext = new GameContext(stateManager, window, windowWidth, windowHeight) ;
}

