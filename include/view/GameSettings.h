#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include "GameState.h"
#include "GameContext.h"
#include "TextBox.h"
#include "Button.h"
#include "ColorTile.h"

#define MAX_NUMBER_OF_COLORS 4

#include <iostream>
/*
* This view is displayed before the first game for ask settings.
*/
class GameSettings: public GameState
{
    private:
        GameContext* gameContext ;

        sf::Font font;
        TextBox tbNamePlayer1 ;
        TextBox tbNamePlayer2;
        ColorTile colorsPlayer1[MAX_NUMBER_OF_COLORS];
        ColorTile colorsPlayer2[MAX_NUMBER_OF_COLORS];
        Button btnPlay;

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
        virtual GameSettings* clone() override;

        //Apply the settings to the players
        void applySettingToPlayers() ;

        void unselectAll(ColorTile * colorsPlayer);
        Color findSelectedColor(ColorTile * colorsPlayer) ;
};

#endif // GAMESETTINGS_H
