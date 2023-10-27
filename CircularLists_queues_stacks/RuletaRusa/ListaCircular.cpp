#include<iostream>
#include"ListaCircular.h"
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

Nodo * ListaCircular::getNodo(int posicion)
{
    Nodo * nodoAux = new Nodo();
    nodoAux = lista;

    if(posicion > 0)
    {
        for(int i = 0; i < posicion; i++)
        {
            nodoAux = nodoAux->siguienteNodo;
        }
    }
    else
    {
        for(int i = posicion; i < 0; i++)
        {
            nodoAux = nodoAux->anteriorNodo;
        }
    }
    return nodoAux;
}

ListaCircular::ListaCircular()
{
    this->n = 0;
    this->lista = NULL;
}

ListaCircular::~ListaCircular()
{
    Nodo* nodo = lista;
    Nodo* nodo2;

    for(int i = 0; i < n; i++)
    {
        nodo2 = nodo;
        nodo = nodo->siguienteNodo;
        delete nodo2;
    }
}

string ListaCircular::getValor(int posicion)
{
    assertdomjudge(posicion < n && posicion >= 0);
    
    Nodo *nodoAux = new Nodo();

    nodoAux = getNodo(posicion);

    return nodoAux->elemento;
}

void ListaCircular::setValor(int posicion, string nuevoValor)
{
    assertdomjudge(posicion < n && posicion >= 0);

    Nodo *nodoAux = new Nodo();

    nodoAux = getNodo(posicion);
    nodoAux->elemento = nuevoValor;
}

int ListaCircular::getN()
{
    return this->n;
}

void ListaCircular::insertar(int posicion, string nuevoValor)
{
    assertdomjudge(posicion <= n && posicion >= 0);

    Nodo *nuevoNodo = new Nodo();

    if(posicion == 0)
    {
        if(n == 0)
        {
            nuevoNodo->elemento = nuevoValor;
            nuevoNodo->siguienteNodo = nuevoNodo;
            nuevoNodo->anteriorNodo = nuevoNodo;
            lista = nuevoNodo;
        }
        else
        {
            nuevoNodo->elemento = nuevoValor;
            nuevoNodo->siguienteNodo = getNodo(posicion);
            nuevoNodo->anteriorNodo = getNodo(posicion - 1);
        }
    }
    else
    {
        nuevoNodo->elemento = nuevoValor;
        nuevoNodo->siguienteNodo =  getNodo(posicion);
        nuevoNodo->anteriorNodo = getNodo(posicion - 1);
        getNodo(posicion)->anteriorNodo = nuevoNodo;
        getNodo(posicion - 1)->siguienteNodo = nuevoNodo;
    }
    n++;
}

void ListaCircular::eliminar(int posicion)
{
    assertdomjudge(posicion < n && posicion >= 0);

    Nodo *eliminar = getNodo(posicion);

    if(posicion == 0)
    {
        if(n == 1)
        {
            delete eliminar;
        }
        else
        {
            getNodo(n - 1)->siguienteNodo = getNodo(posicion + 1);
            getNodo(posicion + 1)->anteriorNodo = getNodo(n - 1);
            lista = lista->siguienteNodo;
            delete eliminar;
        }
    }
    else
    {
        getNodo(posicion + 1)->anteriorNodo = getNodo(posicion - 1);
        getNodo(posicion - 1)->siguienteNodo = getNodo(posicion + 1);
        delete eliminar;
    }
    n--;
}

void ListaCircular::girar(int p)
{
    lista = getNodo(p);
}