#include "Playground.h"

Playground::Playground()
{
    //ctor
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
