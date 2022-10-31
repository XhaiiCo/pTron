#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <stack>
#include "GameState.h"

class StateManager
{
    private:
        GameState* state ;
    public:
        StateManager();
        virtual ~StateManager();
        StateManager(const StateManager& other);
        StateManager& operator=(const StateManager& other);

        void setState(GameState* state){ this->state = state ;}
        GameState* getState(){return this->state ;}
 };

#endif // STATEMANAGER_H
