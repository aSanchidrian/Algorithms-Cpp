#include "ListaEnlazada.h"
#include <iostream>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

ListaEnlazada::ListaEnlazada()
{
    this->n = 0;
    this->lista = NULL;
}

ListaEnlazada::~ListaEnlazada()
{
    delete[] lista;
}

Nodo * ListaEnlazada::getNodo(int posicion)
{
    Nodo *nodoAux = new Nodo();
    nodoAux = lista;

    for(int i = 0; i < posicion; i++)
    {
        nodoAux = nodoAux->siguienteNodo;
    }

    return nodoAux;
}

int ListaEnlazada::getValor(int posicion)
{
    assertdomjudge(posicion < n && posicion >= 0);

    Nodo *nodoAux = new Nodo();

    nodoAux = getNodo(posicion);

    return nodoAux->elemento;
}

void ListaEnlazada::setValor(int posicion, int nuevoValor)
{
    assertdomjudge(posicion < n && posicion >= 0);

    Nodo *nodoAux = new Nodo();

    nodoAux = getNodo(posicion);

    nodoAux->elemento = nuevoValor;
}

int ListaEnlazada::getN()
{
    return this->n;
}

void ListaEnlazada::insertar(int posicion, int nuevoValor)
{
    assertdomjudge(posicion <= n && posicion >= 0);

    Nodo *nodoNuevo = new Nodo();

    if(posicion == 0)
    {
        if(n == 0)
        {
            lista = new Nodo();
            lista->elemento = nuevoValor;
        }
        else
        {
            nodoNuevo->elemento = lista->elemento;
            nodoNuevo->siguienteNodo = lista->siguienteNodo;
            lista->elemento = nuevoValor;
            lista->siguienteNodo = nodoNuevo;
        }
    }
    else if(posicion == n)
    {
        Nodo *nodoAnterior = new Nodo();

        nodoAnterior = getNodo(posicion - 1);

        nodoNuevo->elemento = nuevoValor;
        nodoAnterior->siguienteNodo = nodoNuevo;
    }
    else
    {
        Nodo *nodoSiguiente = new Nodo();
        Nodo *nodoAnterior = new Nodo();

        nodoAnterior = getNodo(posicion - 1);
        nodoSiguiente = getNodo(posicion);

        nodoNuevo->elemento = nuevoValor;
        nodoNuevo->siguienteNodo = nodoSiguiente;
        nodoAnterior->siguienteNodo = nodoNuevo;
    }
    
    n++;
}

void ListaEnlazada::eliminar(int posicion)
{
    assertdomjudge(posicion < n && posicion >= 0);

    if(posicion == 0)
    {
        if(n == 1)
        {
            free(lista);
        }
        else
        {
            free(lista);
            lista = getNodo(posicion + 1);
        }
    }
    else
    {
        getNodo(posicion - 1)->siguienteNodo = getNodo(posicion + 1);
    }
    
    n--;
}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar)
{
    for(int i = 0; i < listaAConcatenar->n; i++)
    {
        insertar(n, listaAConcatenar->getValor(i));
    }
}

int ListaEnlazada::buscar(int elementoABuscar)
{
    int result = -1;

    for(int i = 0; i < n; i++)
    {
        if(getValor(i) == elementoABuscar)
        {
            result = i;
        }
    }

    return result;
}
