#include "../include/Game.h"
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

Game::Game()
{

}

Game::Game(int modeGame, int minasMode)
{
    //ctor
    tableGame = Tablero(modeGame,minasMode);
    actualMode = modeGame;
    isGameFinished = false;
}

Game::~Game()
{
    //dtor
}

void Game::playMarcar()
{
    int fila, columna;
    int* posicion;

    posicion = seleccionFilCol();
    fila = posicion[0];
    columna = posicion[1];

    tableGame.marcarCasillas(fila,columna);


}

int* Game::seleccionFilCol()
{
    int* posicion = new int[2];

    cout << "\n\n\tSelecciona la casilla disponible que quieras.\n\n";

    cout << "\tFila: ";
    cin >> posicion[0];

    while (cin.fail() || posicion[0] < 1 || posicion[0] > actualMode-2)
    {
        system("cls");
        tableGame.printTablero();
        cout << "\n\n\tNumero no valido\n\n\tIntroduce numero entre 1-" << actualMode-2 << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\n\tFila: ";
        cin >> posicion[0];

    }

    cout << "\tColumna: ";
    cin >> posicion[1];

    while (cin.fail() || posicion[1] < 1 || posicion[1] > actualMode-2)
    {
        system("cls");
        tableGame.printTablero();
        cout << "\n\n\tNumero no valido\n\n\tIntroduce numero entre 1-" << actualMode-2 << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\n\tFila: " << posicion[0] << "\n";
        cout << "\tColumna: ";
        cin >> posicion[1];

    }

    return posicion;
}

void Game::play()
{
    int fila, columna;
    int* posicion;

    system("cls");
    tableGame.printTablero();

    posicion = seleccionFilCol();
    fila = posicion[0];
    columna = posicion[1];

    bool selected = tableGame.casillaSeleccionada(fila,columna);
    /*Aquí se setea tanto la casilla como seleccionada como que se comprueba si hay mina*/
    if(!selected)
    {
        //Comprueba si ha seleccionado todas las casillas posibles sin tocar ninguna mina
        if(tableGame.checkCount())
        {
            win();
            isGameFinished = true;
        }

    }else{
        gameOver();
        isGameFinished = true;

    }

}

void Game::gameOver()
{
    system("cls");
    tableGame.printTablero();
    cout << "\n\n\t GAME OVER\n\n";
}

void Game::win()
{
    system("cls");
    tableGame.printTablero();
    cout << "\n\n\t ¡HAS GANADO!\n\n";
}

void Game::menu()
{
    tableGame.setMines();
    tableGame.calculateValuesTablero();
    string opcion;

    do{
        system("cls");
        tableGame.printTablero();

        cout << "\n\n\tQue deseas hacer? Marcar o seleccionar? (M/S): ";

        cin >> opcion;

        while (cin.fail() || (opcion.compare("m") && opcion.compare("M") && opcion.compare("s") && opcion.compare("S")))
            {
                system("cls");
                tableGame.printTablero();
                cout << "\n\n\tOpcion no valida.\n\n\tIntroduce una de las opciones anteriores (M o S)\n";
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\n\n\tQue deseas hacer? Marcar o seleccionar? (M/S): ";
                cin >> opcion;

            }

        if(opcion.compare("m") == 0||opcion.compare("M") == 0)
        {
            opcion = "1";
        }else{
            opcion = "2";
        }

         switch(stoi(opcion)){
             case 1:{
                playMarcar(); //se tiene que hacer aún esta función
                break;
             }
             case 2:{
                play();
                break;
             }
        };
    }while(!isGameFinished); //el bucle se tiene que hacer aqui junto con el game over y el win (no en play)



}
