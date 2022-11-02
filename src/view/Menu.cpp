#include "Menu.h"
#include <iostream>

#include "GameSettings.h"

Menu::Menu(GameContext* gameContext): gameContext(gameContext){}

Menu::~Menu()
{
    //dtor
}

void Menu::init(){
    if (!font.loadFromFile(FONT_PATH))
    {
        //handle error
    }

    float width = this->gameContext->getWindowWidth() ;
    float height = this->gameContext->getWindowHeight() ;

    textBtn[0].setFont(font);
    textBtn[0].setColor(sf::Color::Red);
    textBtn[0].setString("PLAY");
    textBtn[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    textBtn[1].setFont(font);
    textBtn[1].setColor(sf::Color::White);
    textBtn[1].setString("OPTIONS");
    textBtn[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    textBtn[2].setFont(font);
    textBtn[2].setColor(sf::Color::White);
    textBtn[2].setString("EXIT");
    textBtn[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}

void Menu::processInput(){
    sf::Event event;
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    while (window->pollEvent(event)){
        if(event.type == sf::Event::Closed) window->close() ;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) this->MoveUp() ;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) this->MoveDown() ;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        int pressedItem = this->GetPressedItem();

        if(pressedItem == 0)
        {
            this->nextState() ;
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

}

void Menu::update(){};

void Menu::draw(){
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    window->clear() ;
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {

        window->draw(textBtn[i]);
    }
    window->display();
}

void Menu::nextState(){
    StateManager* stateManager = this->gameContext->getStateManager() ;
    stateManager->setState(new GameSettings(this->gameContext)) ;
    stateManager->getState()->init() ;
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
