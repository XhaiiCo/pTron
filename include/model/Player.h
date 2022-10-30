#ifndef PLAYER_H
#define PLAYER_H
#include "string"
#include <SFML/Graphics.hpp>

class Player
{
    private:
        std::string name ;
        int x;
        int y ;
        int dirX = 0;
        int dirY = 0;

    public:
        Player(std::string = "UNDEFINED");
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        void setX(int value){
            this->x = value;
        }

        void setY(int value){
            this->y = value ;
        }

        bool changeDirection(const int dirX, const int dirY) ;
        void movePlayer() ;

        std::string str() const ;
};

#endif // PLAYER_H
