#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "Playground.h"
#include "Player.h"
#include "GamePlay.h"
#include "Menu.h"
#include "StateManager.h"
#include "GameContext.h"

class Game
{

    private:
        GameContext* gameContext ;

    public:
        Game();
        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);

        void run() ;
        void initGameContext() ;
};

#endif // GAME_H
