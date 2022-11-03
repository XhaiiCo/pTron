#ifndef PLAYER_H
#define PLAYER_H

#include "string"
#include "Color.h"

/*
* This class represents a player, a player is represented by a  name.
*/
class Player
{
    private:
        std::string name ;

        //The score increase when the player win a game.
        int score = 0;

        //If the player win the game
        bool win ;

        //Position on the playground
        int x;
        int y ;

        //Direction
        /*
        * for example
        * if dirX equal to 1 : the player will advance by 1 on the x-axis at each iteration.
        * if dirX equal to 0 : the player will not move on the x-axis at each iteration.
        * and if dirX equal to -1 : the player will move back on the x-axis at each iteration.
        * It's the same principale for dirY but on the  y axis.
        */
        int dirX = 0;
        int dirY = 0;

        //BONUS
        /*
        * The god mode is a bonus that the player can activate once game.
        * It makes him invincible for a few seconds.
        */
        bool godMode = false ;//If the godMode is currently activate
        int nbGodModeRemaining ;//The number of god mode remaining (each time the god mode is activated the remaining number decreases)

        //COLOR
        //The color of the player
        Color mainColor ;
        //The color of the player when the godMode is activate
        Color godModeColor ;

    public:
        Player(std::string str = "UNDEFINED", int x = 0, int y = 0);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        //Reset the settings to restart a game
        void resetParams() ;

        //Increase the score by one
        void increaseScore() ;

        //Return the current score
        int getScore() ;

        std::string getName(){ return this->name ;}
        void setName(std::string value){ this->name = value ;}

        int getX() { return this->x ;}
        void setX(int value) ;

        int getY() { return this->y ;}
        void setY(int value) ;

        bool getWin() { return this->win ;}
        void setWin(bool value){ this->win = value ;}

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

        /*
        * Activate god mode if nbGodModeRemaining is greater than 0 and decrease this variable.
        * And return true or false depending  on whether the god mode is activate or not
        */
        bool triggerGodMode() ;

        //Disable the god mode
        void disableGodMode() ;

        //Return true or false if the player is in god mode or not
        bool isGodMode(){ return this->godMode ;}

        /*
        * Change the direction of the player in x and y
        * Return true if the direction have change false otherwise
        */
        bool changeDirection(const int dirX, const int dirY) ;

        /*
        * Will move the player according to his current directions.
        * And if it reaches the edge of the card: put it back on the opposite side.
        */
        void movePlayer() ;

        std::string str() const ;
};

#endif // PLAYER_H
