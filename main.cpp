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
    p1.setColor(255, 0, 0) ;
    p2.setColor(85, 255, 0) ;

    Playground playground(p1, p2);
    playground.movePlayers() ;

    std::cout << playground.str() << std::endl ;

    //Test p1
    playground.changeDirectionPlayer1(1, 0) ;
    playground.changeDirectionPlayer2(0,1) ;

    // The window
    RenderWindow window(VideoMode(W, H), "The Tron Game!");
    window.setFramerateLimit(9);
    Game game(W, H, &playground);
    Menu menu(W, H);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed) window.close() ;
//            if(event.type == sf::Event::KeyReleased)
//            {
//                if(event.key.code == sf::Keyboard::Up)
//                {
//                    menu.MoveUp();
//                }
//                else if(event.key.code == sf::Keyboard::Down)
//                {
//                    menu.MoveDown();
//                }
//                else if(event.key.code == sf::Keyboard::Return)
//                {
//                    int pressedItem = menu.GetPressedItem();
//
//                    if(pressedItem == 0)
//                    {
//                        std::cout << "Play button has been pressed" << std::endl;
//                    }
//                    else if(pressedItem == 1)
//                    {
//                        std::cout << "Option button has been pressed" << std::endl;
//                    }
//                    else
//                    {
//                        window.close();
//                    }
//                }
//            }
//            else if(event.type == sf::Event::Closed)
//            {
//                window.close();
//            }
        }
        playground.movePlayers() ;
        game.drawGame() ;
        window.clear();
        window.draw(game.getSprite()); // affiche le nouveau sprite
        window.display();
    }
}
