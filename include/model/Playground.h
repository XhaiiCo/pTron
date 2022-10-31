#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include "Case.h"
#include "vector"
#include "Player.h"

class Playground
{
    //CONSTANT
    public:
        const inline static int NB_COLUMN = 75;
        const inline static int NB_LINE = 50 ;


    private:
        /*
        * Association interne par pointer, les cases appartiennent au plateau de jeux, elle n'existe pas en dehors
        */
        std::vector<std::vector<Case*>> cases ;

        /*
        * Associatino interne par valeur, les joueur appartiennent au plateau.
        */
        Player player1 ;
        Player player2 ;

    public:
        Playground(Player = Player(), Player = Player());
        virtual ~Playground();
        Playground(const Playground& other);
        Playground& operator=(const Playground& other);

        std::vector<std::vector<Case*>> getCases(){
            return this->cases ;
        } ;

        void init() ;
        void createCase() ;

        bool changeDirectionPlayer1(int dirX, int dirY) ;
        bool changeDirectionPlayer2(int dirX, int dirY) ;

        bool triggerGodModePlayer1() ;
        bool isPlayer1InGodMode() ;
        void disableGodModePlayer1() ;

        bool triggerGodModePlayer2() ;
        bool isPlayer2InGodMode() ;
        void disableGodModePlayer2() ;

        void movePlayers() ;
        void displayplayers() ;

        bool isPlayer1HasLost() ;
        bool isPlayer2HasLost() ;

        std::string str() const ;
};

#endif // PLAYGROUND_H
