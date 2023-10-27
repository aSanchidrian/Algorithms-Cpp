#include <iostream>
#include <string>
#include "ListaEnlazada.h"

using namespace std;

class Agenda
{
	int capacidad;  //Capacidad maxima de la tabla
    int n;  //Numero actual de elementos de la tabla
    ListaEnlazada* tabla;  //Array listas enlazadas

public:
    Agenda(int capacidad);
    ~Agenda();
    int obtenerPosicion(long telefono);
    bool existeContacto(long telefono);
    string getContacto(long telefono);
    void introducirContacto(long telefono, string contacto);
    void eliminarContacto(long telefono);
    void imprimir();
};