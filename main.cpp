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
//    TextBox textbox1(15, sf::Color::White, false);
//    textbox1.setFont(arial);
//    textbox1.setPosition({100, 100});
//    textbox1.setLimit(10);
//
//    Button btn1("Click me", {200, 50}, 20, sf::Color::Green, sf::Color::Black);
//    btn1.setPosition({100, 300});
//    btn1.setFont(arial);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
//        {
//            textbox1.setSelected(true);
//        }
//        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//        {
//            textbox1.setSelected(false);
//        }
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
//                    break;
//                case sf::Event::MouseButtonPressed:
//                    if(btn1.isMouseOver(window))
//                    {
//                        std::cout << "clicked" << std::endl;
//                    }
//            }
//        }
//
//        window.clear();
//        textbox1.drawTo(window);
//        btn1.drawTo(window);
//        window.display();
//    }
}
