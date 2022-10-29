#include "Case.h"

Case::Case()
{
    //by default a case is empty, it does not contain a player
    this->player = nullptr ;
}

Case::~Case()
{
    //dtor
}

Case::Case(const Case& other)
{
     this->player = other.player;
}

Case& Case::operator=(const Case& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    return *this;
}


void Case::setPlayer(Player& player){
    this->player = &player ;
}

std::string Case::str() const {
    if(this->player == nullptr) return "*" ;

    return this->player->str() ;
}
