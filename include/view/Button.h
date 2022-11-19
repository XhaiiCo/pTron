#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>


class Button
{
    private:
        sf::RectangleShape button;
        sf::Text text;

    public:
        Button(std::string t = "button", sf::Vector2f size = {200, 50}, int charSize = 30, sf::Color bgColor = sf::Color::Green, sf::Color textColor = sf::Color::Black);
        Button(const Button& other);
        Button& operator=(const Button& other);


        void setBorder(sf::Color color);

        void setFont(sf::Font &font);

        void setBackColor(sf::Color color);

        void setTextColor(sf::Color color);

        void setPosition(sf::Vector2f pos);

        void drawTo(sf::RenderWindow &window);

        bool isMouseOver(sf::RenderWindow &window);

};

#endif // BUTTON_H
