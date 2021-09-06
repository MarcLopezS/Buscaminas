#ifndef GAME_H
#define GAME_H

#include "Tablero.h"

class Game
{
    public:
        Game();
        Game(int,int);
        virtual ~Game();

        void play();
        void gameOver();
        void win();
        void menu();
        void playMarcar();
        int* seleccionFilCol();


    private:
        Tablero tableGame;
        bool isGameFinished;
        int actualMode;
};

#endif // GAME_H
