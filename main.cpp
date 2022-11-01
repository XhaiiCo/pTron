#include "Game.h"

#include "TextBox.h"
#include "Button.h"

int main()
{
    Game g ;
    g.run() ;

//    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
//
//    window.setKeyRepeatEnabled(true);
//
//    sf::Font arial;
//    arial.loadFromFile("arial.ttf");
//    TextBox textbox1(15, sf::Color::Black, false);
//    textbox1.setFont(arial);
//    textbox1.setPosition({300, 100});
//    textbox1.setLimit(10);
//    textbox1.setBorder(sf::Color::White);
//
//    TextBox textbox2(15, sf::Color::Black, false);
//    textbox2.setFont(arial);
//    textbox2.setPosition({1200, 100});
//    textbox2.setLimit(10);
//    textbox2.setBorder(sf::Color::White);
//
//    Button btn1("PLAY", {200, 50}, 20, sf::Color::Green, sf::Color::Black);
//    btn1.setPosition({760,600});
//    btn1.setFont(arial);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//
//        while (window.pollEvent(event))
//        {
//            switch(event.type)
//            {
//                case sf::Event::Closed:
//                    window.close();
//
//                case sf::Event::TextEntered:
//                    textbox1.typedOn(event);
//                    textbox2.typedOn(event);
//                    break;
//                case sf::Event::MouseMoved:
//                    if(btn1.isMouseOver(window))
//                    {
//                        btn1.setBackColor(sf::Color::White);
//                    }
//                    else
//                    {
//                        btn1.setBackColor(sf::Color::Green);
//                    }
//
//                    break;
//                case sf::Event::MouseButtonPressed:
//                    if(textbox1.isMouseOver(window))
//                    {
//                        textbox1.setSelected(true);
//                        textbox1.setBorder(sf::Color::Green);
//                        textbox2.setSelected(false);
//                        textbox2.setBorder(sf::Color::White);
//                    }
//                    else if(textbox2.isMouseOver(window))
//                    {
//                        textbox2.setSelected(true);
//                        textbox2.setBorder(sf::Color::Green);
//                        textbox1.setSelected(false);
//                        textbox1.setBorder(sf::Color::White);
//                    }
//                    else
//                    {
//                        textbox1.setSelected(false);
//                        textbox2.setSelected(false);
//                    }
//            }
//        }
//
//        window.clear();
//        textbox1.drawTo(window);
//        textbox2.drawTo(window);
//        btn1.drawTo(window);
//        window.display();
//    }
}
