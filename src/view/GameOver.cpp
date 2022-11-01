#include "GameOver.h"

GameOver::GameOver(StateManager* stateManager, sf::RenderWindow* window, int windowWidth, int windowHeight)
    : stateManager(stateManager), window(window), windowWidth(windowWidth), windowHeight(windowHeight){}

GameOver::~GameOver()
{
    //dtor
}

GameOver::GameOver(const GameOver& other)
{
    //copy ctor
}

GameOver& GameOver::operator=(const GameOver& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void GameOver::init(){
    if (!font.loadFromFile("arial.ttf"))
    {
        //handle error
    }

    //CREATE THE TILE
    title.setFont(font);
    title.setColor(sf::Color::Blue);
    title.setString("Game Over broooo");
    title.setPosition(sf::Vector2f(windowWidth / 2 - 100, windowHeight / 2 - 100));
}
void GameOver::processInput(){
    sf::Event event;
    while (window->pollEvent(event)){
        if(event.type == sf::Event::Closed) window->close() ;
    }
}
void GameOver::update(){}
void GameOver::draw(){
    this->window->clear() ;
    this->window->draw(this->title) ;
    this->window->display();
}
void GameOver::nextState(){}
