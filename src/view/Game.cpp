#include "Game.h"
#include <iostream>

#include "GameLaunch.h"

Game::Game()
{
    this->windowWidth = Playground::NB_COLUMN * (GamePlay::CASE_WIDTH + GamePlay::PADDING);
    this->windowHeight = Playground::NB_LINE * (GamePlay::CASE_WIDTH + GamePlay::PADDING);

    this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "The Tron Game!");
    this->window->setFramerateLimit(12);

    stateManager = new StateManager() ;

    this->gameContext = new GameContext(this->stateManager, this->window, this->windowWidth, this->windowHeight) ;
}

Game::~Game()
{
    delete window ;
    delete stateManager ;
    delete gameContext ;
}


Game::Game(const Game& other)
{
    delete window ;
    delete stateManager ;
    delete gameContext ;

    this->windowWidth = other.windowWidth ;
    this->windowHeight = other.windowHeight;
    this->window = other.window ;
    this->stateManager = other.stateManager ;
}

Game& Game::operator=(const Game& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    delete window ;
    delete stateManager ;
    delete gameContext ;

    this->windowWidth = rhs.windowWidth ;
    this->windowHeight = rhs.windowHeight;
    this->window = rhs.window ;
    this->stateManager = rhs.stateManager ;

    return *this;
}

void Game::run(){
    GameLaunch gameLauch(stateManager, window, windowWidth, windowHeight) ;
    stateManager->setState(&gameLauch) ;
    stateManager->getState()->init() ;
    while(window->isOpen()){
        stateManager->getState()->processInput() ;
        stateManager->getState()->update() ;
        stateManager->getState()->draw() ;
    }
}

