#include "GameOver.h"
#include "GamePlay.h"

GameOver::GameOver(GameContext* gameContext): gameContext(gameContext){}

GameOver::~GameOver()
{
    //dtor
}

GameOver::GameOver(const GameOver& other)
{
    this->gameContext = other.gameContext ;
    this->font = other.font ;
    this->title = other.title ;
    this->scorePlayer1 = other.scorePlayer1 ;
    this->scorePlayer2 = other.scorePlayer2 ;
}

GameOver& GameOver::operator=(const GameOver& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->gameContext = rhs.gameContext ;
    this->font = rhs.font ;
    this->title = rhs.title ;
    this->scorePlayer1 = rhs.scorePlayer1 ;
    this->scorePlayer2 = rhs.scorePlayer2 ;

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

    //Set the title text
    std::string titleText = "" ;
    if(p1->getWin()) titleText = p1->getName() + " won the game !";
    else if(p2->getWin()) titleText = p2->getName()+ " won the game !" ;
    else titleText = "Match draw" ;

    //CREATE THE TITLE
    title.setFont(font);
    title.setCharacterSize(60);
    title.setColor(sf::Color::Red);
    title.setString(titleText);

    //POSITION THE TITLE
    sf::FloatRect titleRect = title.getLocalBounds();
    title.setOrigin(titleRect.left + titleRect.width/2.0f, titleRect.top  + titleRect.height/2.0f);
    title.setPosition(this->gameContext->getWindow()->getView().getCenter());

    //SCORE PLAYER 1
    scorePlayer1.setFont(font);
    scorePlayer1.setColor(sf::Color(p1->getMainColor().getRed(), p1->getMainColor().getGreen(), p1->getMainColor().getBlue()));
    scorePlayer1.setString(std::to_string(p1->getScore()));
    scorePlayer1.setPosition(sf::Vector2f(windowWidth / 4, windowHeight / 2));

    //SCORE PLAYER 2
    scorePlayer2.setFont(font);
    scorePlayer2.setColor(sf::Color(p2->getMainColor().getRed(), p2->getMainColor().getGreen(), p2->getMainColor().getBlue()));
    scorePlayer2.setString(std::to_string(p2->getScore()));
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
    GamePlay* gamePlay = new GamePlay(this->gameContext) ;
    stateManager->setState(gamePlay) ;
    stateManager->getState()->init() ;

    delete gamePlay ;
}

GameOver* GameOver::clone() {
    return new GameOver(*this) ;
}
