#include "TextBox.h"

void TextBox::inputLogic(int charTyped)
{
    if(charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
    {
        text << static_cast<char>(charTyped);
    }
    else if(charTyped == DELETE_KEY)
    {
        if(text.str().length() > 0)
        {
            deleteLastChar();
        }
    }
    textbox.setString(text.str() + "_");
}

void TextBox::deleteLastChar()
{
    std::string t = text.str();
    std::string newT = "";
    for(int i = 0; i < t.length() - 1; i++)
    {
        newT += t[i];
    }
    text.str("");
    text << newT;

    textbox.setString(text.str());
}

TextBox::TextBox(int size, sf::Color color, bool sel)
{
    textbox.setCharacterSize(size);
    textbox.setColor(color);
    isSelected = sel;
    if(sel)
    {
        textbox.setString("_");
    }
    else
    {
        textbox.setString("");
    }

    background.setSize({200, 50});
    background.setFillColor(sf::Color::White);
}

void TextBox::setFont(sf::Font &font)
{
    textbox.setFont(font);
}

void TextBox::setPosition(sf::Vector2f pos)
{
    background.setPosition(pos);

    float xPos = (pos.x + background.getLocalBounds().width / 3) - (textbox.getLocalBounds().width / 2);
    float yPos = (pos.y + background.getLocalBounds().height / 3) - (textbox.getLocalBounds().height / 2);
    textbox.setPosition(xPos, yPos);
}

void TextBox::setLimit(int lim)
{
    limit = lim;
}

void TextBox::setSelected(bool sel)
{
    isSelected = sel;
    if(!sel)
    {
        std::string t = text.str();
        std::string newT = "";
        for(int i = 0; i < t.length(); i++)
        {
            newT += t[i];
        }
        textbox.setString(newT);
    }
}

void TextBox::setBorder(sf::Color color)
{
    background.setOutlineColor(color);
    background.setOutlineThickness(3);
}

std::string TextBox::getText()
{
    return text.str();
}

void TextBox::drawTo(sf::RenderWindow &window)
{
    window.draw(background);
    window.draw(textbox);
}

void TextBox::typedOn(sf::Event input)
{
    if(isSelected)
    {
        int charTyped = input.text.unicode;
        if(charTyped < 128)
        {
            int textLength = text.str().length();

            if(textLength < limit)
            {
                inputLogic(charTyped);
            }
            else if(charTyped == DELETE_KEY)
            {
                deleteLastChar();
            }
        }
    }
}

bool TextBox::isMouseOver(sf::RenderWindow &window)
{
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float btnPosX = background.getPosition().x;
    float btnPosY = background.getPosition().y;

    float btnxPosWith = background.getPosition().x + background.getLocalBounds().width;
    float btnyPosHeight = background.getPosition().y + background.getLocalBounds().height;

    if(mouseX < btnxPosWith && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
    {
        return true;
    }
    return false;
}
