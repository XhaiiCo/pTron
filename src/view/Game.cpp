#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game(int width, int height): width(width), height(height)
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
    c.setPosition(100, 100);
    c.setFillColor(Color::White);
    this->t.draw(c);

    c.setPosition(200, 200);
    c.setFillColor(Color::Yellow);
    this->t.draw(c);

    this->t.display();
}

Sprite Game::getSprite() {
    return this->sprite;
}
