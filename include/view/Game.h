#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

#include "Playground.h"

using namespace sf;

class Game
{
    //CONSTANT
    public:
        inline const static int CIRCLE_RADIUS = 10 ;
    private:
        int width;
        int height;
        Sprite sprite;
        RenderTexture t;
        CircleShape c = CircleShape(CIRCLE_RADIUS);

        Playground playground ;

    public:
        Game(int width = 500, int height = 500);
        Game(int width, int height, Playground);
        virtual ~Game();
        void init();
        Sprite getSprite();
};

#endif // GAME_H
