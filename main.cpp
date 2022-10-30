#include <SFML/Graphics.hpp>
#include <iostream>

#include "Playground.h"
#include "Player.h"
#include "Game.h"

using namespace sf;

int main()
{
    int W = 500, H = 500;

    Player p1("David");
    Player p2("Jésurémie");

    Playground playground(p1, p2);
    p1 = Player("test") ;

    RenderWindow window(VideoMode(W, H), "The Tron Game!");
    window.setFramerateLimit(60);
    Game game(W, H);

    while (window.isOpen())
    {
       sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(game.getSprite());
        window.display();
    }

}
