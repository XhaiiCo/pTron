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
        int windowWidth ;
        int windowHeight ;
        sf::RenderWindow* window ;
        StateManager* stateManager ;

        GameContext* gameContext ;

    public:
        Game();
        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);

        void run() ;
};

#endif // GAME_H
