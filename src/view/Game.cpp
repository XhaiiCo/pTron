#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Playground.h"
#include "Player.h"
#include "GamePlay.h"
#include "Menu.h"
#include "MainWindow.h"
#include "StateManager.h"
Game::Game()
{
}

Game::~Game()
{
    //dtor
}


void Game::run(){
    int windowWidth = Playground::NB_COLUMN * (GamePlay::CASE_WIDTH + GamePlay::PADDING);
    int windowHeight = Playground::NB_LINE * (GamePlay::CASE_WIDTH + GamePlay::PADDING);

    RenderWindow window(VideoMode(windowWidth, windowHeight), "The Tron Game!");
    window.setFramerateLimit(9);

    StateManager sm ;

    Menu menu(&sm, &window, windowWidth, windowHeight) ;
    sm.setState(&menu) ;
    sm.getState()->init() ;

    while(window.isOpen()){
        sm.getState()->processInput() ;
        sm.getState()->update() ;
        sm.getState()->draw() ;

    }
}

