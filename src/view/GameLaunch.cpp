#include "GameLaunch.h"
#include "Menu.h"
#include <iostream>

GameLaunch::GameLaunch(GameContext* gameContext): gameContext(gameContext)
{
    //ctor
}

GameLaunch::~GameLaunch()
{
    //dtor
}

GameLaunch::GameLaunch(const GameLaunch& other)
{
    this->duration = other.duration ;
    this->title = other.title ;
    this->titleFont = other.titleFont ;
    this->gameContext = other.gameContext ;
    this->goNextState = other.goNextState ;
    this->titleY = other.titleY;
    this->velocitytitleY = other.velocitytitleY;
    this->guideText = other.guideText ;
}

GameLaunch& GameLaunch::operator=(const GameLaunch& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->title = rhs.title ;
    this->titleFont = rhs.titleFont ;
    this->duration = rhs.duration ;
    this->gameContext = rhs.gameContext ;
    this->goNextState = rhs.goNextState ;
    this->titleY = rhs.titleY;
    this->velocitytitleY = rhs.velocitytitleY;
    this->guideText = rhs.guideText ;


    return *this;
}


void GameLaunch::init(){
    titleY = this->gameContext->getWindow()->getView().getCenter().y ;
    this->duration.restart() ;

    if (!titleFont.loadFromFile(FONT_PATH))
    {
        //handle error
    }

    //CREATE THE TILE
    title.setFont(titleFont);
    title.setColor(sf::Color::Green);
    title.setString("THE TRON GAME");
    title.setCharacterSize(70);

    sf::FloatRect titleRect = title.getLocalBounds();
    title.setOrigin(titleRect.left + titleRect.width/2.0f, titleRect.top  + titleRect.height/2.0f);
    title.setPosition(this->gameContext->getWindow()->getView().getCenter());

    //CREATE THE GUIDE TEXT
    guideText.setFont(titleFont);
    guideText.setColor(sf::Color::White);
    guideText.setString("press enter");
    guideText.setCharacterSize(20);

    sf::FloatRect guideTextRect = guideText.getLocalBounds();
    guideText.setOrigin(guideTextRect.left + guideTextRect.width/2.0f, guideTextRect.top  + guideTextRect.height/2.0f);
    guideText.setPosition({
                              this->gameContext->getWindow()->getView().getCenter().x,
                              (this->gameContext->getWindow()->getView().getCenter().y) + (this->gameContext->getWindow()->getView().getCenter().y/1.3)
                          });

}

void GameLaunch::processInput(){
    sf::Event event ;
    sf::RenderWindow* window = this->gameContext->getWindow() ;
    while (window->pollEvent(event)){
        if(event.type == sf::Event::Closed) window->close() ;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) this->goNextState= true ;
}

void GameLaunch::update(){
    if(goNextState && titleY > this->gameContext->getWindow()->getView().getCenter().y / 2){
        titleY += velocitytitleY ;
        title.setPosition({
              this->gameContext->getWindow()->getView().getCenter().x,
              titleY
              });
    }
    else if(goNextState){
        title.setPosition({
                this->gameContext->getWindow()->getView().getCenter().x,
                this->gameContext->getWindow()->getView().getCenter().y / 2
              });
              this->nextState() ;
    }
}

void GameLaunch::draw(){
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    window->clear() ;
    window->draw(title);
    if(!goNextState && this->duration.getElapsedTime().asSeconds() >= DISPLAY_GUIDE_DURATION)
        window->draw(guideText) ;
    window->display();
}

void GameLaunch::nextState(){
    StateManager* stateManager = this->gameContext->getStateManager() ;
    Menu* menu = new Menu(this->gameContext) ;
    stateManager->setState(menu);
    stateManager->getState()->init() ;

    delete menu ;
}

GameLaunch* GameLaunch::clone() {
    return new GameLaunch(*this) ;
}
