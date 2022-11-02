#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "Player.h"

/*
* The gameContext contains the objects that are useful for the different views,For example the window, the 2 players.
* And this gameContext will be passed through the different views during the execution of the program.
* The advantage of using a class that contains the objects, rather than passing them as parameters,
* is that it's easier to add things without have to change them in all the views.
*/
class GameContext
{
    private:
        sf::RenderWindow* window ;
        StateManager* stateManager;
        Player* player1 ;
        Player* player2 ;

        float windowWidth ;
        float windowHeight ;



    public:
        GameContext(StateManager stateManager, sf::RenderWindow* window, Player* player1, Player* player2, float windowWidth = 500, float windowHeight = 500);
        virtual ~GameContext();
        GameContext(const GameContext& other);
        GameContext& operator=(const GameContext& other);

        sf::RenderWindow* getWindow(){ return this->window ; }
        StateManager* getStateManager(){ return this->stateManager ; }
        float getWindowWidth(){ return this->windowWidth ; }
        float getWindowHeight(){ return this->windowHeight ; }

        Player* getPlayer1(){ return this->player1 ;}
        Player* getPlayer2(){ return this->player2 ;}
};

#endif // GAMECONTEXT_H
