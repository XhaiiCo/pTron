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

    for(int i = 0 ; i < MAX_NUMBER_OF_COLORS ; i++){
        this->colorsPlayer1[i] = other.colorsPlayer1[i] ;
        this->colorsPlayer1[i] = other.colorsPlayer2[i] ;
    }

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

    for(int i = 0 ; i < MAX_NUMBER_OF_COLORS ; i++){
        this->colorsPlayer1[i] = rhs.colorsPlayer1[i] ;
        this->colorsPlayer1[i] = rhs.colorsPlayer2[i] ;
    }

    return *this;
}


void GameSettings::init(){
    //GET THE WINDOW FROM THE GAME CONTEXT
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    window->setKeyRepeatEnabled(true);

    font.loadFromFile("assets/fonts/Square-Bold.otf");

    //float windowWidth = window->getSize().x;

    float xPosTb = window->getSize().x / 6;
    float yPosTb = window->getSize().y / 7;

    //CREATE THE TEXTBOX FOR PLAYER 1 NAME
    this->tbNamePlayer1 = TextBox(30, sf::Color::Black, false);
    this->tbNamePlayer1.setFont(font);
    this->tbNamePlayer1.setPosition({xPosTb, yPosTb});
    this->tbNamePlayer1.setLimit(10);
    this->tbNamePlayer1.setBorder(sf::Color::White);
    this->tbNamePlayer1.setText("Player 1") ;

    //CREATE THE TEXTBOX FOR PLAYER 2 NAME
    this->tbNamePlayer2 = TextBox(30, sf::Color::Black, false);
    this->tbNamePlayer2.setFont(font);
    this->tbNamePlayer2.setPosition({xPosTb * 4.07, yPosTb});
    this->tbNamePlayer2.setLimit(10);
    this->tbNamePlayer2.setBorder(sf::Color::White);
    this->tbNamePlayer2.setText("Player 2") ;

    //CREATE THE PLAY BUTTON
    this->btnPlay = Button("PLAY", {270, 90}, 80, sf::Color::Black, sf::Color::Green);
    this->btnPlay.setPosition({window->getSize().x / 2, window->getSize().y / 1.4});
    this->btnPlay.setFont(font);
    this->btnPlay.setBorder(sf::Color::Green);

    colorsPlayer1[0].setColor(Color(29, 185, 175));//light blue
    colorsPlayer1[0].setSelected(true);
    colorsPlayer1[1].setColor(Color(209, 22, 36));//Blood red
    colorsPlayer1[2].setColor(Color(255, 128, 0));//Orange
    colorsPlayer1[3].setColor(Color(255, 51, 255));//Pink

    int decal = 0;
    for(int i = 0; i < MAX_NUMBER_OF_COLORS; i++)
    {
        colorsPlayer1[i].setPosition({window->getSize().x / 7.8 + decal, window->getSize().y / 2.5});
        decal += 80;
    }

    colorsPlayer2[0].setColor(Color(25, 25, 220));//Marine blue
    colorsPlayer2[0].setSelected(true);
    colorsPlayer2[1].setColor(Color(50, 220, 50));//Apple green
    colorsPlayer2[2].setColor(Color(150, 50, 200));//Purple
    colorsPlayer2[3].setColor(Color(245,222,179));//Wheat

    decal = 0;
    for(int i = 0; i < MAX_NUMBER_OF_COLORS; i++)
    {
        colorsPlayer2[i].setPosition({window->getSize().x / 1.57 + decal, window->getSize().y / 2.5});
        decal += 80;
    }
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
                    btnPlay.setBackColor(sf::Color::Black);
                }
                break;

            case sf::Event::MouseButtonPressed:
                if(tbNamePlayer1.isMouseOver(*window))
                {
                    tbNamePlayer1.setSelected(true);
                    tbNamePlayer1.setBorder(sf::Color::Green);
                    tbNamePlayer2.setSelected(false);
                    tbNamePlayer2.setBorder(sf::Color::Transparent);
                }
                else if(tbNamePlayer2.isMouseOver(*window))
                {
                    tbNamePlayer2.setSelected(true);
                    tbNamePlayer2.setBorder(sf::Color::Green);
                    tbNamePlayer1.setSelected(false);
                    tbNamePlayer1.setBorder(sf::Color::Transparent);
                }
                else if(btnPlay.isMouseOver(*window))
                {
                    this->applySettingToPlayers() ;
                    this->nextState() ;
                }

                for(int i = 0 ; i < MAX_NUMBER_OF_COLORS ; i++){
                    if(colorsPlayer1[i].isMouseOver(*window)){
                        unselectAll(colorsPlayer1) ;
                        colorsPlayer1[i].setSelected(true) ;
                    }
                    else if(colorsPlayer2[i].isMouseOver(*window)){
                        unselectAll(colorsPlayer2) ;
                        colorsPlayer2[i].setSelected(true) ;
                    }
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

    for(int i = 0; i < MAX_NUMBER_OF_COLORS; i++)
    {
        colorsPlayer1[i].drawTo(*window);
    }

    for(int i = 0; i < MAX_NUMBER_OF_COLORS; i++)
    {
        colorsPlayer2[i].drawTo(*window);
    }

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
    p1->setMainColor(findSelectedColor(colorsPlayer1));
    p1->setGodModeColor(Color(255, 255, 0)) ;
    p2->setMainColor(findSelectedColor(colorsPlayer2)) ;
    p2->setGodModeColor(Color(255, 255, 0)) ;

    p1->setScore(0) ;
    p2->setScore(0) ;
}

void GameSettings::unselectAll(ColorTile * colorsPlayer)
{
    for(int i = 0; i < MAX_NUMBER_OF_COLORS; i++)
    {
        colorsPlayer[i].setSelected(false);
    }

}

Color GameSettings::findSelectedColor(ColorTile * colorsPlayer){
    for(int i = 0 ; i < MAX_NUMBER_OF_COLORS ; i++){
        if(colorsPlayer[i].isSelected()) return colorsPlayer[i].getColor() ;
    }

    return Color(255, 0, 0) ;
}
