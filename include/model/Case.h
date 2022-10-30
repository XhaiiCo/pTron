#ifndef CASE_H
#define CASE_H

#include "Player.h"
class Case
{
    private:
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
