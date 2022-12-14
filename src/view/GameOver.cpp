#include "GameOver.h"
#include "GamePlay.h"
#include "Menu.h"

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
    Color titleColor = Color(255,255,255);
    if(p1->getWin()) {
        titleText = p1->getName() + " won the game !";
        titleColor = p1->getMainColor() ;
    }
    else if(p2->getWin()){
        titleText = p2->getName()+ " won the game !" ;
        titleColor = p2->getMainColor() ;
    }
    else titleText = "Match draw" ;

    //CREATE THE TITLE
    title.setFont(font);
    title.setCharacterSize(60);
    title.setColor(sf::Color(titleColor.getRed(), titleColor.getGreen(), titleColor.getBlue()));
    title.setString(titleText);

    //POSITION THE TITLE
    sf::FloatRect titleRect = title.getLocalBounds();
    title.setOrigin(titleRect.left + titleRect.width/2.0f, titleRect.top  + titleRect.height/2.0f);
    title.setPosition(sf::Vector2f(windowWidth / 2, windowHeight / 5));


    //SCORE PLAYER 1
    scorePlayer1.setFont(font);
    scorePlayer1.setColor(sf::Color(p1->getMainColor().getRed(), p1->getMainColor().getGreen(), p1->getMainColor().getBlue()));
    scorePlayer1.setString(std::to_string(p1->getScore()));
    scorePlayer1.setCharacterSize(70);
    scorePlayer1.setPosition(sf::Vector2f(windowWidth / 2.4, windowHeight / 3.4));

    //SCORE PLAYER 2
    scorePlayer2.setFont(font);
    scorePlayer2.setColor(sf::Color(p2->getMainColor().getRed(), p2->getMainColor().getGreen(), p2->getMainColor().getBlue()));
    scorePlayer2.setString(std::to_string(p2->getScore()));
    scorePlayer2.setCharacterSize(70);
    scorePlayer2.setPosition(sf::Vector2f(windowWidth / 1.81, windowHeight / 3.4));

    sf::FloatRect textRect;
    float x = 1.5;

    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        textBtn[i].setFont(font);
        textBtn[i].setColor(sf::Color::White);
        textBtn[i].setString(btnNames[i]);
        textBtn[i].setCharacterSize(70);
        textRect = textBtn[i].getLocalBounds();
        textBtn[i].setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
        x += 0.6;
        textBtn[i].setPosition(sf::Vector2f(windowWidth / 2, windowHeight / (MAX_NUMBER_OF_ITEMS + 1) * x));
    }
    textBtn[0].setColor(sf::Color::Green);

    selectedItemIndex = 0;

}
void GameOver::processInput(){
    sf::Event event;
    sf::RenderWindow* window = this->gameContext->getWindow() ;
    while (window->pollEvent(event)){
        if(event.type == sf::Event::Closed) window->close() ;

        if(event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::Up) this->MoveUp() ;
            else if(event.key.code == sf::Keyboard::Down) this->MoveDown() ;
            else if(event.key.code == sf::Keyboard::Enter){
                int pressedItem = this->GetPressedItem();

                if(pressedItem == 0)
                {
                    this->nextState() ;
                }
                else if(pressedItem == 1)
                {
                    StateManager* stateManager = this->gameContext->getStateManager() ;
                    Menu* menu= new Menu(this->gameContext) ;
                    stateManager->setState(menu) ;
                    stateManager->getState()->init() ;

                    delete menu ;
                }
                else
                {
                    window->close();
                }
            }
        }
    }
}

void GameOver::update(){}

void GameOver::draw(){
    sf::RenderWindow* window = this->gameContext->getWindow() ;

    window->clear() ;
    window->draw(this->title) ;
    window->draw(this->scorePlayer1) ;
    window->draw(this->scorePlayer2) ;
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window->draw(textBtn[i]);
    }
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

void GameOver::MoveUp()
{
    if(selectedItemIndex - 1 >= 0)
    {
        textBtn[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        textBtn[selectedItemIndex].setColor(sf::Color::Green);
    }
}

void GameOver::MoveDown()
{

    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        textBtn[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        textBtn[selectedItemIndex].setColor(sf::Color::Green);
    }
}

int GameOver::GetPressedItem() const
{
    return selectedItemIndex;
}
