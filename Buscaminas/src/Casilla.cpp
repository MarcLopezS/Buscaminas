#include "../include/Casilla.h"
using namespace std;
Casilla::Casilla()
{
    //ctor
    isMine = false;
    selected = false;

    valor = "-";

}

Casilla::~Casilla()
{
    //dtor
}

void Casilla::setValorReal(int value){
    valorReal = value;
}

int Casilla::getValorReal(){
    return valorReal;
}

void Casilla::setValor(string value)
{
    valor = value;
}


string Casilla::getValor()
{
    return valor;
}

void Casilla::setMarca(string mark)
{
    marca = mark;
}

string Casilla::getMarca()
{
    return marca;
}

void Casilla::setIsMine(bool mine)
{
    isMine = mine;
}

bool Casilla::getIsMine()
{
    return isMine;
}

void Casilla::setSelected(bool selectedCasilla)
{
    selected = selectedCasilla;
}

bool Casilla::getSelected()
{
    return selected;
}

void Casilla::setLimit(bool limit)
{
    isLimit = limit;
}

bool Casilla::getLimit()
{
    return isLimit;
}
