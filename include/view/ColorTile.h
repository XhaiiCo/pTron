#ifndef COLORTILE_H
#define COLORTILE_H

#include <SFML/Graphics.hpp>

class ColorTile
{
    private:
        sf::RectangleShape tile;
        bool selected = false;

    public:
        ColorTile(sf::Vector2f size = {60, 60}, sf::Color color = sf::Color::Red);
        virtual ~ColorTile();
        ColorTile(const ColorTile& other);
        ColorTile& operator=(const ColorTile& other);

        void setColor(sf::Color color);

        void setPosition(sf::Vector2f pos);

        void setBorder(sf::Color color);

        void drawTo(sf::RenderWindow &window);

        void setSelected(bool sel);

        bool isSelected();

        bool isMouseOver(sf::RenderWindow &window);
};

#endif // COLORTILE_H
