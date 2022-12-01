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
    this->gameContext = other.gameContext ;
    this->playground = other.playground ;
    this->emptyCaseColor = other.emptyCaseColor ;
    this->player1Lost = other.player1Lost ;
    this->player2Lost = other.player2Lost ;
    this->godModePlayer1Time = other.godModePlayer1Time ;
    this->godModePlayer2Time = other.godModePlayer2Time ;
}

GamePlay& GamePlay::operator=(const GamePlay& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->gameContext = rhs.gameContext ;
    this->playground = rhs.playground ;
    this->emptyCaseColor = rhs.emptyCaseColor ;
    this->player1Lost = rhs.player1Lost ;
    this->player2Lost = rhs.player2Lost ;
    this->godModePlayer1Time = rhs.godModePlayer1Time ;
    this->godModePlayer2Time = rhs.godModePlayer2Time ;

    return *this;
}

void GamePlay::init(){
    //Get the players from the game context
    Player* p1 = this->gameContext->getPlayer1() ;
    Player* p2 = this->gameContext->getPlayer2() ;
    this->gameContext->getWindow()->setFramerateLimit(11) ;

    //Reset the player's params
    p1->resetParams() ;
    p2->resetParams() ;

    //Set the start position for both player
    int yStart = (int)(Playground::NB_LINE/2) ;
    p1->setX(5) ;
    p1->setY(yStart) ;

    p2->setX(Playground::NB_COLUMN-5) ;
    p2->setY(yStart) ;

    p1->changeDirection(1,0) ;
    p2->changeDirection(-1, 0) ;


    //Init the playground with the 2 players
    this->playground.init(p1, p2) ;
}

void GamePlay::processInput(){
    sf::Event event;
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    Player* p1 = this->gameContext->getPlayer1() ;
    Player* p2 = this->gameContext->getPlayer2() ;

    while(window->pollEvent(event)){
        if(event.type == sf::Event::Closed) window->close();
        if(event.type == sf::Event::KeyPressed){

            //PLAYER 1 KEY BINDINGS
            if (event.key.code == sf::Keyboard::Z) p1->changeDirection(0, -1);
            if (event.key.code == sf::Keyboard::S) p1->changeDirection(0, 1);
            if (event.key.code == sf::Keyboard::Q) p1->changeDirection(-1, 0);
            if (event.key.code == sf::Keyboard::D) p1->changeDirection(1, 0);
            if (event.key.code == sf::Keyboard::A) {
            if (p1->triggerGodMode()){
                this->godModePlayer1Time.restart() ;
                }
            }

            //PLAYER 2 KEY BINDINGS
            if (event.key.code == sf::Keyboard::Up) p2->changeDirection(0, -1);
            if (event.key.code == sf::Keyboard::Down) p2->changeDirection(0, 1);
            if (event.key.code == sf::Keyboard::Left) p2->changeDirection(-1, 0);
            if (event.key.code == sf::Keyboard::Right) p2->changeDirection(1, 0);
            if (event.key.code == sf::Keyboard::RControl) {
                if(p2->triggerGodMode()){
                    this->godModePlayer2Time.restart() ;
                }
            }
        }
    }




}

void GamePlay::update(){
    //Get the players from the game context
    Player* p1 = this->gameContext->getPlayer1() ;
    Player* p2 = this->gameContext->getPlayer2() ;

    //MOVE BOTH PLAYER
    playground.movePlayers() ;

    //CHECK IF THE PLAYER HAVE LOST
    player1Lost = playground.isPlayerHasLost(0) ;
    player2Lost = playground.isPlayerHasLost(1) ;

    //MANAGE GOD MODE
    if(p1->isGodMode()){
            if(this->godModePlayer1Time.getElapsedTime().asSeconds() >= GOD_MODE_DURATION_IN_SECONDS)
                p1->disableGodMode() ;
    }

    if(p2->isGodMode()){
            if(this->godModePlayer2Time.getElapsedTime().asSeconds() >= GOD_MODE_DURATION_IN_SECONDS)
                p2->disableGodMode() ;
    }


    //AND SET PLAYER ON THE MAP
    playground.displayplayers() ;

    if(player1Lost || player2Lost){
        if(player1Lost != player2Lost)//If there is a draw, we do not increase the scores
        {
            if(player1Lost) { p2->increaseScore() ; p2->setWin(true) ; }
            if(player2Lost) { p1->increaseScore() ; p1->setWin(true) ; }
        }
        this->nextState() ;
    }
}

void GamePlay::draw(){
    //GET WINDOW FROM THE GET CONTEXT
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    window->clear() ;

    std::vector<std::vector<Case>> Cases = this->playground.getCases() ;

    //DRAW EACH CASE
    for(int i = 0 ; i < Cases.size() ; i++){
        for(int j = 0 ; j < Cases[i].size() ; j++){
            //GET THE PLAYER ON THE CASE
            Player* p = Cases[i][j].getPlayer() ;

            //CREATE THE CASE
            sf::RectangleShape rectangle(sf::Vector2f(CASE_WIDTH, CASE_WIDTH)) ;
            rectangle.setPosition(j*(CASE_WIDTH + PADDING ) , i*(CASE_WIDTH + PADDING)) ;
            rectangle.setOutlineColor(sf::Color(15,15,15)) ;
            rectangle.setOutlineThickness(1) ;

            //GET THE COLOR
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
    GameOver* gameOver = new GameOver(this->gameContext) ;

    stateManager->setState(gameOver);
    stateManager->getState()->init() ;

    delete gameOver ;
}

GamePlay* GamePlay::clone() {
    return new GamePlay(*this) ;
}
