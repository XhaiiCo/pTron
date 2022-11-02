#ifndef GAMELAUNCH_H
#define GAMELAUNCH_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "StateManager.h"
#include "GameContext.h"

class GameLaunch: public GameState
{
    //CONSTANT
    public:
        const inline static int LAUNCH_SCREEN_DURATION_IN_SECONDS = 3 ;
        const inline static std::string FONT_PATH = "assets/fonts/joystix-monospace.ttf" ;

    private:
        sf::Clock duration ;
        sf::Text title ;
        sf::Font font ;

        GameContext* gameContext ;

    public:
        GameLaunch(GameContext* gameContext);
        virtual ~GameLaunch();
        GameLaunch(const GameLaunch& other);
        GameLaunch& operator=(const GameLaunch& other);

        virtual void init() override ;
        virtual void processInput() override ;
        virtual void update() override ;
        virtual void draw() override ;
        virtual void nextState() override ;
        virtual GameLaunch* clone() override;
};

#endif // GAMELAUNCH_H
