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
    Player* p1 = this->gameContext->getPlayer1() ;
    Player* p2 = this->gameContext->getPlayer2() ;

    p1->resetParams() ;
    p2->resetParams() ;

    int yStart = (int)(Playground::NB_LINE/2) ;
    p1->setX(5) ;
    p1->setY(yStart) ;

    p2->setX(Playground::NB_COLUMN-5) ;
    p2->setY(yStart) ;

    p1->changeDirection(1,0) ;
    p2->changeDirection(-1, 0) ;


    this->playground.init(p1, p2) ;
}

void GamePlay::processInput(){
    sf::Event event;
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    while(window->pollEvent(event)){
        if(event.type == sf::Event::Closed) window->close();
    }

    Player* p1 = this->gameContext->getPlayer1() ;
    Player* p2 = this->gameContext->getPlayer2() ;

    //PLAYER1
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) p1->changeDirection(0, -1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) p1->changeDirection(0, 1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) p1->changeDirection(-1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) p1->changeDirection(1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if(p1->triggerGodMode()){
            this->godModePlayer1Time.restart() ;
        }
    }


    //PLAYER 2
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) p2->changeDirection(0, -1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) p2->changeDirection(0, 1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) p2->changeDirection(-1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) p2->changeDirection(1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
        if(p2->triggerGodMode()){
            this->godModePlayer2Time.restart() ;
        }
    }
}

void GamePlay::update(){
    Player* p1 = this->gameContext->getPlayer1() ;
    Player* p2 = this->gameContext->getPlayer2() ;

    playground.movePlayers() ;

    player1Lost = playground.isPlayerHasLost(0) ;
    player2Lost = playground.isPlayerHasLost(1) ;

    if(player1Lost != player2Lost)//If there is a draw, we do not increase the scores
    {
        if(player1Lost) p2->increaseScore() ;
        if(player2Lost) p1->increaseScore() ;
    }


    if(player1Lost || player2Lost) this->nextState() ;

    if(p1->isGodMode()){
            if(this->godModePlayer1Time.getElapsedTime().asSeconds() >= GOD_MODE_DURATION_IN_SECONDS)
                p1->disableGodMode() ;
    }

    if(p2->isGodMode()){
            if(this->godModePlayer2Time.getElapsedTime().asSeconds() >= GOD_MODE_DURATION_IN_SECONDS)
                p2->disableGodMode() ;
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
