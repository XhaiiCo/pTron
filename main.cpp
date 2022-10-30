#include <SFML/Graphics.hpp>
#include <iostream>

#include "Playground.h"
#include "Player.h"
#include "Menu.h"

int main()
{
    /*
    Player p1("David") ;
    Player p2("Jésurémie") ;

    Playground playground(p1, p2);
    p1 = Player("test") ;

    std::cout << playground.str() << std::endl ;*/



    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    Menu menu(window.getSize().x, window.getSize().y);

    /*
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Magenta);*/

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Up)
                {
                    menu.MoveUp();
                }
                else if(event.key.code == sf::Keyboard::Down)
                {
                    menu.MoveDown();
                }
                else if(event.key.code == sf::Keyboard::Return)
                {
                    int pressedItem = menu.GetPressedItem();

                    if(pressedItem == 0)
                    {
                        std::cout << "Play button has been pressed" << std::endl;
                    }
                    else if(pressedItem == 1)
                    {
                        std::cout << "Option button has been pressed" << std::endl;
                    }
                    else
                    {
                        window.close();
                    }
                }
            }
            else if(event.type == sf::Event::Closed)
            {
                window.close();
            }


/*
            switch(event.type)
            {
                case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem())
                            {
                                case 0:
                                    std::cout << "Play button has been pressed" << std::endl;
                                    break;
                                case 1:
                                    std::cout << "Option button has been pressed" << std::endl;
                                    break;
                                case 2:
                                    window.close();
                            }
                    }
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
            }*/

        }

        window.clear();

        menu.draw(window);

        window.display();
    }

}
