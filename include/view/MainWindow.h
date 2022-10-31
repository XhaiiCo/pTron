#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Playground.h"

class MainWindow
{
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
