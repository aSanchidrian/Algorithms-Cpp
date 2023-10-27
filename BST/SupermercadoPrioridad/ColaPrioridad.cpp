#include <iostream>
#include "ColaPrioridad.h"

using namespace std;

void ColaPrioridad::encolar(int nuevoElemento)
{
    this->vector.insertarAlFinal(nuevoElemento);
    int posPadre = (this->vector.getN()/2);
    int posElemento = this->vector.getN();

    while(posPadre >= 1 && this->vector.getValor(posPadre - 1) > this->vector.getValor(posElemento - 1))
    {
        int aux;
        aux = this->vector.getValor(posPadre - 1);
        this->vector.setValor((posPadre - 1), nuevoElemento);
        this->vector.setValor((posPadre * 2 - 1), aux);
        posPadre = (posPadre / 2);
    }
}

int ColaPrioridad::desencolar()
{
    int aux = this->vector.getValor(0);

    this->vector.setValor(0, this->vector.getValor(this->vector.getN() - 1));
    this->vector.eliminarAlFinal();
    reestructurar();

    return aux;
}

bool ColaPrioridad::estaVacia()
{
    if(this->vector.getN() == 0)
    {
        return true;
    }
    return false;
}

void ColaPrioridad::reestructurar()
{
    int valor = this->vector.getValor(0);
    int posPadre = 1;

    if(this->vector.getN() > 1)
    {
        while (valor > this->vector.getValor(posPadre * 2 - 1) || valor > this->vector.getValor(posPadre * 2))
        {
            if (this->vector.getValor(posPadre * 2) < valor)
            {
                if (this->vector.getValor(posPadre * 2) > this->vector.getValor(posPadre * 2 - 1))
                {
                    this->vector.setValor((posPadre - 1), this->vector.getValor(posPadre * 2 - 1));
                    this->vector.setValor((posPadre * 2 - 1), valor);
                    posPadre *= 2;
                }
                else
                {
                    this->vector.setValor((posPadre - 1), this->vector.getValor(posPadre * 2));
                    this->vector.setValor((posPadre * 2), valor);
                    posPadre = (posPadre * 2 + 1);
                }
            }
            else
            {
                this->vector.setValor((posPadre - 1), this->vector.getValor(posPadre * 2 - 1));
                this->vector.setValor((posPadre * 2 - 1), valor);
                posPadre *= 2;
            }
        }
    }
}
