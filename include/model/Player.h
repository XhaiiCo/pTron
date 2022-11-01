#ifndef PLAYER_H
#define PLAYER_H

#include "string"
#include "Color.h"


class Player
{
    private:
        std::string name ;
        int score = 0;

        int x;
        int y ;
        int dirX = 0;
        int dirY = 0;

        //COLOR
        Color mainColor ;
        Color godModeColor ;

        //BONUS
        bool godMode = false ;
        int nbGodModeRemaining ;

    public:
        Player(std::string = "UNDEFINED", int x = 0, int y = 0);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        void resetParams() ;
        void ecreaseScore() ;
        int getScore() ;

        int getX() { return this->x ;}
        void setX(int value) ;

        int getY() { return this->y ;}
        void setY(int value) ;

        void setMainColor(Color color) {
            this->mainColor = color ;
        };
        Color getMainColor(){ return this->mainColor ;}

        void setGodModeColor(Color color) {
            this->godModeColor = color ;
        };
        Color getGodModeColor(){ return this->godModeColor ;}

        void setNbGodModeRemaining(int value){
            if(value < 0 ) value = 0 ;
            this->nbGodModeRemaining = value ;
        }

        bool triggerGodMode() ;
        void disableGodMode() ;
        bool isGodMode(){ return this->godMode ;}

        bool changeDirection(const int dirX, const int dirY) ;
        void movePlayer() ;

        std::string str() const ;
};

#endif // PLAYER_H
