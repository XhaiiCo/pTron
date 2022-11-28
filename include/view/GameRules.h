#ifndef GAMERULES_H
#define GAMERULES_H

#include "GameState.h"
#include "GameContext.h"


class GameRules: public GameState
{

    private:
        GameContext* gameContext ;

    public:
        GameRules(GameContext*);
        virtual ~GameRules();
        GameRules(const GameRules& other);
        GameRules& operator=(const GameRules& other);

        virtual void init() ;

        virtual void processInput() ;

        virtual void update() ;

        virtual void draw() ;

        virtual void nextState() ;

        virtual GameRules* clone() ;
};

#endif // GAMERULES_H
