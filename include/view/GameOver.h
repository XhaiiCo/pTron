#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "GameState.h"
#include "StateManager.h"
#include <SFML/Graphics.hpp>
#include "GameContext.h"

class GameOver: public GameState
{
    private:
        GameContext* gameContext ;

        sf::Text title ;
        sf::Font font ;

    public:
        GameOver(GameContext* gameContext);
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
