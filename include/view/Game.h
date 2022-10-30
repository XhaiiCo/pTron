#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

#include "Playground.h"

using namespace sf;

class Game
{
    //CONSTANT
    public:
        inline const static int CIRCLE_RADIUS = 6 ;
    private:
        int width;
        int height;
        Sprite sprite;
        RenderTexture t;
        CircleShape c = CircleShape(CIRCLE_RADIUS);

        Playground* playground ;

    public:
        Game(int width, int height, Playground*);
        virtual ~Game();
        Sprite getSprite();

        void drawGame() ;
};

#endif // GAME_H
