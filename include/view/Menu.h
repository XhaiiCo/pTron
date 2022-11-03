#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "StateManager.h"
#include "GameContext.h"

#define MAX_NUMBER_OF_ITEMS 3

/*
* This view is the main menu of the game
*/
class Menu: public GameState
{
    //CONSTANT
    public:
        const inline static std::string FONT_PATH = "assets/fonts/Square-Bold.otf" ;
        const inline static std::string TITLE_FONT_PATH = "assets/fonts/joystix-monospace.ttf" ;

    private:
        int selectedItemIndex;
        sf::Text title ;
        sf::Font titleFont ;

        sf::Font font;
        sf::Text textBtn[MAX_NUMBER_OF_ITEMS];

        GameContext* gameContext ;
    public:
        Menu(GameContext* gameContext);
        virtual ~Menu();
        Menu(const Menu& other);
        Menu& operator=(const Menu& other);

        //Move up to item's menu
        void MoveUp();

        //Move down to item's menu
        void MoveDown();

        //Get the current selected item
        int GetPressedItem() const;

        virtual void init() override ;
        virtual void processInput() override ;
        virtual void update() override ;
        virtual void draw() override ;
        virtual void nextState() override ;
        virtual Menu* clone() override;
};

#endif // MENU_H
