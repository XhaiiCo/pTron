#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    private:

    public:
        Player();
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);
};

#endif // PLAYER_H
