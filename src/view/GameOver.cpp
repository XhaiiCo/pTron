#include "GameOver.h"
#include "GamePlay.h"

GameOver::GameOver(GameContext* gameContext): gameContext(gameContext){}

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
    if (!font.loadFromFile(FONT_PATH))
    {
        //handle error
    }

    float windowWidth = this->gameContext->getWindowWidth() ;
    float windowHeight = this->gameContext->getWindowHeight() ;
    Player* p1 = this->gameContext->getPlayer1() ;
    Player* p2 = this->gameContext->getPlayer2() ;

    //CREATE THE TILE
    title.setFont(font);
    title.setColor(sf::Color::Red);
    title.setString("Game Over broooo");
    title.setPosition(sf::Vector2f(windowWidth / 2, windowHeight / 4));

    //SCORE PLAYEE 1
    scorePlayer1.setFont(font);
    scorePlayer1.setColor(sf::Color(p1->getMainColor().getRed(), p1->getMainColor().getGreen(), p1->getMainColor().getBlue()));
    scorePlayer1.setString("2");
    scorePlayer1.setPosition(sf::Vector2f(windowWidth / 4, windowHeight / 2));

    //SCORE PLAYEE 2
    scorePlayer2.setFont(font);
    scorePlayer2.setColor(sf::Color(p2->getMainColor().getRed(), p2->getMainColor().getGreen(), p2->getMainColor().getBlue()));
    scorePlayer2.setString("6");
    scorePlayer2.setPosition(sf::Vector2f((windowWidth / 4)*2, windowHeight / 2));
}
void GameOver::processInput(){
    sf::Event event;
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    while (window->pollEvent(event)){
        if(event.type == sf::Event::Closed) window->close() ;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) this->nextState();
}

void GameOver::update(){}

void GameOver::draw(){
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    window->clear() ;
    window->draw(this->title) ;
    window->draw(this->scorePlayer1) ;
    window->draw(this->scorePlayer2) ;
    window->display();
}

void GameOver::nextState(){
    StateManager* stateManager = this->gameContext->getStateManager() ;
    stateManager->setState(new GamePlay(this->gameContext)) ;
    stateManager->getState()->init() ;
}
