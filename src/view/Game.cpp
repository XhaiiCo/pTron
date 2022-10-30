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
            c.setPosition(j*(CIRCLE_RADIUS*2 + PADDING) ,i*(CIRCLE_RADIUS*2 +PADDING)) ;
            Player* p = Cases[i][j]->getPlayer() ;
            if(p == nullptr) c.setFillColor(Color::Black) ;
            else c.setFillColor(sf::Color(p->getRed(), p->getGreen(), p->getBlue())) ;
            this->t.draw(c) ;
        }
    }

    this->t.display();
}

Sprite Game::getSprite() {
    return this->sprite;
}
