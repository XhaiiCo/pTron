#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
    public:
        GameState();
        virtual ~GameState();
        GameState(const GameState& other);
        GameState& operator=(const GameState& other);

        virtual void init() = 0 ;
        virtual void processInput() = 0 ;
        virtual void update() = 0 ;
        virtual void draw() = 0 ;
};

#endif // GAMESTATE_H
