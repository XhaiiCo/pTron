#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "GameState.h"
#include "StateManager.h"
#include <SFML/Graphics.hpp>
#include "GameContext.h"

#define MAX_NUMBER_OF_ITEMS 3

/*
* This view will be displayed at the end of the game.
* And display the winner and the score.
*/
class GameOver: public GameState
{
    //CONSTANT
    public:
        const inline static std::string FONT_PATH = "assets/fonts/Square-Bold.otf" ;


    private:
        int selectedItemIndex;
        GameContext* gameContext ;

        sf::Font font ;
        sf::Text title ;
        sf::Text scorePlayer1 ;
        sf::Text scorePlayer2 ;

        sf::Text textBtn[MAX_NUMBER_OF_ITEMS];

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

        //Move up to item's menu
        void MoveUp();

        //Move down to item's menu
        void MoveDown();

        int GetPressedItem() const;
};

#endif // GAMEOVER_H
