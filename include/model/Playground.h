#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include "Case.h"
#include "vector"
#include "Player.h"

/*
* The playground class represents the playing field of a game.
* The class contains the both players and a matrix of case
*/
class Playground
{
    //CONSTANT
    public:
        const inline static int NB_COLUMN = 75;
        const inline static int NB_LINE = 50 ;
        const inline static int NB_PLAYERS = 2 ;


    private:
        /*
        * Cases is a matrix of case. That represents the playing field.
        * Internal association by pointer:
        *   The cases belong to the playground, it does not exist outside.
        *   If we delete the playground, we delete the cases too.
        */
        std::vector<std::vector<Case*>> cases ;

        /*
        * External association by pointer:
        *   The player don't belong to the playground.
        *   He exits outside the box because he can play several games and it still the same player.
        */
        std::vector<Player*> players ;

    public:
        Playground();
        virtual ~Playground();
        Playground(const Playground& other);
        Playground& operator=(const Playground& other);

        std::vector<std::vector<Case*>> getCases(){
            return this->cases ;
        } ;

        //This method will init the playground, add the two players and create the cases
        void init(Player* player1, Player* player2) ;

        //This method will create and push all the cases into the cases matrix.
        void createCase() ;

        //This method will validate the player's IP (between 0 and 1)
        bool validPlayerId(int id) ;

        //This method will call the movePlayer method for the both player
        void movePlayers() ;

        //This method will put the players into the cases according to their x and y positions.
        void displayplayers() ;

        /*
        * This method will return if the player has lost or not.
        * Param (id): The player id (0 for player 1 or 1 for player 2)
        */
        bool isPlayerHasLost(int id) ;


        std::string str() const ;
};

#endif // PLAYGROUND_H
