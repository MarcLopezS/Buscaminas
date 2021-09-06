#include "../include/Tablero.h"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <iostream>
#include <time.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

using namespace std;

Tablero::Tablero()
{

}

Tablero::Tablero(int size, int minasMode)
{
    //ctor

    sizeMode = size;
    cantidadMinas = minasMode;

    casillasMinas = new string[minasMode];

    casillasTablero = new Casilla*[size];

    for(int i = 0; i<size;i++)
    {
        casillasTablero[i] = new Casilla[size];
    }

    countSelected = 0;


    for(int i = 0;i<size;i++)
    {
        casillasTablero[0][i].setLimit(true);
        casillasTablero[size-1][i].setLimit(true);

        if(i!=0 || i != size-1)
        {
            casillasTablero[i][0].setLimit(true);
            casillasTablero[i][size-1].setLimit(true);
        }

    }
}

Tablero::~Tablero()
{
    //dtor
}

void Tablero::setMines()
{
    // será el valor O la mina
    srand(_getpid());
    int xrandom, yrandom,minas_colocadas=0;

    while(minas_colocadas<cantidadMinas){


        xrandom = (rand()%(sizeMode-2))+1;
        yrandom = (rand()%(sizeMode-2))+1;

        if(!casillasTablero[xrandom][yrandom].getIsMine())
        {
            casillasTablero[xrandom][yrandom].setIsMine(true);
            casillasTablero[xrandom][yrandom].setValorReal(9);
            setCasillaMinas(to_string(xrandom) +"|"+to_string(yrandom),minas_colocadas);
            minas_colocadas++;
        }

    }
}

void Tablero::calculateValuesTablero()
{
    //se empieza a calcular desde la casilla 1,1

    /*

        1,1 --> [0,0] [0,1] [0,2] [1,0] [1,2] [2,0] [2,1] [2,2]
    */

    int contador = 0;

    for(int i = 1;i <= sizeMode-2;i++)
    {
        for(int j = 1; j <= sizeMode-2; j++)
        {

            if(!casillasTablero[i][j].getIsMine())
            {
                casillasTablero[i][j].setValorReal(0);
                casillasTablero[i-1][j-1].getIsMine()?contador++:0;
                casillasTablero[i-1][j].getIsMine()?contador++:0;
                casillasTablero[i-1][j+1].getIsMine()?contador++:0;
                casillasTablero[i][j-1].getIsMine()?contador++:0;
                casillasTablero[i][j+1].getIsMine()?contador++:0;
                casillasTablero[i+1][j-1].getIsMine()?contador++:0;
                casillasTablero[i+1][j].getIsMine()?contador++:0;
                casillasTablero[i+1][j+1].getIsMine()?contador++:0;

                //seteamos el valor calculado de minas próximas
                casillasTablero[i][j].setValorReal(contador);


            }
            contador = 0;

        }
    }

}

void Tablero::setCasillaMinas(string positionMine, int positionArray)
{
    casillasMinas[positionArray] = positionMine;
}

string* Tablero::getCasillaMinas()
{
    return casillasMinas;
}

bool Tablero::isCasillaMina(int fila, int col)
{

    return casillasTablero[fila][col].getIsMine()?true:false;
}

bool Tablero::casillaSeleccionada(int fila, int col)
{
    if(!(casillasTablero[fila][col].getSelected()) && (fila>0 && fila<sizeMode-1 && col>0 && col<sizeMode-1))
    {
        casillasTablero[fila][col].setSelected(true);
        ++countSelected;
        if(isCasillaMina(fila,col))
        {
            return true;
        }

        if(casillasTablero[fila][col].getValorReal() == 0)
        {
            casillaSeleccionada(fila-1,col-1);
            casillaSeleccionada(fila-1,col);
            casillaSeleccionada(fila-1,col+1);
            casillaSeleccionada(fila,col-1);
            casillaSeleccionada(fila,col+1);
            casillaSeleccionada(fila+1,col-1);
            casillaSeleccionada(fila+1,col);
            casillaSeleccionada(fila+1,col+1);

        }
    }

    return false;
}

bool Tablero::checkCount()
{
    //esto solo es para el modo EASY, para adaptarlo hay que cambiar el numero a comparar
    return countSelected==(sizeMode-cantidadMinas)?true:false;
}

void Tablero::marcarCasillas(int fila, int columna)
{
    if(casillasTablero[fila][columna].getValor() == "-")
        casillasTablero[fila][columna].setValor("P");
    else
        casillasTablero[fila][columna].setValor("-");
}

void Tablero::printNumLim(int end= 1)
{
    if(end == 0)
    {
        cout << "\t     ";
        for(int k = 1; k<sizeMode-1;k++)
        {
            if(k<10)
                cout << k << "   ";
            else
                cout << k << "  ";
        }

        cout << "\n";
    }
    cout << "\t   -";

    for(int i = 1; i< sizeMode-1;i++)
    {
        cout << "----";
    }
    cout << "\n";

}

void Tablero::printTablero()
{
    //printTest();
    string printCasilla, color;

    printNumLim(0);
    for(int i=1;i<sizeMode-1;i++)
    {
        if(i<10)
            cout << "\t "<< i << " ";
        else
            cout << "\t" << i << " ";
        for(int j=1;j<sizeMode-1;j++)
        {
            printCasilla = ((casillasTablero[i][j].getSelected())
                    ?(casillasTablero[i][j].getIsMine())
                        ?"X" :to_string(casillasTablero[i][j].getValorReal())
                    :casillasTablero[i][j].getValor());

            cout <<"| ";

            //Para poner diferentes colores a los diferentes caracteres
            if(printCasilla == "P")
                cout << CYAN << printCasilla << RESET;
            else
                //para printar la mina y de color rojo
                if(printCasilla == "X")
                    cout<<RED<< printCasilla << RESET;
                else
                    if(printCasilla == "0") //para printar huecos vacios si no hay minas alrededor
                        cout<< " ";
                    else
                        if((printCasilla == "1" || printCasilla == "2"))
                             cout << GREEN << printCasilla << RESET;
                        else
                            if(printCasilla == "4" || printCasilla == "5" || printCasilla == "6" || printCasilla == "7" || printCasilla == "8")
                                 cout << MAGENTA << printCasilla << RESET;
                            else
                                 cout << YELLOW << printCasilla << RESET;
            cout<< " ";

            if(sizeMode-2 == j)
            {
                cout << "|\n";
                //cout << "\t   ---------------------------------\n";
                printNumLim();

            }

        }
    }
}

void Tablero::printTest()
{
    cout << "Las minas estan en: ";
    for(int i=0; i<cantidadMinas;i++)
    {
        cout << casillasMinas[i].substr(0,casillasMinas[i].find("|")) << "," << casillasMinas[i].substr(casillasMinas[i].find("|")+1,casillasMinas[i].back()) << " | ";
    }
    cout << "\n";
}
