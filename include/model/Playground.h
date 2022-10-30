#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include "Case.h"
#include "vector"
#include "Player.h"

class Playground
{
    //CONSTANT
    public:
        const inline static int NB_COLUMN = 30 ;
        const inline static int NB_LINE = 30 ;


    private:
        std::vector<std::vector<Case*>> cases ;

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
        void movePlayers() ;

        std::string str() const ;
};

#endif // PLAYGROUND_H
