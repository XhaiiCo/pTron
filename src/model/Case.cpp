#include "Case.h"

Case::Case()
{
    //ctor
}

Case::~Case()
{
    //dtor
}

Case::Case(const Case& other)
{
    //copy ctor
}

Case& Case::operator=(const Case& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
