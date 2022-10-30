#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

Player::Player(std::string name, sf::Color color): name(name), color(color)
{
    //ctor
}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& other)
{
    this->name = other.name ;
    this->color = other.color ;
}

Player& Player::operator=(const Player& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->name = rhs.name ;
    this->color = rhs.color ;
    return *this;
}


std::string Player::str() const {
    return this->name ;
}
