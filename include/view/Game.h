#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Game
{
    private:
        int width;
        int height;
        Sprite sprite;
        RenderTexture t;
        CircleShape c = CircleShape(4);

    public:
        Game(int width = 500, int height = 500);
        virtual ~Game();
        void init();
        Sprite getSprite();
};

#endif // GAME_H
