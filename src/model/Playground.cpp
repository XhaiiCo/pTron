#include "Playground.h"
#include "Case.h"

Playground::Playground()
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


    return *this;
}



void Playground::init()
{
    this->createCase() ;
}

void Playground::createCase()
{
    for(int i = 0 ; i < Playground::NB_LINE ; i++)
    {
        std::vector<Case*> line ;

        for(int j = 0 ; j < Playground::NB_COLUMN ; j++)
        {
            line.push_back(new Case()) ;

            //juste pour tester si le joueur est bien ajouté
            /*
            Player p;
            line[j]->setPlayer(p);*/
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
