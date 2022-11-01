#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "GameState.h"
#include "StateManager.h"
#include <SFML/Graphics.hpp>

class GameOver: public GameState
{
    private:
        StateManager* stateManager ;
        sf::RenderWindow* window ;
        int windowWidth ;
        int windowHeight ;

        sf::Text title ;
        sf::Font font ;

    public:
        GameOver(StateManager*, sf::RenderWindow*, int windowWidth = 500, int windowHeight = 500);
        virtual ~GameOver();
        GameOver(const GameOver& other);
        GameOver& operator=(const GameOver& other);

        virtual void init() override ;
        virtual void processInput() override ;
        virtual void update() override ;
        virtual void draw() override ;
        virtual void nextState() override ;
};

#endif // GAMEOVER_H
