#pragma once
#include "Nodo.h"

class ListaEnlazada
{
	Nodo *lista;
	int n;
	Nodo * getNodo (int posicion);
	int ultimaPosicion;
	Nodo *ultimoNodo;

public:

/* Constructor por defecto. Inicializa los valores vacios.
       Parámetro: Ninguno
       Retorno: Ninguno.
       Precondicion: Ninguno.
       Complejidad Temporal: O(1)
       Complejidad Espacial: O(1)
*/
	ListaEnlazada();

	/* Devuelve el valor de una posicion.
	Parámetro: la posicion
	Retorno: el valor.
	Precondicion: posicion < n && posicion >= 0
	Complejidad Temporal: O(n)
	Complejidad Espacial: O(1)
*/
	Contacto getValor(int posicion);

/* Metodo para cambiar un valor de una posicion
	Parámetro: posicion y el valor
	Retorno: Ninguno.
	Precondicion: posicion < n && posicion >= 0
	Complejidad Temporal: O(n)
	Complejidad Espacial: O(1)
*/
	void setValor(int posicion, Contacto nuevoValor);

/* Duevuelve el numero de valores que hay en la lista.
	Parámetro: Ninguno
	Retorno: n.
	Precondicion: Ninguno.
	Complejidad Temporal: O(1)
	Complejidad Espacial: O(1)
*/
	int getN(); 

/*Metodo para insertar un valor en una posicion especifica
	Parámetro: posicion y el valor
	Retorno: Ninguno.
	Precondicion: posicion <= n && posicion >= 0.
	Complejidad Temporal: O(n)
	Complejidad Espacial: O(1)
*/
	void insertar (int posicion, Contacto nuevoValor);

/*Metodo para eliminar un valor en una posicion especifica
	Parámetro: posicion y el valor
	Retorno: Ninguno.
	Precondicion: posicion < n && posicion >= 0.
	Complejidad Temporal: O(n)
	Complejidad Espacial: O(1)
*/
	void eliminar (int posicion);

/*Metodo para concatenar una lista al final de la otra
	Parámetro: la lista a concatenar
	Retorno: Ninguno.
	Precondicion: El puntero a la lista a concatenar es no nulo.
	Complejidad Temporal: O(n+m)
	Complejidad Espacial: O(1)
*/
	void concatenar(ListaEnlazada *listaAConcatenar);

/*Metodo para buscar un elemento
	Parámetro: elemento a buscar
	Retorno: el valor.Contacto
	Precondicion: El elemento a buscar existe en la lista.
	Complejidad Temporal: O(n^2)
	Complejidad Espacial: O(1)
*/
	int buscar(Contacto elementoABuscar);

/*Destructor por defecto
	Parámetro: Ninguno.
	Retorno: Ninguno.
	Precondicion: Ninguno.
	Complejidad Temporal: O(1)
	Complejidad Espacial: O(1)
*/
	~ListaEnlazada();
};







