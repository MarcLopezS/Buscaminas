#ifndef CASILLA_H
#define CASILLA_H

#include <string>

class Casilla
{
    public:
        Casilla();
        virtual ~Casilla();

        void setValorReal(int);
        int getValorReal();
        void setValor(std::string);
        std::string getValor();
        void setMarca(std::string);
        std::string getMarca();

        void setIsMine(bool);
        bool getIsMine();

        void setSelected(bool);
        bool getSelected();

        void setLimit(bool);
        bool getLimit();


    private:
        std::string valor;
        int valorReal;
        std::string marca;
        bool isMine;
        bool isLimit; //casilla de los limites
        bool selected; //para marcar que el jugador ya ha abierto esa casilla
};

#endif // CASILLA_H
