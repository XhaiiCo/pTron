#include "Game.h"
#include <iostream>

#include "GameLaunch.h"

Game::Game(){}

Game::~Game()
{
     delete gameContext ;
     delete player1 ;
     delete player2 ;
}


Game::Game(const Game& other)
{
    delete gameContext ;
    delete player1 ;
    delete player2 ;


    this->gameContext = other.gameContext ;
    this->player1 = other.player1 ;
    this->player2 = other.player2 ;
}

Game& Game::operator=(const Game& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    delete gameContext ;
    delete player1 ;
    delete player2 ;

    this->gameContext = rhs.gameContext ;
    this->player1 = rhs.player1 ;
    this->player2 = rhs.player2 ;

    return *this;
}

void Game::run(){
    this->initGameContext() ;

    //Get the stateManager and window from gameContext
    StateManager* stateManager = this->gameContext->getStateManager() ;
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    //Create the lauch game view and add it to the gameContext
    GameLaunch gameLauch(this->gameContext) ;
    stateManager->setState(&gameLauch) ;
    stateManager->getState()->init() ;

    //Main loop
    while(window->isOpen()){
        stateManager->getState()->processInput() ;
        stateManager->getState()->update() ;
        stateManager->getState()->draw() ;
    }
}

void Game::initGameContext(){

    //Calculates window's size
    int windowWidth = Playground::NB_COLUMN * (GamePlay::CASE_WIDTH + GamePlay::PADDING);
    int windowHeight = Playground::NB_LINE * (GamePlay::CASE_WIDTH + GamePlay::PADDING);

    //Create the window
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "The Tron Game!", sf::Style::Close);
    window->setFramerateLimit(12);

    //Create the stateManager
    StateManager stateManager = StateManager() ;

    //Create the players
    this->player1 = new Player() ;
    this->player2 = new Player() ;

    //Create the gameContext
    this->gameContext = new GameContext(stateManager, window, player1, player2, windowWidth, windowHeight) ;
}

