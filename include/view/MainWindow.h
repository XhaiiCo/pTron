#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Playground.h"

class MainWindow
{
    //CONSTANT
    public:
    const inline static int FRAME_RATE_LIMIT = 60 ;
    const inline static int SPEED = 5;
    private:
        int windowWidth ;
        int windowHeight ;
        bool player1Lost = false ;
        bool player2Lost = false ;

        Playground playground ;


    public:
        MainWindow(Playground = Playground());
        virtual ~MainWindow();

        void start() ;
};

#endif // MAINWINDOW_H
