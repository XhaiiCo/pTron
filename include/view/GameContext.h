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

        std::string namePlayer1 = "Player 1" ;
        std::string namePlayer2 = "Player 2" ;

    public:
        GameContext(StateManager stateManager, sf::RenderWindow* window, float windowWidth = 500, float windowHeight = 500);
        virtual ~GameContext();
        GameContext(const GameContext& other);
        GameContext& operator=(const GameContext& other);

        sf::RenderWindow* getWindow(){ return this->window ; }
        StateManager* getStateManager(){ return this->stateManager ; }
        float getWindowWidth(){ return this->windowWidth ; }
        float getWindowHeight(){ return this->windowHeight ; }

        void setNamePlayer1(std::string value){this->namePlayer1 = value ;}
        void setNamePlayer2(std::string value){this->namePlayer2 = value ;}
        std::string getNamePlayer1(){ return this->namePlayer1 ;}
        std::string getNamePlayer2(){ return this->namePlayer2 ;}
};

#endif // GAMECONTEXT_H
