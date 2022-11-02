#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "StateManager.h"
#include "GameContext.h"

#define MAX_NUMBER_OF_ITEMS 3

class Menu: public GameState
{
    //CONSTANT
    public:
        const inline static std::string FONT_PATH = "assets/fonts/Square-Bold.otf" ;

    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text textBtn[MAX_NUMBER_OF_ITEMS];

        GameContext* gameContext ;
    public:
        Menu(GameContext* gameContext);
        virtual ~Menu();

        void draw (sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem() const;

        virtual void init() override ;
        virtual void processInput() override ;
        virtual void update() override ;
        virtual void draw() override ;
        virtual void nextState() override ;
        virtual Menu* clone() override;
};

#endif // MENU_H
