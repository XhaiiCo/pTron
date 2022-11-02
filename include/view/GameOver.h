#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "GameState.h"
#include "StateManager.h"
#include <SFML/Graphics.hpp>
#include "GameContext.h"

class GameOver: public GameState
{
    //CONSTANT
    public:
        const inline static std::string FONT_PATH = "assets/fonts/Square-Bold.otf" ;
    private:
        GameContext* gameContext ;

        sf::Font font ;
        sf::Text title ;
        sf::Text scorePlayer1 ;
        sf::Text scorePlayer2 ;

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
        virtual GameOver* clone() override;
};

#endif // GAMEOVER_H
