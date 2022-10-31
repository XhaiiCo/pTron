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
}

void TextBox::setFont(sf::Font &font)
{
    textbox.setFont(font);
}

void TextBox::setPosition(sf::Vector2f pos)
{
    textbox.setPosition(pos);
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

std::string TextBox::getText()
{
    return text.str();
}

void TextBox::drawTo(sf::RenderWindow &window)
{
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
