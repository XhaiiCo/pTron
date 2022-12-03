#include "Button.h"

Button::Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
{
    text.setString(t);
    text.setColor(textColor);
    text.setCharacterSize(charSize);

    button.setSize(size);
    button.setFillColor(bgColor);
}

void Button::setBorder(sf::Color color)
{
    button.setOutlineColor(color);
    button.setOutlineThickness(3);
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
    float btnPosX = (float) pos.x - (float) button.getLocalBounds().width / (float) 2;

    button.setPosition(btnPosX , pos.y);

    float xPos = btnPosX + button.getLocalBounds().width / 4.94;
    float yPos = pos.y - button.getLocalBounds().height / 12;
    text.setPosition(xPos, yPos);

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
