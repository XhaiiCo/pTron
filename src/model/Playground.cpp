#include "Playground.h"
#include "Case.h"

Playground::Playground()
{
    this->init() ;
}

Playground::~Playground()
{
    //dtor
}

Playground::Playground(const Playground& other)
{
    //copy ctor
}

Playground& Playground::operator=(const Playground& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}



void Playground::init() {
    this->createCase() ;
}

void Playground::createCase(){
    for(int i = 0 ; i < Playground::NB_LINE ; i++){
        std::vector<Case*> line ;
        for(int j = 0 ; j < Playground::NB_COLUMN ; j++){
            line.push_back(new Case()) ;
        }
        this->cases.push_back(line) ;
    }
}


std::string Playground::str() const{
    std::string result = "" ;
    for(std::vector<Case*> line : this->cases){
        for(Case* c : line){
            result += " " + c->str() + " ";
        }
        result += "\n" ;
    }

    return result ;
}
