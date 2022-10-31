#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "GameState.h"
#include "StateManager.h"
#include <SFML/Graphics.hpp>
#include "Playground.h"

class GamePlay: public GameState
{
    //CONSTANT
    public:
        inline const static int CASE_WIDTH = 20 ;
        inline const static int PADDING = 0 ;


    private:
        sf::RenderWindow* window ;
        StateManager* sm ;
        float width ;
        float height ;
        Playground playground ;

        bool player1Lost = false ;
        bool player2Lost = false ;


    public:
        GamePlay(StateManager* sm, sf::RenderWindow* window, float width = 500, float height = 500);
        virtual ~GamePlay();
        GamePlay(const GamePlay& other);
        GamePlay& operator=(const GamePlay& other);


        virtual void init() override ;
        virtual void processInput() override ;
        virtual void update() override ;
        virtual void draw() override ;

};

#endif // GAMEPLAY_H
