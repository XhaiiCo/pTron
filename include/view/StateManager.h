#ifndef STATEMANAGER_H
#define STATEMANAGER_H

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

        void setState(GameState* state) ;
        GameState* getState() ;
 };

#endif // STATEMANAGER_H
