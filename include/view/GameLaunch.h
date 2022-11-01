#ifndef GAMELAUNCH_H
#define GAMELAUNCH_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "StateManager.h"

class GameLaunch: public GameState
{
    //CONSTANT
    public:
        const inline static int LAUNCH_SCREEN_DURATION_IN_SECONDS = 3 ;

    private:
        sf::Clock duration ;
        sf::Text title ;
        sf::Font font ;

        sf::RenderWindow* window ;
        StateManager* stateManager ;
        int windowWidth ;
        int windowHeight ;

    public:
        GameLaunch(StateManager*, sf::RenderWindow*, int = 500, int = 500);
        virtual ~GameLaunch();
        GameLaunch(const GameLaunch& other);
        GameLaunch& operator=(const GameLaunch& other);

        virtual void init() override ;
        virtual void processInput() override ;
        virtual void update() override ;
        virtual void draw() override ;
};

#endif // GAMELAUNCH_H
