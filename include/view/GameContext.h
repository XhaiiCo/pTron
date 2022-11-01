#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include <SFML/Graphics.hpp>
#include "StateManager.h"

class GameContext
{
    private:
        sf::RenderWindow* window ;
        StateManager* stateManager;
        float windowWidth ;
        float windowHeight ;

    public:
        GameContext(StateManager stateManager, sf::RenderWindow* window, float windowWidth = 500, float windowHeight = 500);
        virtual ~GameContext();
        GameContext(const GameContext& other);
        GameContext& operator=(const GameContext& other);

        sf::RenderWindow* getWindow(){ return this->window ; }
        StateManager* getStateManager(){ return this->stateManager ; }
        float getWindowWidth(){ return this->windowWidth ; }
        float getWindowHeight(){ return this->windowHeight ; }
};

#endif // GAMECONTEXT_H
