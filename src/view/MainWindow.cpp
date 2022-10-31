#include "MainWindow.h"
#include <iostream>

#include "Game.h"
#include "Menu.h"

MainWindow::MainWindow(Playground playground): playground(playground)
{
    this->windowWidth = Playground::NB_COLUMN * (Game::CASE_WIDTH + Game::PADDING);
    this->windowHeight = Playground::NB_LINE * (Game::CASE_WIDTH + Game::PADDING);
}

MainWindow::~MainWindow()
{
    //dtor
}
//
//void MainWindow::start(){
//    RenderWindow window(VideoMode(windowWidth, windowHeight), "The Tron Game!");
//    window.setFramerateLimit(FRAME_RATE_LIMIT);
//    Game game(windowWidth, windowHeight, &playground);
//    Menu menu(windowWidth, windowHeight);
//    int cpt = 0 ;
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if(event.type == Event::Closed) window.close() ;
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
//                        window.close();
//                        RenderWindow play(VideoMode(windowWidth, windowHeight), "Play Option");
//                        play.setFramerateLimit(FRAME_RATE_LIMIT);
//
//                        while(play.isOpen())
//                        {
//                            sf::Event event1;
//                            while (play.pollEvent(event1))
//                            {
//
//                                if(event1.type == sf::Event::Closed)
//                                {
//                                    play.close();
//                                }
//                            }
//                            if (Keyboard::isKeyPressed(Keyboard::Up)) playground.changeDirectionPlayer2(0, -1);
//                            if (Keyboard::isKeyPressed(Keyboard::Down)) playground.changeDirectionPlayer2(0, 1);
//                            if (Keyboard::isKeyPressed(Keyboard::Left)) playground.changeDirectionPlayer2(-1, 0);
//                            if (Keyboard::isKeyPressed(Keyboard::Right)) playground.changeDirectionPlayer2(1, 0);
//
//                            if (Keyboard::isKeyPressed(Keyboard::Z)) playground.changeDirectionPlayer1(0, -1);
//                            if (Keyboard::isKeyPressed(Keyboard::S)) playground.changeDirectionPlayer1(0, 1);
//                            if (Keyboard::isKeyPressed(Keyboard::Q)) playground.changeDirectionPlayer1(-1, 0);
//                            if (Keyboard::isKeyPressed(Keyboard::D)) playground.changeDirectionPlayer1(1, 0);
//
//                            if(cpt == 0){
//                                    playground.movePlayers() ;
//
//                                    player1Lost = playground.isPlayer1HasLost() ;
//                                    player2Lost = playground.isPlayer2HasLost() ;
//
//                                    if(player1Lost || player2Lost) play.close() ;
//
//                                    playground.displayplayers() ;
//
//                                    cpt++ ;
//
//                            }
//                            else {
//                                cpt++ ;
//                                if(cpt == SPEED) cpt = 0 ;
//
//                            }
//                            game.drawGame() ;
//
//                            play.clear();
//                            play.draw(game.getSprite());
//                            play.display();
//                        }
//
//                        if(player1Lost && player2Lost) std::cout << "Match draw" << std::endl ;
//                        else if(player2Lost) std::cout << "Player 1 won" << std::endl ;
//                        else if(player1Lost) std::cout << "Player 2 won" << std::endl ;
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
//        }
//
//        window.clear();
//        menu.draw(window);
//        window.display();
//    }
//}
