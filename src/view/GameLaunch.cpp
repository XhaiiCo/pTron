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
    this->font = other.font ;
    this->gameContext = other.gameContext ;
}

GameLaunch& GameLaunch::operator=(const GameLaunch& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->duration = rhs.duration ;
    this->title = rhs.title ;
    this->font = rhs.font ;
    this->gameContext = rhs.gameContext ;


    return *this;
}


void GameLaunch::init(){
    this->duration.restart() ;

    if (!font.loadFromFile(FONT_PATH))
    {
        //handle error
    }

    //CREATE THE TILE
    title.setFont(font);
    title.setColor(sf::Color::Green);
    title.setString("THE TRON GAME");
    title.setCharacterSize(70);

    sf::FloatRect titleRect = title.getLocalBounds();
    title.setOrigin(titleRect.left + titleRect.width/2.0f, titleRect.top  + titleRect.height/2.0f);

    //title.setPosition(sf::Vector2f(this->gameContext->getWindowWidth() / 2 - 100, this->gameContext->getWindowHeight() / 2 - 20));

    title.setPosition(this->gameContext->getWindow()->getView().getCenter());
}

void GameLaunch::processInput(){
    sf::Event event ;
    sf::RenderWindow* window = this->gameContext->getWindow() ;
    while (window->pollEvent(event)){
        if(event.type == sf::Event::Closed) window->close() ;
    }
}

void GameLaunch::update(){
    if(this->duration.getElapsedTime().asSeconds() >= LAUNCH_SCREEN_DURATION_IN_SECONDS)
        this->nextState() ;
}

void GameLaunch::draw(){
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    window->clear() ;
    window->draw(title);
    window->display();
}

void GameLaunch::nextState(){
    StateManager* stateManager = this->gameContext->getStateManager() ;

    stateManager->setState(new Menu(this->gameContext)) ;
    stateManager->getState()->init() ;
}

GameLaunch* GameLaunch::clone() {
    return new GameLaunch(*this) ;
}
