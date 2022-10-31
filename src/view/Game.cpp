#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Game::Game(int width, int height, Playground* playground): width(width), height(height), playground(playground)
{
}

Game::~Game()
{
    //dtor
}

void Game::drawGame()  {
    // Créée une image sur laquelle on peut dessiner
    this->t.create(this->width, this->height);
    this->t.setSmooth(true);
    // on l'a met dans le sprite
    this->sprite.setTexture(this->t.getTexture());
    // Sinon ça affiche des trucs chelou
    this->t.clear();
    std::vector<std::vector<Case*>> Cases = this->playground->getCases() ;

    for(int i = 0 ; i < Cases.size() ; i++){
        for(int j = 0 ; j < Cases[i].size() ; j++){
            Player* p = Cases[i][j]->getPlayer() ;

            sf::RectangleShape rectangle(sf::Vector2f(CASE_WIDTH, CASE_WIDTH)) ;
            rectangle.setPosition(j*(CASE_WIDTH + PADDING ) , i*(CASE_WIDTH + PADDING)) ;
            rectangle.setOutlineColor(sf::Color(15,15,15)) ;
            rectangle.setOutlineThickness(1) ;

            if(p == nullptr) rectangle.setFillColor(sf::Color(25,25,30)) ;
            else rectangle.setFillColor(sf::Color(p->getRed(), p->getGreen(), p->getBlue())) ;
            this->t.draw(rectangle) ;
        }
    }

    this->t.display();
}

Sprite Game::getSprite() {
    return this->sprite;
}
