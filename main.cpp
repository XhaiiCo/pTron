#include <SFML/Graphics.hpp>
#include <iostream>

#include "Playground.h"
#include "Player.h"
#include "Game.h"
#include "Menu.h"

using namespace sf;

int main()
{
    int W = 500, H = 500;

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

    // La window
    RenderWindow window(VideoMode(W, H), "The Tron Game!");
    window.setFramerateLimit(60);
    Game game(W, H);
    Menu menu(W, H);

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

            window.clear();
            menu.draw(window); // affiche le nouveau sprite
            window.display();
        }
    }
}
