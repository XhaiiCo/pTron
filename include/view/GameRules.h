#ifndef GAMERULES_H
#define GAMERULES_H

#include <string>
#include "GameState.h"
#include "GameContext.h"

#define MAX_NUMBER_OF_LINES 8

class GameRules: public GameState
{

    public:
        const inline static std::string FONT_PATH = "assets/fonts/Square-Bold.otf";
        const std::string rulesLines[MAX_NUMBER_OF_LINES] =
        {
            "2 players are on a board, they continuously advance and",
            "leave a coloured wall in their path, deadly for",
            "those who hit it. The objective is to outlast your opponent.",
            "Player 1 moves with the ZQSD keys while player 2 moves with",
            "the arrow keys. Both players have a bonus (A for player 1 and",
            "CTRL for player 2) which can be used once per game and which",
            "allows them to be invincible for a period of 3 seconds and thus",
            "pass through walls. So use it wisely."
        };



    private:
        GameContext* gameContext;

        sf::Text rulesText[MAX_NUMBER_OF_LINES];
        sf::Font font;

    public:
        GameRules(GameContext*);
        virtual ~GameRules();
        GameRules(const GameRules& other);
        GameRules& operator=(const GameRules& other);

        virtual void init() ;

        virtual void processInput() ;

        virtual void update() ;

        virtual void draw() ;

        virtual void nextState() ;

        virtual GameRules* clone() ;
};

#endif // GAMERULES_H
