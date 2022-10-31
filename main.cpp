#include <SFML/Graphics.hpp>
#include <iostream>

#include "Playground.h"
#include "Player.h"
#include "Game.h"
#include "Menu.h"
#include "MainWindow.h"

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
    MainWindow mainWindow(playground) ;
    mainWindow.start() ;

}
