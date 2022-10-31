#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "StateManager.h"

#define MAX_NUMBER_OF_ITEMS 3

class Menu: public GameState
{
    private:
        int selectedItemIndex;
        float width ;
        float height ;
        sf::Font font;
        sf::Text textBtn[MAX_NUMBER_OF_ITEMS];

        sf::RenderWindow* window ;
        StateManager* sm ;
    public:
        Menu(StateManager* sm, sf::RenderWindow* window, float width = 500, float height = 500);
        virtual ~Menu();

        void draw (sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem() const;

        virtual void init() override ;
        virtual void processInput() override ;
        virtual void update() override ;
        virtual void draw() override ;
};

#endif // MENU_H
