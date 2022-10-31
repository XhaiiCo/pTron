#ifndef PLAYER_H
#define PLAYER_H

#include "string"

class Player
{
    private:
        std::string name ;
        int x;
        int y ;
        int dirX = 0;
        int dirY = 0;

        //COLOR
        int red ;
        int green ;
        int blue ;

        int redGodMode ;
        int greenGodMode ;
        int blueGodMode ;

        //BONUS
        bool godMode = false ;
        int nbGodModeRemaining = 1 ;

    public:
        Player(std::string = "UNDEFINED", int x = 0, int y = 0);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        int getX() { return this->x ;}
        void setX(int value) ;

        int getY() { return this->y ;}
        void setY(int value) ;

        void setColor(int r, int g, int b) {
            this->red = r ;
            this->green = g ;
            this->blue = b ;
        };
        int getRed() { return this->red ;}
        int getGreen() { return this->green ;}
        int getBlue() { return this->blue ;}

        void setColorGodMode(int r, int g, int b) {
            this->redGodMode = r ;
            this->greenGodMode = g ;
            this->blueGodMode = b ;
        };
        int getRedGodMode() { return this->redGodMode;}
        int getGreenGodMode() { return this->greenGodMode ;}
        int getBlueGodMode() { return this->blueGodMode ;}

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
