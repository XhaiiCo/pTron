#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "Player.h"

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
