#include "GamePlay.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameOver.h"

GamePlay::GamePlay(GameContext* gameContext): gameContext(gameContext){}

GamePlay::~GamePlay()
{
    //dtor
}

GamePlay::GamePlay(const GamePlay& other)
{
    //copy ctor
}

GamePlay& GamePlay::operator=(const GamePlay& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void GamePlay::init(){
    int yStart = (int)(Playground::NB_LINE/2) ;
    Player p1(this->gameContext->getNamePlayer1(), 5, yStart) ;
    Player p2(this->gameContext->getNamePlayer2(), Playground::NB_COLUMN-5, yStart) ;

    p1.setMainColor(Color(0, 255, 0));
    p1.setGodModeColor(Color(255, 255, 0)) ;
    p2.setMainColor(Color(0, 0, 255)) ;
    p2.setGodModeColor(Color(255, 255, 0)) ;

    p1.changeDirection(1,0) ;
    p2.changeDirection(-1, 0) ;

    Playground p(p1,p2) ;

    this->playground = p;
}

void GamePlay::processInput(){
    sf::Event event;
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    while(window->pollEvent(event)){
        if(event.type == sf::Event::Closed) window->close();
    }

    //PLAYER1
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) playground.changeDirectionPlayer(0, 0, -1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) playground.changeDirectionPlayer(0, 0, 1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) playground.changeDirectionPlayer(0, -1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) playground.changeDirectionPlayer(0, 1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if(playground.triggerGodModePlayer(0)){
            this->godModePlayer1Time.restart() ;
        }
    }


    //PLAYER 2
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) playground.changeDirectionPlayer(1, 0, -1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) playground.changeDirectionPlayer(1, 0, 1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) playground.changeDirectionPlayer(1, -1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) playground.changeDirectionPlayer(1, 1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
        if(playground.triggerGodModePlayer(1)){
            this->godModePlayer2Time.restart() ;
        }
    }
}

void GamePlay::update(){
    playground.movePlayers() ;

    player1Lost = playground.isPlayerHasLost(0) ;
    player2Lost = playground.isPlayerHasLost(1) ;

    if(player1Lost || player2Lost) this->nextState() ;

    if(playground.isPlayerInGodMode(0)){
            if(this->godModePlayer1Time.getElapsedTime().asSeconds() >= GOD_MODE_DURATION_IN_SECONDS)
                playground.disableGodModePlayer(0) ;
    }

    if(playground.isPlayerInGodMode(1)){
        if(this->godModePlayer2Time.getElapsedTime().asSeconds() >= GOD_MODE_DURATION_IN_SECONDS)
            playground.disableGodModePlayer(1) ;
    }

    playground.displayplayers() ;
}

void GamePlay::draw(){
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    window->clear() ;
    std::vector<std::vector<Case*>> Cases = this->playground.getCases() ;

    for(int i = 0 ; i < Cases.size() ; i++){
        for(int j = 0 ; j < Cases[i].size() ; j++){
            Player* p = Cases[i][j]->getPlayer() ;

            sf::RectangleShape rectangle(sf::Vector2f(CASE_WIDTH, CASE_WIDTH)) ;
            rectangle.setPosition(j*(CASE_WIDTH + PADDING ) , i*(CASE_WIDTH + PADDING)) ;
            rectangle.setOutlineColor(sf::Color(15,15,15)) ;
            rectangle.setOutlineThickness(1) ;

            Color color ;
            if(p == nullptr) color = this->emptyCaseColor ;
            else if(p->isGodMode()) color = p->getGodModeColor() ;
            else color = p->getMainColor() ;

            rectangle.setFillColor(sf::Color(color.getRed(), color.getGreen(), color.getBlue())) ;

            window->draw(rectangle) ;
        }
    }
    window->display();
}

void GamePlay::nextState(){
    StateManager* stateManager = this->gameContext->getStateManager() ;
    stateManager->setState(new GameOver(this->gameContext));
    stateManager->getState()->init() ;
}
