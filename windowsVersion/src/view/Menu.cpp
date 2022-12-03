#include "Menu.h"
#include <iostream>

#include "GameSettings.h"
#include "GameRules.h"

Menu::Menu(GameContext* gameContext): gameContext(gameContext){}

Menu::~Menu()
{
    //dtor
}

Menu::Menu(const Menu& other)
{
    this->selectedItemIndex = other.selectedItemIndex ;
    this->font = other.font ;
    for(int i = 0 ; i < MAX_NUMBER_OF_ITEMS ; i++){
        this->textBtn[i] = other.textBtn[i] ;
    }
    this->gameContext = other.gameContext ;
}

Menu& Menu::operator=(const Menu& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->selectedItemIndex = rhs.selectedItemIndex ;
    this->font = rhs.font ;
    for(int i = 0 ; i < MAX_NUMBER_OF_ITEMS ; i++){
        this->textBtn[i] = rhs.textBtn[i] ;
    }
    this->gameContext = rhs.gameContext ;

    return *this;
}

void Menu::init(){

    if (!font.loadFromFile(FONT_PATH))
    {
        //handle error
    }

    float width = this->gameContext->getWindowWidth() ;
    float height = this->gameContext->getWindowHeight() ;
    this->gameContext->getWindow()->setKeyRepeatEnabled(false) ;

    sf::FloatRect textRect;
    float x = 1.5;

    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        textBtn[i].setFont(font);
        textBtn[i].setColor(sf::Color::White);
        textBtn[i].setString(btnNames[i]);
        textBtn[i].setCharacterSize(70);
        textRect = textBtn[i].getLocalBounds();
        textBtn[i].setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
        x += 0.6;
        textBtn[i].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * x));
    }
    textBtn[0].setColor(sf::Color::Green);


    selectedItemIndex = 0;

    if (!titleFont.loadFromFile(TITLE_FONT_PATH))
    {
        //handle error
    }

    //CREATE THE TITLE
    title.setFont(titleFont);
    title.setColor(sf::Color::Green);
    title.setString("THE TRON GAME");
    title.setCharacterSize(70);

    sf::FloatRect titleRect = title.getLocalBounds();
    title.setOrigin(titleRect.left + titleRect.width/2.0f, titleRect.top  + titleRect.height/2.0f);
    title.setPosition({
                      this->gameContext->getWindow()->getView().getCenter().x,
                      this->gameContext->getWindow()->getView().getCenter().y / 2
                      });
}

void Menu::processInput(){
    sf::Event event;
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    while (window->pollEvent(event)){
        if(event.type == sf::Event::Closed) window->close() ;

        if(event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::Up) this->MoveUp() ;
            else if(event.key.code == sf::Keyboard::Down) this->MoveDown() ;
            else if(event.key.code == sf::Keyboard::Enter){
                int pressedItem = this->GetPressedItem();

                if(pressedItem == 0)
                {
                    this->nextState() ;
                }
                else if(pressedItem == 1)
                {
                    StateManager* stateManager = this->gameContext->getStateManager() ;

                    GameRules* gameRules = new GameRules(this->gameContext) ;
                    stateManager->setState(gameRules) ;
                    stateManager->getState()->init() ;

                    delete gameRules ;
                }
                else
                {
                    window->close();
                }
            }
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
    window->draw(this->title) ;
    window->display();
}

void Menu::nextState(){
    StateManager* stateManager = this->gameContext->getStateManager() ;
    GameSettings* gameSettings = new GameSettings(this->gameContext) ;
    stateManager->setState(gameSettings) ;
    stateManager->getState()->init() ;

    delete gameSettings ;
}

Menu* Menu::clone() {
    return new Menu(*this) ;
}

void Menu::MoveUp()
{
    if(selectedItemIndex - 1 >= 0)
    {
        textBtn[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        textBtn[selectedItemIndex].setColor(sf::Color::Green);
    }
}

void Menu::MoveDown()
{

    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        textBtn[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        textBtn[selectedItemIndex].setColor(sf::Color::Green);
    }
}

int Menu::GetPressedItem() const
{
    return selectedItemIndex;
}
