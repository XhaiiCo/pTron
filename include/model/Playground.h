#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include "vector"
#include "Case.h"
#include "Player.h"

class Playground
{
    private:
        const inline static int NB_COLUMN = 10 ;
        const inline static int NB_LINE = 10 ;

        std::vector<std::vector<Case*>> cases ;

        Player player1 ;
        Player player2 ;

    public:
        Playground(Player = Player(), Player = Player());
        virtual ~Playground();
        Playground(const Playground& other);
        Playground& operator=(const Playground& other);

        void init() ;
        void createCase() ;

        void movePlayer(int x, int y) ;

        std::string str() const ;
};

#endif // PLAYGROUND_H
