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

    font.loadFromFile("assets/fonts/Square-Bold.otf");
    this->tbNamePlayer1 = TextBox(30, sf::Color::Black, false);
    this->tbNamePlayer1.setFont(font);
    this->tbNamePlayer1.setPosition({300, 100});
    this->tbNamePlayer1.setLimit(10);
    this->tbNamePlayer1.setBorder(sf::Color::White);
    this->tbNamePlayer1.setText("Player 1") ;

    this->tbNamePlayer2 = TextBox(30, sf::Color::Black, false);
    this->tbNamePlayer2.setFont(font);
    this->tbNamePlayer2.setPosition({1200, 100});
    this->tbNamePlayer2.setLimit(10);
    this->tbNamePlayer2.setBorder(sf::Color::White);
    this->tbNamePlayer2.setText("Player 2") ;

    this->btnPlay = Button("PLAY", {200, 50}, 30, sf::Color::Green, sf::Color::Black);
    this->btnPlay .setPosition({760,600});
    this->btnPlay .setFont(font);
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
                tbNamePlayer1.typedOn(event);
                tbNamePlayer2.typedOn(event);
                break;

            case sf::Event::MouseMoved:
                if(btnPlay.isMouseOver(*window))
                {
                    btnPlay.setBackColor(sf::Color::White);
                }
                else
                {
                    btnPlay.setBackColor(sf::Color::Green);
                }
                break;

            case sf::Event::MouseButtonPressed:
                if(tbNamePlayer1.isMouseOver(*window))
                {
                    tbNamePlayer1.setSelected(true);
                    tbNamePlayer1.setBorder(sf::Color::Green);
                    tbNamePlayer2.setSelected(false);
                    tbNamePlayer2.setBorder(sf::Color::White);
                }
                else if(tbNamePlayer2.isMouseOver(*window))
                {
                    tbNamePlayer2.setSelected(true);
                    tbNamePlayer2.setBorder(sf::Color::Green);
                    tbNamePlayer1.setSelected(false);
                    tbNamePlayer1.setBorder(sf::Color::White);
                }
                else if(btnPlay.isMouseOver(*window))
                {
                    std::string namePlayer1 = this->tbNamePlayer1.getText() ;
                    if(namePlayer1 == "") namePlayer1 = "Player 1" ;

                    std::string namePlayer2 = this->tbNamePlayer2.getText() ;
                    if(namePlayer2 == "") namePlayer2 = "Player 2" ;

                    this->gameContext->setNamePlayer1(namePlayer1) ;
                    this->gameContext->setNamePlayer2(namePlayer2) ;

                    this->nextState() ;

                }
                else
                {
                    tbNamePlayer1.setSelected(false);
                    tbNamePlayer2.setSelected(false);
                }
                break ;
        }
    }


}
void GameSettings::update(){}

void GameSettings::draw(){
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    window->clear();

    this->tbNamePlayer1.drawTo(*window);
    this->tbNamePlayer2.drawTo(*window);
    this->btnPlay.drawTo(*window);

    window->display();
}

void GameSettings::nextState(){
    StateManager* stateManager = this->gameContext->getStateManager() ;
    stateManager->setState(new GamePlay(this->gameContext)) ;
    stateManager->getState()->init() ;
}
