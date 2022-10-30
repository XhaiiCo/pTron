#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text textBtn[MAX_NUMBER_OF_ITEMS];
    public:
        Menu(float width = 500, float height = 500);
        virtual ~Menu();

        void draw (sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem() const;

};

#endif // MENU_H
