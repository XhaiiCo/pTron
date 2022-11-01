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
        const inline static int NB_PLAYERS = 2 ;


    private:
        /*
        * Association interne par pointer, les cases appartiennent au plateau de jeux, elle n'existe pas en dehors
        */
        std::vector<std::vector<Case*>> cases ;

        /*
        * Associatino interne par valeur, les joueur appartiennent au plateau.
        */
        std::vector<Player*> players ;

    public:
        Playground(Player* player1 = new Player(), Player* player2 = new Player());
        virtual ~Playground();
        Playground(const Playground& other);
        Playground& operator=(const Playground& other);

        std::vector<std::vector<Case*>> getCases(){
            return this->cases ;
        } ;

        void init() ;
        void createCase() ;

        bool validPlayerId(int id) ;

        void movePlayers() ;
        void displayplayers() ;

        bool isPlayerHasLost(int id) ;
        std::string str() const ;
};

#endif // PLAYGROUND_H
