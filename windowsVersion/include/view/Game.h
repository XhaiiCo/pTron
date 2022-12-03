#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "Playground.h"
#include "Player.h"
#include "GamePlay.h"
#include "Menu.h"
#include "StateManager.h"
#include "GameContext.h"
#include "Player.h"

/*
* The Game class is the "main" class. it contains the players and gameContext.
* This class contains also the main loop of the game.
*/
class Game
{

    private:
        /*
        *
        * The gameContext contains the objects that are useful for the different views,For example the window, the 2 players.
        * And this gameContext will be passed through the different views during the execution of the program.
        * The advantage of using a class that contains the objects, rather than passing them as parameters,
        * is that it's easier to add things without have to change them in all the views.
        *
        * Internal association by pointer:
        *   the game class create the gameContext and handle it.
        */
        GameContext* gameContext ;
        StateManager* stateManager ;
        sf::RenderWindow* window ;

        /*
        * Internal association by pointer:
        *   The game class create both players, and handle them.
        */
        Player* player1 ;
        Player* player2 ;

    public:
        Game();
        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);

        /*
        * This method contains the main loop.
        * In the main loop at each iteration it will :
        *   capture the keyboard/mouse inputs,
        *   update the view
        *   and redraw
        */
        void run() ;

        /*
        * This method will initialize the game context.
        * by creating objects and add them to the GameContext
        */
        void initGameContext() ;
};

#endif // GAME_H
