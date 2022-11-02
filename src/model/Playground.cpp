#include "Playground.h"

Playground::Playground()
{}

Playground::~Playground()
{
    //Remove cases
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
    //Remove cases
    for(std::vector<Case*> line : this->cases)
    {
        for(Case* c : line)
        {
            delete c;
        }
    }
    this->cases.clear();

    //Clear players list but not delete, because their don't belong to playground.
    this->players.clear() ;

    //Add cases
    for(std::vector<Case*> otherLine : other.cases)
    {
        std::vector<Case*> line;

        for(Case* c : otherLine)
        {
            line.push_back(new Case(*c));
        }

        this->cases.push_back(line);
    }

    //Add players
    for(Player* p: other.players)
        this->players.push_back(p) ;
}

Playground& Playground::operator=(const Playground& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    //Delete cases
    for(std::vector<Case*> line : this->cases)
    {
        for(Case* c : line)
        {
            delete c;
        }
    }
    this->cases.clear();

    //Clear players list but not delete, because their don't belong to playground.
    this->players.clear() ;

    //Add cases
    for(std::vector<Case*> rhsLine : rhs.cases)
    {
        std::vector<Case*> line;

        for(Case* c : rhsLine)
        {
            line.push_back(new Case(*c));
        }

        this->cases.push_back(line);
    }

    //add players
    for(Player* p: rhs.players)
        this->players.push_back(p) ;

    return *this;
}

void Playground::init(Player* player1, Player* player2)
{
    this->players.push_back(player1) ;
    this->players.push_back(player2) ;

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
    for(Player* p: this->players)
        p->movePlayer() ;
}

bool Playground::isPlayerHasLost(int id){
    if(!validPlayerId(id)) return false ;

    //If the player is in god mode he can't loose
    if(this->players[id]->isGodMode()) return false ;

    //If the case where the player goes isn't empty, he loses.
    if(this->cases[this->players[id]->getY()][this->players[id]->getX()]->getPlayer() != nullptr) return true ;
    return false ;
}

void Playground::displayplayers(){
    //For each player, put it in the case according to its x and y
    for(Player* p : this->players)
        this->cases[p->getY()][p->getX()]->setPlayer(p) ;
}
