#include "Game.h"
#include <iostream>

Game::Game()
{
    this->windowWidth = Playground::NB_COLUMN * (GamePlay::CASE_WIDTH + GamePlay::PADDING);
    this->windowHeight = Playground::NB_LINE * (GamePlay::CASE_WIDTH + GamePlay::PADDING);

    this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "The Tron Game!");
    this->window->setFramerateLimit(12);

    stateManager = new StateManager() ;
}

Game::~Game()
{
    delete window ;
    delete stateManager ;
}


Game::Game(const Game& other)
{
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

    this->windowWidth = rhs.windowWidth ;
    this->windowHeight = rhs.windowHeight;
    this->window = rhs.window ;
    this->stateManager = rhs.stateManager ;

    return *this;
}

void Game::run(){
    Menu menu(stateManager, window, windowWidth, windowHeight) ;
    stateManager->setState(&menu) ;
    stateManager->getState()->init() ;

    while(window->isOpen()){
        stateManager->getState()->processInput() ;
        stateManager->getState()->update() ;
        stateManager->getState()->draw() ;
    }
}

