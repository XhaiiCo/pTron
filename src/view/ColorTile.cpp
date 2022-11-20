#include "ColorTile.h"

ColorTile::ColorTile(sf::Vector2f size,  sf::Color color)
{
    tile.setSize(size);
    tile.setFillColor(color);
}

ColorTile::~ColorTile()
{
    //dtor
}

ColorTile::ColorTile(const ColorTile& other)
{
    this->tile = other.tile ;
}

ColorTile& ColorTile::operator=(const ColorTile& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->tile = rhs.tile ;

    return *this;
}

void ColorTile::setColor(sf::Color color)
{
    tile.setFillColor(color);
}

void ColorTile::setPosition(sf::Vector2f pos)
{
    tile.setPosition(pos);
}

void ColorTile::setBorder(sf::Color color)
{
    tile.setOutlineColor(color);
    tile.setOutlineThickness(3);
}

void ColorTile::drawTo(sf::RenderWindow &window)
{
    if(selected){
        this->setBorder(sf::Color::White) ;
    }
    else{
        this->setBorder(sf::Color::Transparent);
    }

    window.draw(tile);
}

void ColorTile::setSelected(bool sel)
{
    selected = sel;
}

bool ColorTile::isSelected()
{
    return selected;
}

bool ColorTile::isMouseOver(sf::RenderWindow &window)
{
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float tilePosX = tile.getPosition().x;
    float tilePosY = tile.getPosition().y;

    float tilexPosWith = tile.getPosition().x + tile.getLocalBounds().width;
    float tileyPosHeight = tile.getPosition().y + tile.getLocalBounds().height;

    if(mouseX < tilexPosWith && mouseX > tilePosX && mouseY < tileyPosHeight && mouseY > tilePosY)
    {
        return true;
    }
    return false;
}
