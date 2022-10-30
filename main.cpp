#include <SFML/Graphics.hpp>
#include <iostream>

#include "Playground.h"
#include "Player.h"

int main()
{
    Player p1("David") ;
    Player p2("Jésurémie") ;

    Playground playground(p1, p2);
    p1 = Player("test") ;

    std::cout << playground.str() << std::endl ;



//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Magenta);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }

}
