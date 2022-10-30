#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

Player::Player(std::string name): name(name)
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
}

Player& Player::operator=(const Player& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->name = rhs.name ;
    return *this;
}


std::string Player::str() const {
    return this->name ;
}
