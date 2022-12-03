#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "GameState.h"
#include "StateManager.h"
#include <SFML/Graphics.hpp>
#include "Playground.h"
#include "Color.h"
#include "GameContext.h"

/*
* This view display a game.
* It makes a new playground and passes him the both players
*/
class GamePlay: public GameState
{
    //CONSTANT
    public:
        inline const static int CASE_WIDTH = 17 ;
        inline const static int PADDING = 0 ;
        inline const static int GOD_MODE_DURATION_IN_SECONDS = 2 ;

    private:
        GameContext* gameContext ;

        Playground playground ;
        Color emptyCaseColor = Color(25,25,30) ;

        //If a player have lost
        bool player1Lost = false ;
        bool player2Lost = false ;

        //The time since the player is in god mode
        sf::Clock godModePlayer1Time ;
        sf::Clock godModePlayer2Time ;

    public:
        GamePlay(GameContext* gameContext);
        virtual ~GamePlay();
        GamePlay(const GamePlay& other);
        GamePlay& operator=(const GamePlay& other);


        virtual void init() override ;
        virtual void processInput() override ;
        virtual void update() override ;
        virtual void draw() override ;
        virtual void nextState() override ;
        virtual GamePlay* clone() override;

};

#endif // GAMEPLAY_H
