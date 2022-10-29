#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "Case.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Magenta);

    Player* p ;
    Case c ;
    std::cout << c.str() << std::endl ;
    c.setPlayer(p) ;
    std::cout << c.str() << std::endl ;

    delete p ;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
