#include "GameLaunch.h"
#include "Menu.h"
#include <iostream>

GameLaunch::GameLaunch(StateManager* stateManager, sf::RenderWindow* window, int windowWidth, int windowHeight): window(window), stateManager(stateManager), windowWidth(windowWidth), windowHeight(windowHeight)
{
    //ctor
}

GameLaunch::~GameLaunch()
{
    //dtor
}

GameLaunch::GameLaunch(const GameLaunch& other)
{
    //copy ctor
}

GameLaunch& GameLaunch::operator=(const GameLaunch& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


void GameLaunch::init(){
    this->duration.restart() ;

    if (!font.loadFromFile("arial.ttf"))
    {
        //handle error
    }

    //CREATE THE TILE
    title.setFont(font);
    title.setColor(sf::Color::Blue);
    title.setString("THE TRON GAME !");
    title.setPosition(sf::Vector2f(windowWidth / 2 - 100, windowHeight / 2 - 20));
}

void GameLaunch::processInput(){
    sf::Event event;
    while (window->pollEvent(event)){
        if(event.type == sf::Event::Closed) window->close() ;
    }
}

void GameLaunch::update(){
    if(this->duration.getElapsedTime().asSeconds() >= LAUNCH_SCREEN_DURATION_IN_SECONDS)
        this->nextState() ;
}

void GameLaunch::draw(){
    this->window->clear() ;
    this->window->draw(title);
    this->window->display();
}

void GameLaunch::nextState(){
    this->stateManager->setState(new Menu(this->stateManager, this->window, windowWidth, windowHeight)) ;
    this->stateManager->getState()->init() ;
}
