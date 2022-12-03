#ifndef CASE_H
#define CASE_H

#include "Player.h"

/*
* This class represents a case of the playground.
* A case can be empty or owned by a player
*/
class Case
{
    private:
        /*
        * At the beginning the case is empty (player = nullptr),
        * if a player goes over, the case belong to him.
        * External association by pointer:
        *   The player don't belong to the case. He exits outside the box.
        */
        Player* player ;

    public:
        Case();
        virtual ~Case();
        Case(const Case& other);
        Case& operator=(const Case& other);

        void setPlayer(Player* player) ;
        Player* getPlayer() { return this->player ;}

        std::string str() const ;

};

#endif // CASE_H
