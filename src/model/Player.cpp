#include "Player.h"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& other)
{
    //copy ctor
}

Player& Player::operator=(const Player& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


std::string Player::str() const {
    return "P" ;
}
