#include "Color.h"

Color::Color(int red, int green, int blue): red(red), green(green), blue(blue)
{
    //ctor
}

Color::~Color()
{
    //dtor
}

Color::Color(const Color& other)
{
    this->red = other.red ;
    this->green = other.green ;
    this->blue = other.blue ;
}

Color& Color::operator=(const Color& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->red = rhs.red ;
    this->green = rhs.green ;
    this->blue = rhs.blue ;

    return *this;
}


bool Color::validColor(int value){
    if(value < 0 || value > 255) return false ;

    return true ;
}

bool Color::setRed(int value){
    if(this-validColor(value)){
        this->red = value ;
        return true ;
    }
    return false ;
}
bool Color::setGreen(int value){
    if(this-validColor(value)){
        this->green = value ;
        return true ;
    }
    return false ;
}
bool Color::setBlue(int value){
    if(this-validColor(value)){
        this->blue = value ;
        return true ;
    }
    return false ;
}
