#include <iostream>
#include "Cola.h"

using namespace std;

// private:
//   Nodo *principio;
//   Nodo *final;
 
Cola::Cola()
{
    this->principio = nullptr;
    this->final = nullptr;
}

void Cola::encolar(int num)
{
    if(estaVacia())
    {
        Nodo *nodo = new Nodo(num, nullptr);
        this->final->siguiente = nodo;
        this->final = nodo;
    }
    else
    {
        Nodo *nodo = new Nodo(num, nullptr);
        this->final = nodo;
        this->principio = nodo;
    }
}  

int Cola::desencolar()
{
    int value = this->principio->valor;
    Nodo *nodo = new Nodo(0, nullptr);

    nodo = this->principio;

    if(!estaVacia())
    {
        if(this->principio == final)
        {
            this->principio = nullptr;
            this->final = nullptr;
        }
        else
        {
            this->principio = this->principio->siguiente;
        }
    }
    free(nodo);
    return value;
}

bool Cola::estaVacia()
{
    return (this->principio == nullptr) ? true : false;
} 
