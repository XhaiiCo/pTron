#include "GamePlay.h"

#include <iostream>
#include <SFML/Graphics.hpp>
GamePlay::GamePlay(StateManager* sm, sf::RenderWindow* window, float width, float height): sm(sm), window(window), width(width), height(height){}

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
    Player p1("D", 5, yStart) ;
    Player p2("J ", Playground::NB_COLUMN-5, yStart) ;
    p1.setColor(255, 0, 0) ;
    p2.setColor(85, 255, 0) ;
    p1.changeDirection(1,0) ;
    p2.changeDirection(-1, 0) ;

    Playground p(p1,p2) ;

    this->playground = p;
}

void GamePlay::processInput(){
    sf::Event event;

    while(window->pollEvent(event))
        if(event.type == sf::Event::Closed) this->window->close();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) playground.changeDirectionPlayer2(0, -1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) playground.changeDirectionPlayer2(0, 1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) playground.changeDirectionPlayer2(-1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) playground.changeDirectionPlayer2(1, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) playground.changeDirectionPlayer1(0, -1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) playground.changeDirectionPlayer1(0, 1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) playground.changeDirectionPlayer1(-1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) playground.changeDirectionPlayer1(1, 0);
}

void GamePlay::update(){
    playground.movePlayers() ;

    player1Lost = playground.isPlayer1HasLost() ;
    player2Lost = playground.isPlayer2HasLost() ;

    if(player1Lost || player2Lost) this->window->close() ;

    playground.displayplayers() ;

    if(player1Lost && player2Lost) std::cout << "Match draw" << std::endl ;
    else if(player2Lost) std::cout << "Player 1 won" << std::endl ;
    else if(player1Lost) std::cout << "Player 2 won" << std::endl ;
}

void GamePlay::draw(){
    this->window->clear() ;
    std::vector<std::vector<Case*>> Cases = this->playground.getCases() ;

    for(int i = 0 ; i < Cases.size() ; i++){
        for(int j = 0 ; j < Cases[i].size() ; j++){
            Player* p = Cases[i][j]->getPlayer() ;

            sf::RectangleShape rectangle(sf::Vector2f(CASE_WIDTH, CASE_WIDTH)) ;
            rectangle.setPosition(j*(CASE_WIDTH + PADDING ) , i*(CASE_WIDTH + PADDING)) ;
            rectangle.setOutlineColor(sf::Color(15,15,15)) ;
            rectangle.setOutlineThickness(1) ;

            if(p == nullptr) rectangle.setFillColor(sf::Color(25,25,30)) ;
            else rectangle.setFillColor(sf::Color(p->getRed(), p->getGreen(), p->getBlue())) ;
            this->window->draw(rectangle) ;
        }
    }
    this->window->display();
}
