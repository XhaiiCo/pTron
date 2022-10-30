#include <iostream>
#include "Playground.h"
#include "Case.h"


Playground::Playground(Player player1, Player player2): player1(player1), player2(player2)
{
    this->init() ;
}

Playground::~Playground()
{
    for(std::vector<Case*> line : this->cases)
    {
        for(Case* c : line)
        {
            delete c;
        }
    }
    this->cases.clear();
}

Playground::Playground(const Playground& other)
{
    for(std::vector<Case*> otherLine : other.cases)
    {
        std::vector<Case*> line;

        for(Case* c : otherLine)
        {
            line.push_back(new Case(*c));
        }

        this->cases.push_back(line);

        this->player1 = other.player1 ;
        this->player2 = other.player2 ;
    }
}

Playground& Playground::operator=(const Playground& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    for(std::vector<Case*> line : this->cases)
    {
        for(Case* c : line)
        {
            delete c;
        }
    }

    this->cases.clear();

    for(std::vector<Case*> rhsLine : rhs.cases)
    {
        std::vector<Case*> line;

        for(Case* c : rhsLine)
        {
            line.push_back(new Case(*c));
        }

        this->cases.push_back(line);
    }

    this->player1 = rhs.player1 ;
    this->player2 = rhs.player2 ;

    return *this;
}


//Init the playground
void Playground::init()
{
    this->createCase() ;
}

//Fill the matrix with empty cells
void Playground::createCase()
{
    for(int i = 0 ; i < Playground::NB_LINE ; i++)
    {
        std::vector<Case*> line ;

        for(int j = 0 ; j < Playground::NB_COLUMN ; j++)
        {
            line.push_back(new Case()) ;
        }

        this->cases.push_back(line) ;
    }
}

std::string Playground::str() const
{
    std::string result = "" ;

    for(std::vector<Case*> line : this->cases)
    {
        for(Case* c : line)
        {
            result += " " + c->str() + " ";
        }
        result += "\n" ;
    }

    return result ;
}

//Change the direction of the player 1
bool Playground::changeDirectionPlayer1(int dirX, int dirY){
    return player1.changeDirection(dirX, dirY) ;
}

//Change the direction of the player 2
bool Playground::changeDirectionPlayer2(int dirX, int dirY){
    return player2.changeDirection(dirX, dirY) ;
}

//Moves the player one square forward according to his direction
void Playground::movePlayers(){
    this->player1.movePlayer() ;
    this->cases[this->player1.getY()][this->player1.getX()]->setPlayer(&player1) ;

    this->player2.movePlayer() ;
    this->cases[this->player2.getY()][this->player2.getX()]->setPlayer(&player2) ;
}
