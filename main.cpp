#include <SFML/Graphics.hpp>
#include <iostream>

#include "Playground.h"
#include "Player.h"
#include "Game.h"
#include "Menu.h"

using namespace sf;

int main()
{
    int windowWidth = Playground::NB_COLUMN * (Game::CASE_WIDTH + Game::PADDING);
    int windowHeight = Playground::NB_LINE * (Game::CASE_WIDTH + Game::PADDING);
    bool player1Lost = false ;
    bool player2Lost = false ;
    int yStart = (int)(Playground::NB_LINE/2) ;

    Player p1("D", 5, yStart) ;
    Player p2("J", Playground::NB_COLUMN-5, yStart) ;
    p1.setColor(255, 0, 0) ;
    p2.setColor(85, 255, 0) ;
    p1.changeDirection(1,0) ;
    p2.changeDirection(-1, 0) ;

    Playground playground(p1, p2);

    // The window
    RenderWindow window(VideoMode(windowWidth, windowHeight), "The Tron Game!");
    window.setFramerateLimit(9);
    Game game(windowWidth, windowHeight, &playground);
    Menu menu(windowWidth, windowHeight);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed) window.close() ;
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
                        window.close();
                        RenderWindow play(VideoMode(windowWidth, windowHeight), "Play Option");
                        play.setFramerateLimit(9);

                        while(play.isOpen())
                        {
                            sf::Event event1;
                            while (play.pollEvent(event1))
                            {

                                if(event1.type == sf::Event::Closed)
                                {
                                    play.close();
                                }
                            }
                            if (Keyboard::isKeyPressed(Keyboard::Up)) playground.changeDirectionPlayer1(0, -1);
                            if (Keyboard::isKeyPressed(Keyboard::Down)) playground.changeDirectionPlayer1(0, 1);
                            if (Keyboard::isKeyPressed(Keyboard::Left)) playground.changeDirectionPlayer1(-1, 0);
                            if (Keyboard::isKeyPressed(Keyboard::Right)) playground.changeDirectionPlayer1(1, 0);

                            if (Keyboard::isKeyPressed(Keyboard::Z)) playground.changeDirectionPlayer2(0, -1);
                            if (Keyboard::isKeyPressed(Keyboard::S)) playground.changeDirectionPlayer2(0, 1);
                            if (Keyboard::isKeyPressed(Keyboard::Q)) playground.changeDirectionPlayer2(-1, 0);
                            if (Keyboard::isKeyPressed(Keyboard::D)) playground.changeDirectionPlayer2(1, 0);

                            playground.movePlayers() ;


                            player1Lost = playground.isPlayer1HasLost() ;
                            player2Lost = playground.isPlayer2HasLost() ;

                            if(player1Lost || player2Lost) play.close() ;

                            playground.displayplayers() ;

                            game.drawGame() ;

                            play.clear();
                            play.draw(game.getSprite());
                            play.display();
                        }

                        if(player1Lost && player2Lost) std::cout << "Match draw" << std::endl ;
                        else if(player2Lost) std::cout << "Player 1 won" << std::endl ;
                        else if(player1Lost) std::cout << "Player 2 won" << std::endl ;
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
        }



        //game.drawGame() ;
        window.clear();
        menu.draw(window);
        //window.draw(game.getSprite()); // affiche le nouveau sprite
        window.display();
    }


}
