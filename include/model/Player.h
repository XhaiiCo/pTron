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

    public:
        Player(std::string = "UNDEFINED", int x = 0, int y = 0);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        int getX() { return this->x ;}
        void setX(int value){
            if(value < 0) return ;
            //if(value > Playground::NB_COLUMN) return

            this->x = value;
        }

        int getY() { return this->y ;}
        void setY(int value){
            if(value < 0) return ;
            //if(value > Playground::NB_LINE) return

            this->y = value ;
        }

        bool changeDirection(const int dirX, const int dirY) ;
        void movePlayer() ;

        std::string str() const ;
};

#endif // PLAYER_H
