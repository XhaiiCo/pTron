#ifndef COLORTILE_H
#define COLORTILE_H

#include <SFML/Graphics.hpp>
#include "Color.h"

class ColorTile
{
    private:
        sf::RectangleShape tile;
        bool selected = false;
        Color color ;

    public:
        ColorTile(sf::Vector2f size = {60, 60}, Color color = Color(255, 0, 0));
        virtual ~ColorTile();
        ColorTile(const ColorTile& other);
        ColorTile& operator=(const ColorTile& other);

        void setColor(Color color);

        Color getColor() {return this->color ; }

        void setPosition(sf::Vector2f pos);

        void setBorder(sf::Color color);

        void drawTo(sf::RenderWindow &window);

        void setSelected(bool sel);

        bool isSelected();

        bool isMouseOver(sf::RenderWindow &window);
};

#endif // COLORTILE_H
