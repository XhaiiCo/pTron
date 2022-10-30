#include <SFML/Graphics.hpp>
#include <iostream>

#include "Playground.h"
#include "Player.h"

int main()
{
    Player p1("D", 2, 2) ;
    Player p2("J", 3, 5) ;

    Playground playground(p1, p2);
    playground.movePlayers() ;

    std::cout << playground.str() << std::endl ;

    //Test p1
    playground.changeDirectionPlayer1(1, 0) ;
    playground.changeDirectionPlayer2(-1,0) ;
    playground.movePlayers() ;
    playground.changeDirectionPlayer1(0, -1) ;
    playground.movePlayers() ;
    playground.movePlayers() ;
    playground.movePlayers() ;
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
