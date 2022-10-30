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
        int getBlue() { return this->red ;}

        bool changeDirection(const int dirX, const int dirY) ;
        void movePlayer() ;

        std::string str() const ;
};

#endif // PLAYER_H
