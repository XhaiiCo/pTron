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
    this->t.create(this->width, this->height);
    this->t.setSmooth(true);
    this->sprite.setTexture(this->t.getTexture());
    this->t.clear();

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
