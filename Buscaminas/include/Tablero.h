#ifndef TABLERO_H
#define TABLERO_H

#include "Casilla.h"
#include <string>

const int MINAS_EASY = 10;
const int SIZE_EASY = 10; //el tablero es de 8x8, pero se deja un cuadro exterior para hacer más facil la comparación de
                          //calculo de valores de las minas (filas y columnas 0 y 9 siempre estarán vacías)
const int SIZE_STANDARD = 18;
const int MINAS_STANDARD = 40;

class Tablero
{
    public:
        Tablero();
        Tablero(int,int);
        virtual ~Tablero();

        void setMines();
        void calculateValuesTablero();
        void setCasillaMinas(std::string,int);
        std::string* getCasillaMinas();

        bool isCasillaMina(int,int);
        bool casillaSeleccionada(int,int);

        void marcarCasillas(int,int);

        bool checkCount();

        void printNumLim(int);
        void printTablero();
        void printTest();


    private:
        Casilla** casillasTablero;//[SIZE_EASY][SIZE_EASY];
        //std::string casillasMinas[MINAS_EASY];
        std::string* casillasMinas;
        int countSelected; //contar si ha seleccionado todas las casillas sin tocar las minas
        int sizeMode;
        int cantidadMinas;
};

#endif // TABLERO_H
