#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class TextBox
{
    private:
        sf::RectangleShape background;
        sf::Text textbox;
        std::ostringstream text;
        bool isSelected = false;
        int limit;

        void inputLogic(int charTyped);

        void deleteLastChar();

    public:
        TextBox(int size = 30, sf::Color color = sf::Color::Black, bool sel = false);
        virtual ~TextBox();
        TextBox(const TextBox& other);
        TextBox& operator=(const TextBox& rhs);

        void setFont(sf::Font &font);

        void setPosition(sf::Vector2f pos);

        void setLimit(int lim);

        void setSelected(bool sel);

        void setBorder(sf::Color color);

        std::string getText();

        void drawTo(sf::RenderWindow *window);

        void typedOn(sf::Event input);

        bool isMouseOver(sf::RenderWindow *window);

};

#endif // TEXTBOX_H
