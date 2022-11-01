#include <iostream>
#include "Playground.h" nom, nom, Residence Residence
#include "Case.h"


Playground::Playground(Player* player1, Player* player2)
{
    this->players.push_back(player1) ;
    this->players.push_back(player2) ;
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
    for(std::vector<Case*> line : this->cases)
    {
        for(Case* c : line)
        {
            delete c;
        }
    }
    this->cases.clear();

    for(Player* p : players)
        delete p ;

    this->players.clear() ;

    for(std::vector<Case*> otherLine : other.cases)
    {
        std::vector<Case*> line;

        for(Case* c : otherLine)
        {
            line.push_back(new Case(*c));
        }

        this->cases.push_back(line);
    }

    for(Player* p: other.players)
        this->players.push_back(p) ;
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

    for(Player* p : players)
        delete p ;
    this->players.clear() ;

    for(std::vector<Case*> rhsLine : rhs.cases)
    {
        std::vector<Case*> line;

        for(Case* c : rhsLine)
        {
            line.push_back(new Case(*c));
        }

        this->cases.push_back(line);
    }

    for(Player* p: rhs.players)
        this->players.push_back(p) ;

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

bool Playground::validPlayerId(int id){
    if(id >= 0 && id < NB_PLAYERS) return true ;

    return false ;
}

//Moves the player one square forward according to his direction
void Playground::movePlayers(){
//    for(Player* p: this->players)
//        p->movePlayer() ;
    players[0]->movePlayer() ;
    players[1]->movePlayer() ;
}

bool Playground::isPlayerHasLost(int id){
    if(!validPlayerId(id)) return false ;
    if(this->players[id]->isGodMode()) return false ;

    if(this->cases[this->players[id]->getY()][this->players[id]->getX()]->getPlayer() != nullptr) return true ;
    return false ;
}

void Playground::displayplayers(){
    for(Player* p : this->players)
        this->cases[p->getY()][p->getX()]->setPlayer(p) ;
}
