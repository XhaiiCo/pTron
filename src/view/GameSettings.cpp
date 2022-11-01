#include "GameSettings.h"

#include "GamePlay.h"

GameSettings::GameSettings(GameContext* gameContext): gameContext(gameContext)
{
    //ctor
}

GameSettings::~GameSettings()
{
    //dtor
}

GameSettings::GameSettings(const GameSettings& other)
{
    //copy ctor
}

GameSettings& GameSettings::operator=(const GameSettings& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


void GameSettings::init(){
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    window->setKeyRepeatEnabled(true);

    sf::Font font;
    font.loadFromFile("assets/fonts/Square-Bold.otf");
    this->textbox1 = TextBox(30, sf::Color::Black, false);
    this->textbox1.setFont(font);
    this->textbox1.setPosition({300, 100});
    this->textbox1.setLimit(10);
    this->textbox1.setBorder(sf::Color::White);

    textbox2 = TextBox(30, sf::Color::Black, false);
    textbox2.setFont(font);
    textbox2.setPosition({1200, 100});
    textbox2.setLimit(10);
    textbox2.setBorder(sf::Color::White);

    btn1 = Button("PLAY", {200, 50}, 30, sf::Color::Green, sf::Color::Black);
    btn1.setPosition({760,600});
    btn1.setFont(font);

}

void GameSettings::processInput(){
    sf::Event event;
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    while (window->pollEvent(event)){
        switch(event.type)
        {
            case sf::Event::Closed:
                window->close();
                break ;

            case sf::Event::TextEntered:
                textbox1.typedOn(event);
                textbox2.typedOn(event);
                break;

            case sf::Event::MouseMoved:
                if(btn1.isMouseOver(window))
                {
                    btn1.setBackColor(sf::Color::White);
                }
                else
                {
                    btn1.setBackColor(sf::Color::Green);
                }
                break;

            case sf::Event::MouseButtonPressed:
                if(textbox1.isMouseOver(window))
                {
                    textbox1.setSelected(true);
                    textbox1.setBorder(sf::Color::Green);
                    textbox2.setSelected(false);
                    textbox2.setBorder(sf::Color::White);
                }
                else if(textbox2.isMouseOver(window))
                {
                    textbox2.setSelected(true);
                    textbox2.setBorder(sf::Color::Green);
                    textbox1.setSelected(false);
                    textbox1.setBorder(sf::Color::White);
                }
                else
                {
                    textbox1.setSelected(false);
                    textbox2.setSelected(false);
                }
                break ;
        }
    }


}
void GameSettings::update(){}

void GameSettings::draw(){
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    window->clear();

    this->textbox1.drawTo(window);
    this->textbox2.drawTo(window);
    this->btn1.drawTo(*window);

    window->display();
}

void GameSettings::nextState(){
    StateManager* stateManager = this->gameContext->getStateManager() ;
    stateManager->setState(new GamePlay(this->gameContext)) ;
    stateManager->getState()->init() ;
}
