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
    this->gameContext = other.gameContext ;
    this->font = other.font ;
    this->tbNamePlayer1 = other.tbNamePlayer1 ;
    this->tbNamePlayer2 = other.tbNamePlayer2 ;
    this->btnPlay = other.btnPlay ;
}

GameSettings& GameSettings::operator=(const GameSettings& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->gameContext = rhs.gameContext ;
    this->font = rhs.font ;
    this->tbNamePlayer1 = rhs.tbNamePlayer1 ;
    this->tbNamePlayer2 = rhs.tbNamePlayer2 ;
    this->btnPlay = rhs.btnPlay ;

    return *this;
}


void GameSettings::init(){
    //GET THE WINDOW FROM THE GAME CONTEXT
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    window->setKeyRepeatEnabled(true);

    font.loadFromFile("assets/fonts/Square-Bold.otf");

    //CREATE THE TEXTBOX FOR PLAYER 1 NAME
    this->tbNamePlayer1 = TextBox(30, sf::Color::Black, false);
    this->tbNamePlayer1.setFont(font);
    this->tbNamePlayer1.setPosition({300, 100});
    this->tbNamePlayer1.setLimit(10);
    this->tbNamePlayer1.setBorder(sf::Color::White);
    this->tbNamePlayer1.setText("Player 1") ;

    //CREATE THE TEXTBOX FOR PLAYER 2 NAME
    this->tbNamePlayer2 = TextBox(30, sf::Color::Black, false);
    this->tbNamePlayer2.setFont(font);
    this->tbNamePlayer2.setPosition({1200, 100});
    this->tbNamePlayer2.setLimit(10);
    this->tbNamePlayer2.setBorder(sf::Color::White);
    this->tbNamePlayer2.setText("Player 2") ;

    //CREATE THE PLAY BUTTON
    this->btnPlay = Button("PLAY", {300, 100}, 80, sf::Color::Green, sf::Color::White);
    this->btnPlay.setPosition(this->gameContext->getWindow()->getView().getCenter());
    this->btnPlay.setFont(font);
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
                    this->applySettingToPlayers() ;
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
    GamePlay* gamePlay = new GamePlay(this->gameContext) ;
    stateManager->setState(gamePlay) ;
    stateManager->getState()->init() ;

    delete gamePlay ;
}

GameSettings* GameSettings::clone() {
    return new GameSettings(*this) ;
}

void GameSettings::applySettingToPlayers(){
    Player* p1 = this->gameContext->getPlayer1() ;
    Player* p2 = this->gameContext->getPlayer2() ;

    std::string namePlayer1 = this->tbNamePlayer1.getText() ;
    if(namePlayer1 == "") namePlayer1 = "Player 1" ;

    std::string namePlayer2 = this->tbNamePlayer2.getText() ;
    if(namePlayer2 == "") namePlayer2 = "Player 2" ;

    p1->setName(namePlayer1) ;
    p2->setName(namePlayer2) ;
    p1->setMainColor(Color(0, 255, 0));
    p1->setGodModeColor(Color(255, 255, 0)) ;
    p2->setMainColor(Color(0, 0, 255)) ;
    p2->setGodModeColor(Color(255, 255, 0)) ;
}
