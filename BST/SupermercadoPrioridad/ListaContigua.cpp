#include "ListaContigua.h"
#include "cassert"
#include "cstdlib" // Para realloc()
#include "cstring" // Para memmove()
using namespace std;

bool ListaContigua::isLlena()
{
	return (n == capacidad);
}

ListaContigua::ListaContigua()
{
	vector = NULL; // No hay que reservar memoria ya que la ListaContigua se crea vac�a en un principio
	n=0;
	capacidad=0;
}

int ListaContigua::getValor(int posicion)
{
	assert(posicion >= 0 && posicion <= n-1);
	return (vector[posicion]);
}

void ListaContigua::setValor(int posicion, int nuevoValor)
{
	assert(posicion >= 0 && posicion <= n-1);
	vector[posicion] = nuevoValor;
}

int ListaContigua::getN()
{
	return (n);
}

int ListaContigua::getCapacidad()
{
	return (capacidad);
}

void ListaContigua::insertarAlFinal (int nuevoValor)
{
	insertar(n, nuevoValor);
}

void ListaContigua::eliminarAlFinal ()
{
	eliminar(n - 1);
}

void ListaContigua::insertar(int posicion, int nuevoValor)
{
	assert(posicion >= 0 && posicion <= n);

	if (isLlena())
	{
		vector = (int*)realloc(vector, sizeof(int)*(capacidad + INCREMENTO));
		capacidad += INCREMENTO;
	}

	memmove(&vector[posicion + 1], &vector[posicion], sizeof(int)*(n - posicion));
	setValor(posicion, nuevoValor);

	n++;
}

void ListaContigua::eliminar(int posicion)
{
	assert(posicion >= 0 && posicion <= n - 1);

	memmove(&vector[posicion], &vector[posicion + 1], sizeof(int)*(n - posicion - 1));

	if (capacidad - n == 2 * INCREMENTO)
	{
		vector = (int*)realloc(vector, sizeof(int)*(capacidad - INCREMENTO));
		capacidad -= INCREMENTO;
	}
	n--;
}

void ListaContigua::concatenar(ListaContigua *listaAConcatenar)
{
	assert(listaAConcatenar != NULL);

	int m = listaAConcatenar->getN(); 
	
	vector = (int*)realloc(vector, sizeof(int)*(capacidad + m));
	capacidad += m;

	for (int i = 0; i < m; i++)
	{
		insertarAlFinal(listaAConcatenar->getValor(i));
	}
}

int ListaContigua::buscar(int elementoABuscar)
{
	int posicion = 0;
	bool encontrado = false;

	while(!encontrado && posicion < n)
	{
		if (vector[posicion] == elementoABuscar) encontrado = true;
		posicion++;
	}

	if(encontrado)
	{
		return (posicion - 1);
	} 
	else
	{
		return (-1);
	}
}


ListaContigua::~ListaContigua()
{
	free(vector);
}


