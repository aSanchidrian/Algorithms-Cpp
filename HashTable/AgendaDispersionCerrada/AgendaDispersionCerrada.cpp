#include "Agenda.h"
#include "assertdomjudge.h"
#include <iostream>

using namespace std;

Agenda::Agenda(int capacidad)
{
	this->capacidad = capacidad;
	this->n = 0;
	this->nombres = new string[capacidad];
	this->telefonos = new long[capacidad];
	this->vacias = new bool[capacidad];
	this->borradas = new bool[capacidad];

	for(int i = 0; i < capacidad; i++)
	{
		vacias[i] = true;
	}
}

Agenda::~Agenda()
{
	delete[] nombres;
	delete[] telefonos;
	delete[] vacias;
	delete[] borradas;
}

int Agenda::obtenerPosicion(long telefono)
{
	return (telefono % this->capacidad);
}

int Agenda::buscarContacto(long telefono)
{
	int pos = obtenerPosicion(telefono);

	for(int i = pos; i < capacidad; i++)
	{
		if(telefonos[i] == telefono)
		{
			return i;
		}
		else if((i == (capacidad - 1)) && (telefonos[i] != telefono))
		{
			for(int j = 0; j < capacidad; j++)
			{
				if(telefonos[j] == telefono)
				{
					return j;
				}
			}
		}
	}
	return -1;
}

int Agenda::buscarHueco(long telefono)
{
	assertdomjudge(!isLlena());

	int pos = obtenerPosicion(telefono);

	for(int i = pos; i < capacidad; i++)
	{
		if((vacias[i] && !borradas[i]) || (vacias[i] && borradas[i]))	
		{
			return i;
		}
		else if(i == (capacidad - 1) && !vacias[i])
		{
			for(int j = 0; j < capacidad; j++)
			{
				if(vacias[j] && borradas[j] || vacias[j] && !borradas[j])
				{
					return j;
				}
			}
		}
	}
	return -1;
}

bool Agenda::isLlena()
{
	if(n == capacidad)
	{
		return true;
	}
	return false;
}

bool Agenda::existeContacto(long telefono)
{
	for(int i = 0; i < capacidad; i++)
	{
		if(!vacias[i])
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

	return nombres[buscarContacto(telefono)];
}

void Agenda::introducirContacto(long telefono, string contacto)
{
	assertdomjudge(!isLlena() && !existeContacto(telefono));

	int pos = buscarHueco(telefono);

	nombres[pos] = contacto;
	telefonos[pos] = telefono;
	vacias[pos] = false;
	borradas[pos] = false;

	n++;
}

void Agenda::eliminarContacto(long telefono)
{
	assertdomjudge(existeContacto(telefono));

	int pos = buscarContacto(telefono);
	vacias[pos] = true;
	borradas[pos] = true;

	n--;
}

void Agenda::imprimir()
{
	for (int i = 0; i < capacidad; i++)
	{
		cout << "Posicion " << i << " | Vacia: " << vacias[i] << " | Borrada: " << 
		borradas[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
	}
}