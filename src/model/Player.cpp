#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Playground.h"

Player::Player(std::string name, int x, int y): name(name), x(x), y(y)
{
    this->dirX = 0 ;
    this->dirY = 0 ;
}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& other)
{
    this->name = other.name ;
    this->x = other.x ;
    this->y = other.y ;
    this->dirX = other.dirX ;
    this->dirY = other.dirY ;
}

Player& Player::operator=(const Player& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->name = rhs.name ;
    this->x = rhs.x ;
    this->y = rhs.y ;
    this->dirX = rhs.dirX ;
    this->dirY = rhs.dirY ;

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

    if(this->x >= Playground::NB_COLUMN) this->x = 0 ;
    if(this->x < 0) this->x = Playground::NB_LINE -1 ;

    this->y += dirY ;
    if(this->y >= Playground::NB_COLUMN) this->y = 0 ;
    if(this->y < 0) this->y = Playground::NB_COLUMN -1 ;
}
