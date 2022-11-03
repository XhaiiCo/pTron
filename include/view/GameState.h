#ifndef GAMESTATE_H
#define GAMESTATE_H

/* DESIGN PATTERN STATE
* the gameState class is an abstract class.
* It represents a view, each view of the program implements this class and redefined the methods.
*
* The advantage of this design pattern is that for each view we will use the same architecture.
* And no matter the view we will always call the same methods,
* so it is easy to change view, and To add or delete a view, we just have to modify the nextState method
*/
class GameState
{
    public:
        GameState();
        virtual ~GameState();
        GameState(const GameState& other);
        GameState& operator=(const GameState& other);

        /*
        * The init method will initialize the view.
        * It's in this method that we will create the elements of the view.
        */
        virtual void init() = 0 ;

        /*
        * It's in the processInput method that will define the keyboard and mouse input listeners.
        */
        virtual void processInput() = 0 ;

        /*
        * In the update method this is where we will make the actions that will update the view.
        * For example, move an animation forward.
        */
        virtual void update() = 0 ;

        /*
        * In the draw method,
        * we will draw the elements that we have initialized in init method.
        */
        virtual void draw() = 0 ;

        /*
        * The nextState method will switch to the next state, i.e. to the next view.
        */
        virtual void nextState() = 0 ;

        virtual GameState* clone() = 0 ;
};

#endif // GAMESTATE_HA
