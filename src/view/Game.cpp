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

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "The Tron Game!", sf::Style::Close);
    window->setFramerateLimit(12);

    StateManager stateManager = StateManager() ;

    int yStart = (int)(Playground::NB_LINE/2) ;
    this->player1 = new Player("D", 5, yStart) ;
    this->player2 = new Player("A", Playground::NB_COLUMN-5, yStart) ;

    this->gameContext = new GameContext(stateManager, window, player1, player2, windowWidth, windowHeight) ;
}

