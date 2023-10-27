#include <iostream>
#include "Supermercado.h"
#include "ColaPrioridad.h"
using namespace std;

Supermercado::Supermercado(int n)
{
    this->n_cajas = n;
    this->cajas = new ColaPrioridad[this->n_cajas];
}

void Supermercado::nuevoUsuario(int n,int id)
{
    this->cajas[n].encolar(id);
}

void Supermercado::cerrarCaja(int n)
{
    int i = 0;

    while(!cajas[n].estaVacia())  
    {
        if(i == n)
        {
            i++;
        }

        if(i >= n_cajas)
        {
            i = 0;
        }

        this->cajas[i].encolar(this->cajas[n].desencolar());
        i++;
    }
}

int Supermercado::atenderUsuario(int n)
{
    return this->cajas[n].desencolar();
}

bool Supermercado::cajaVacia(int n)
{
    if(this->cajas[n].estaVacia())
    {
        return true;
    }
    return false;
}