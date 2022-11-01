#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include "GameState.h"
#include "GameContext.h"
#include "TextBox.h"
#include "Button.h"

class GameSettings: public GameState
{
    private:
        GameContext* gameContext ;

        sf::Font font;
        TextBox textbox1 ;
        TextBox textbox2 ;
        Button btn1 ;

    public:
        GameSettings(GameContext* gameContext);
        virtual ~GameSettings();
        GameSettings(const GameSettings& other);
        GameSettings& operator=(const GameSettings& other);

        virtual void init() override ;
        virtual void processInput() override ;
        virtual void update() override ;
        virtual void draw() override ;

        virtual void nextState() override ;

};

#endif // GAMESETTINGS_H
