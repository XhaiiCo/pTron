#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

#include "Playground.h"

using namespace sf;

class Game
{
    //CONSTANT
    public:
        inline const static int CASE_WIDTH = 20 ;
        inline const static int PADDING = 0 ;
    private:
        int width;
        int height;
        Sprite sprite;
        RenderTexture t;

        Playground* playground ;

    public:
        Game(int width, int height, Playground*);
        virtual ~Game();
        Sprite getSprite();

        void drawGame() ;
};

#endif // GAME_H
