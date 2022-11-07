#include "Button.h"

Button::Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
{
    text.setString(t);
    text.setColor(textColor);
    text.setCharacterSize(charSize);

    button.setSize(size);
    button.setFillColor(bgColor);
}

Button::Button(const Button& other)
{
    this->button = other.button ;
    this->text = other.text ;
}

Button& Button::operator=(const Button& rhs)
{
    this->button = rhs.button ;
    this->text = rhs.text ;
}

void Button::setFont(sf::Font &font)
{
    text.setFont(font);
}

void Button::setBackColor(sf::Color color)
{
    button.setFillColor(color);
}

void Button::setTextColor(sf::Color color)
{
    text.setColor(color);
}

void Button::setPosition(sf::Vector2f pos)
{
/*
    sf::FloatRect buttonRect = button.getLocalBounds();
    button.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top  + buttonRect.height/2.0f);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, buttonRect.top  + buttonRect.height/2.0f);

    button.setPosition(pos);*/

    sf::FloatRect buttonRect = button.getLocalBounds();
    button.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top  + buttonRect.height/2.0f);
    button.setPosition(pos);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(buttonRect.left + buttonRect.width/3.82f, buttonRect.top  + buttonRect.height/2.0f);
    text.setPosition(pos);

    /*
    sf::FloatRect textLB = text.getLocalBounds().;
    sf::Vector2f center = {textLB.width / 2.0f, textLB.height / 2.0f} ;
    sf::Vector2f localBounds = center + textLB.*/

}

void Button::drawTo(sf::RenderWindow &window)
{
    window.draw(button);
    window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow &window)
{
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float btnPosX = button.getPosition().x;
    float btnPosY = button.getPosition().y;

    float btnxPosWith = button.getPosition().x + button.getLocalBounds().width;
    float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

    if(mouseX < btnxPosWith && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
    {
        return true;
    }
    return false;
}
