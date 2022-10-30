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

//change the player direction
bool Player::changeDirection(const int dirX, const int dirY){

    //One of the direction have to be 0, because the player can't move horizontally
    if(dirX != 0 && dirY != 0) return false ;

    //If the player is currently moving on the x-axis he can only change direction in y
    if(this->dirX != 0 && dirX != 0) return false ;

    //If the player is currently moving on the y-axis he can only change direction in x
    if(this->dirY != 0 && dirY != 0) return false ;

    this->dirX = dirX ;
    this->dirY = dirY ;
    return true ;

}

void Player::movePlayer(){
    this->x += dirX ;
    this->y += dirY ;
}
