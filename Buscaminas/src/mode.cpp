#include "../include/mode.h"
#include <iostream>

using namespace std;

Mode::Mode()
{
    //ctor
}

Mode::~Mode()
{
    //dtor
}

string Mode::getMode()
{
    return mode;
}

void Mode::setMode(string val)
{
    mode = val;
}

void Mode::printMode()
{
    cout << "\t\t\tBUSCAMINAS\n";
    cout << "Hola jugador! Aqui puedes jugar al buscaminas en diferentes modos de juego.\n";
    cout << "En cada modo, tiene tableros de diferentes dimensiones y con una cantidad diferente de minas\n\n";
    cout << "\t - FACIL  (tablero 8x8 y 10 minas)\n\t - NORMAL (tablero 16x16 y 40 minas)";

}

void Mode::playGame()
{
    printMode();

    cout << "\n\nSelecciona el modo que quieres jugar (F/N): ";
    cin >> mode;

    while (cin.fail() || (mode.compare("f") && mode.compare("F") && mode.compare("n") && mode.compare("N")))
            {
                system("cls");
                printMode();
                cout << "\n\n\tOpcion no valida.\n\n\tIntroduce una de las opciones anteriores (F o N)\n";
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\n\n\tSelecciona el modo que quieres jugar (F/N): ";
                cin >> mode;

            }

    if(mode.compare("f") == 0||mode.compare("F")==0)
    {
        Game* game = new Game(SIZE_EASY,MINAS_EASY);
        game->menu();

    }else{
        Game* game = new Game(SIZE_STANDARD,MINAS_STANDARD);
        game->menu();

    }



}
