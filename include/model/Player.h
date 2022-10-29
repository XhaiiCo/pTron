#ifndef PLAYER_H
#define PLAYER_H
#include "string"

class Player
{
    private:

    public:
        Player();
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        std::string str() const ;
};

#endif // PLAYER_H
