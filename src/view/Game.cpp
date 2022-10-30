#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game(int width, int height): width(width), height(height)
{
    init();
}

Game::Game(int width, int height, Playground playground): width(width), height(height), playground(playground)
{
    init();
}

Game::~Game()
{
    //dtor
}

void Game::init() {
    // Créée une image sur laquelle on peut dessiner
    this->t.create(this->width, this->height);
    this->t.setSmooth(true);
    // on l'a met dans le sprite
    this->sprite.setTexture(this->t.getTexture());
    // Sinon ça affiche des trucs chelou
    this->t.clear();

    // Affichage des point
//    c.setPosition(100, 100);
//    c.setFillColor(Color::White);
//    this->t.draw(c);
//
//    c.setPosition(200, 200);
//    c.setFillColor(Color::Yellow);
//    this->t.draw(c);

    std::vector<std::vector<Case*>> Cases = this->playground.getCases() ;

    for(int i = 0 ; i < Cases.size() ; i++){
        for(int j = 0 ; j < Cases[i].size() ; j++){
            c.setPosition(i*(CIRCLE_RADIUS*2 +2) ,j*(CIRCLE_RADIUS*2 +2)) ;
            Player* p = Cases[j][i]->getPlayer() ;
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
