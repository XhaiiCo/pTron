#ifndef PLAYER_H
#define PLAYER_H
#include "string"
#include <SFML/Graphics.hpp>

class Player
{
    private:
        std::string name ;
        sf::Color color;

    public:
        Player(std::string = "UNDEFINED", sf::Color = sf::Color::White);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        std::string str() const ;
};

#endif // PLAYER_H
