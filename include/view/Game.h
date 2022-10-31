#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

#include "Playground.h"

using namespace sf;

class Game
{

    private:

    public:
        Game();
        virtual ~Game();
        void run() ;
};

#endif // GAME_H
