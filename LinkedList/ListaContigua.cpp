#include"ListaContigua.h"
#include<iostream>
using namespace std;

/*
            int *vector;
            int n;
            int capacidad;
            int incremento;
*/

ListaContigua::ListaContigua(int incremento)
{
    this->incremento = incremento;
    this->n = 0;
    this->capacidad = 0;
    this->vector = NULL;
}

ListaContigua::~ListaContigua()
{
    delete[] vector;
}

int ListaContigua::getValor(int posicion)
{
    return vector[posicion];
}

void ListaContigua::setValor(int posicion, int nuevoValor)
{
    this->vector[posicion] = nuevoValor;
}

int ListaContigua::getN()
{
    return this->n;
}

int ListaContigua::getCapacidad()
{
    return this->capacidad;
}

void ListaContigua::insertar(int posicion, int nuevoValor)
{

}

void ListaContigua::eliminar(int posicion)
{

}

void ListaContigua::concatenar(ListaContigua *listaAConcatenar)
{

}

int ListaContigua::buscar(int elementoABuscar)
{
    return 0;
}