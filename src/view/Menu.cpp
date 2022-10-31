#include "Menu.h"
#include <iostream>

#include "GamePlay.h"

Menu::Menu(StateManager* sm, sf::RenderWindow* window, float width, float height): sm(sm), window(window), width(width), height(height){}

Menu::~Menu()
{
    //dtor
}

void Menu::init(){
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
};

void Menu::processInput(){
    sf::Event event;
    while (window->pollEvent(event)){
        if(event.type == sf::Event::Closed) window->close() ;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) this->MoveUp() ;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) this->MoveDown() ;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        int pressedItem = this->GetPressedItem();

        if(pressedItem == 0)
        {
            this->sm->setState(new GamePlay(this->sm, this->window, this->width, this->height)) ;
            this->sm->getState()->init() ;
        }
        else if(pressedItem == 1)
        {
            std::cout << "Option button has been pressed" << std::endl;
        }
        else
        {
            window->close();
        }
    }

};

void Menu::update(){};

void Menu::draw(){
    this->window->clear() ;
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {

        this->window->draw(textBtn[i]);
    }
    this->window->display();
};

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
