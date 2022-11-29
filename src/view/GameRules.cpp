#include "GameRules.h"

GameRules::GameRules(GameContext* gameContext)
{
    this->gameContext = gameContext ;
}

GameRules::~GameRules()
{
    //dtor
}

GameRules::GameRules(const GameRules& other)
{
    this->gameContext = other.gameContext ;
}

GameRules& GameRules::operator=(const GameRules& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    this->gameContext = rhs.gameContext ;

    return *this;
}

void GameRules::init()
{
    if (!font.loadFromFile(FONT_PATH))
    {
        //handle error
    }

    float width = this->gameContext->getWindowWidth() ;
    float height = this->gameContext->getWindowHeight() ;

    sf::FloatRect textRect;
    float x = 1.5;

    for(int i = 0; i < MAX_NUMBER_OF_LINES; i++)
    {
        rulesText[i].setFont(font);
        rulesText[i].setColor(sf::Color::Green);
        rulesText[i].setString(rulesLines[i]);
        rulesText[i].setCharacterSize(36);
        textRect = rulesText[i].getLocalBounds();
        rulesText[i].setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
        x += 0.6;
        rulesText[i].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_LINES + 3) * x));
    }


    txtBtn.setFont(font);
    txtBtn.setColor(sf::Color::White);
    txtBtn.setString("Return");
    txtBtn.setCharacterSize(28);
    textRect = txtBtn.getLocalBounds();
    txtBtn.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    txtBtn.setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_LINES + 1) * 7));



}

void GameRules::processInput(){

    sf::Event event;
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    while (window->pollEvent(event)){
        if(event.type == sf::Event::Closed) window->close() ;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        //retour au menu
    }
}

void GameRules::update(){}

void GameRules::draw()
{
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    window->clear();

    for(int i = 0; i < MAX_NUMBER_OF_LINES; i++)
    {
        window->draw(rulesText[i]);
    }
    window->draw(txtBtn);

    window->display();
}

void GameRules::nextState(){}

GameRules* GameRules::clone(){
    return new GameRules(*this) ;
}
