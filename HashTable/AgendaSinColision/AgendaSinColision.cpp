#include "Agenda.h"
#include "assertdomjudge.h"
#include <iostream>
#include <string>

using namespace std;

Agenda::Agenda(int capacidad)
{
	this->capacidad = capacidad;
	this->nombres = new string[capacidad];
	this->telefonos = new long[capacidad];
	this->ocupados = new bool[capacidad];
}

Agenda::~Agenda()
{
	delete[] nombres;
	delete[] telefonos;
	delete[] ocupados;
}

int Agenda::obtenerPosicion(long telefono)
{
	return (telefono % this->capacidad);
}

bool Agenda::existeContacto(long telefono)
{
	for(int i = 0; i < capacidad; i++)
	{
		if(ocupados[i])
		{
			if(telefonos[i] == telefono)
			{
				return true;
			}
		}
	}
	return false;
}

string Agenda::getContacto(long telefono)
{
	assertdomjudge(existeContacto(telefono));

	return nombres[obtenerPosicion(telefono)];
}

void Agenda::introducirContacto(long telefono, string contacto)
{
	assertdomjudge(ocupados[obtenerPosicion(telefono)] != true);

	int pos = obtenerPosicion(telefono);

	nombres[pos] = contacto;
	telefonos[pos] = telefono;
	ocupados[pos] = true;
}

void Agenda::eliminarContacto(long telefono)
{
	assertdomjudge(existeContacto(telefono));

	int pos = obtenerPosicion(telefono);
	ocupados[pos] = false;
}

void Agenda::imprimir()
{
	for (int i = 0; i < capacidad; i++)
	{
		cout << "Posicion " << i << " | Ocupada: " << ocupados[i] << " | Telefono: " <<
			telefonos[i] << " | Nombre: " << nombres[i] << endl;
	}
}