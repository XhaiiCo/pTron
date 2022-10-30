#include "Menu.h"

Menu::Menu(float width, float height)
{

    if (!font.loadFromFile("arial.ttf"))
    {
        //handle error
    }

    textBtn[0].setFont(font);
    textBtn[0].setColor(sf::Color::Red);
    textBtn[0].setString("Play");
    textBtn[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    textBtn[1].setFont(font);
    textBtn[1].setColor(sf::Color::White);
    textBtn[1].setString("Options");
    textBtn[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    textBtn[2].setFont(font);
    textBtn[2].setColor(sf::Color::White);
    textBtn[2].setString("Exit");
    textBtn[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}

Menu::~Menu()
{
    //dtor
}

void Menu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {

        window.draw(textBtn[i]);
    }
}

void Menu::MoveUp()
{
    if(selectedItemIndex - 1 >= 0)
    {
        textBtn[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        textBtn[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{

    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        textBtn[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        textBtn[selectedItemIndex].setColor(sf::Color::Red);
    }
}

int Menu::GetPressedItem() const
{
    return selectedItemIndex;
}
