#include "ABB.h"
#include "assertdomjudge.h"
#include <iostream>

using namespace std;

ABB::ABB()
{
  this->raiz = NULL;
  this->n = 0;
}

void ABB::insertar (int nuevoElemento)
{
  Nodo *nuevoNodo = new Nodo();
  nuevoNodo->hijoDerecho = NULL;
  nuevoNodo->hijoIzquierdo = NULL;

  if(this->n == 0)  //no esta creado el arbol
  {
    nuevoNodo->contenido = nuevoElemento;
    this->raiz = nuevoNodo;
  }
  else
  {
    Nodo *aux = buscarHueco(this->raiz, nuevoElemento);
    nuevoNodo->padre = aux;

    if(nuevoElemento <= aux->contenido)
    {
      aux->hijoIzquierdo = nuevoNodo;
    }
    else
    {
      aux->hijoDerecho = nuevoNodo; 
    }
  }
  this->n++;
}

Nodo * ABB::buscar(int elementoABuscar)
{
  if(raiz == NULL || raiz->contenido == elementoABuscar)
  {
    return raiz;
  }

  if(raiz->contenido < elementoABuscar)
  {
    return buscarRecursivo(raiz->hijoDerecho, elementoABuscar);
  }

  return buscarRecursivo(raiz->hijoIzquierdo, elementoABuscar);
}

void ABB::eliminar (int elementoAEliminar)
{ 
  if(elementoAEliminar == raiz->contenido && raiz->hijoIzquierdo == NULL && raiz->hijoDerecho == NULL)  //solo existe la raiz
  {
    delete raiz;
  }
  else
  {
    eliminarNodo(buscar(elementoAEliminar));
  }
}

void ABB::imprimir()
{
  if(raiz==NULL)
    cout<<"VACIO"<<endl;
  else   
    imprimirRecorrido(raiz);    
}

bool ABB::esABB()
{
  if(raiz != NULL)
  {
    esSubABB(raiz);
  }
  return false;
}

bool ABB::esAVL()
{
  if(esABB())
  {
    esSubAVL(raiz);
  }
  return false;
}

void ABB::leerArbol()
{
  raiz = leerSubarbol(NULL);
}

ABB::~ABB()
{
  if(this->n > 0)
  {
    eliminarSubarbol(raiz);
  }
}

void ABB::eliminarSubarbol (Nodo *raizSubarbol)
{
  if(raizSubarbol != NULL)
  {
    if(raizSubarbol->hijoIzquierdo == NULL && raizSubarbol->hijoDerecho == NULL)
    {
      delete raizSubarbol;
    }
    else
    {
      eliminarSubarbol(raizSubarbol->hijoIzquierdo);
      eliminarSubarbol(raizSubarbol->hijoDerecho);
    }
  }
}

Nodo *ABB::buscarHueco(Nodo *raizSubarbol, int elementoAInsertar)
{
  if(elementoAInsertar <= raizSubarbol->contenido)
  {
    if(raizSubarbol->hijoIzquierdo != NULL)
    {
      return buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar);
    }
    else
    {
      return raizSubarbol;
    }
  }
  else
  {
    if(raizSubarbol->hijoDerecho != NULL)
    {
      return buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar);
    }
    else
    {
      return raizSubarbol;
    }
  }
}

Nodo *ABB::buscarRecursivo (Nodo *raizSubarbol, int elementoABuscar)
{
  if(raizSubarbol == NULL || raizSubarbol->contenido == elementoABuscar)
  {
    return raizSubarbol;
  }

  if(elementoABuscar < raizSubarbol->contenido)
  {
    return buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
  }
  
  return buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
}

Nodo *ABB::buscarMaximo (Nodo *raizSubarbol)
{
  if(raizSubarbol->hijoDerecho == NULL)
  {
    return raizSubarbol->hijoDerecho;
  }
  else
  { 
    return buscarMaximo(raizSubarbol->hijoDerecho);
  }
}

Nodo *ABB::buscarMinimo (Nodo *raizSubarbol)
{
  if(raizSubarbol->hijoIzquierdo == NULL)
  {
    return raizSubarbol->hijoIzquierdo;
  }
  else
  { 
    return buscarMaximo(raizSubarbol->hijoIzquierdo);
  }
}

void ABB::eliminarNodo (Nodo *nodoParaEliminar)
{
  int aux = 0;
  Nodo *nodo = new Nodo();

  if(nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho == NULL)  // Si es un nodo hoja
  {
    nodoParaEliminar->padre->hijoIzquierdo = NULL;
    nodoParaEliminar->padre->hijoDerecho = NULL;
    delete nodoParaEliminar;
  }
  else // Si es un nodo interno
  {
    if(nodoParaEliminar->hijoIzquierdo != NULL && nodoParaEliminar->hijoDerecho == NULL)
    {
      if(nodoParaEliminar->padre == NULL)
      {
        if(nodoParaEliminar->hijoIzquierdo != NULL)
        {
          nodo = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
          nodoParaEliminar->contenido = nodo->contenido;
          eliminarNodo(nodo);
        }
        else if(nodoParaEliminar->hijoDerecho != NULL)
        {
          nodo = buscarMinimo(nodoParaEliminar->hijoDerecho);
          nodoParaEliminar->contenido = nodo->contenido;
          eliminarNodo(nodo);
        }
        else
        {
			    raiz = NULL;
		    }
      }
      else if(nodoParaEliminar->padre != NULL)
      {
        nodo = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
        if(nodoParaEliminar->padre->hijoIzquierdo != NULL)
        {
          if(nodoParaEliminar->contenido == nodoParaEliminar->padre->hijoIzquierdo->contenido)
          {
            nodoParaEliminar->padre->hijoIzquierdo = nodo;
          }
        }
      }
      //eliminarNodo(nodo);
    }
    else if(nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho != NULL)
    { 
      if(nodoParaEliminar->padre == NULL)
      {
        if(nodoParaEliminar->hijoIzquierdo != NULL)
        {
          nodo = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
          nodoParaEliminar->contenido = nodo->contenido;
          eliminarNodo(nodo);
        }
        else if(nodoParaEliminar->hijoDerecho != NULL)
        {
          nodo = buscarMinimo(nodoParaEliminar->hijoDerecho);
          nodoParaEliminar->contenido = nodo->contenido;
          eliminarNodo(nodo);
        }
        else
        {
			    raiz = NULL;
		    }
      }
      if(nodoParaEliminar->padre != NULL)
      {
        if(nodoParaEliminar->padre->hijoDerecho != NULL)
        {
          if(nodoParaEliminar->contenido == nodoParaEliminar->padre->hijoDerecho->contenido)
          {
            nodoParaEliminar->padre->hijoDerecho = nodo;
          }
        }
      }
      //eliminarNodo(nodo);
    }
    else if(nodoParaEliminar->hijoIzquierdo != NULL && nodoParaEliminar->hijoDerecho != NULL) // Tiene ambos hijos
    {
      if(alturaNodo(nodoParaEliminar->hijoDerecho) <= alturaNodo(nodoParaEliminar->hijoIzquierdo))
      {
        Nodo *nodo = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
        nodoParaEliminar->contenido = nodo->contenido;
        eliminarNodo(nodo);
      }
      else
      {
        Nodo *nodo = buscarMinimo(nodoParaEliminar->hijoDerecho);
        nodoParaEliminar->contenido = nodo->contenido;
        eliminarNodo(nodo);
      }
    }
  }
  this->n--;
}

int ABB::alturaNodo(Nodo *raizSubarbol)
{
  int izquierda = 0, derecha = 0;
  if(raizSubarbol == NULL)
  {
    return -1;
  }

  if(raizSubarbol->hijoIzquierdo == NULL && raizSubarbol->hijoDerecho == NULL)
  {
    return 0;
  }
  else
  {
    izquierda = 1 + alturaNodo(raizSubarbol->hijoIzquierdo);  //altura izquierda
    derecha = 1 + alturaNodo(raizSubarbol->hijoDerecho);  //altura derecha
    
    if(izquierda < derecha)
    {
      return izquierda;
    }
    else
    {
      return derecha;
    }
  }
}

void ABB::imprimirRecorrido(Nodo *raizSubarbol)
{
  cout<<raizSubarbol->contenido<<endl;
  if(raizSubarbol->hijoIzquierdo!=NULL)
  {
    cout<<"I";
    imprimirRecorrido(raizSubarbol->hijoIzquierdo);
    cout<<endl;
  }
  if(raizSubarbol->hijoDerecho!=NULL)
  {
    cout<<"D";
    imprimirRecorrido(raizSubarbol->hijoDerecho);
    cout<<endl;
  }
}

bool ABB::esSubABB(Nodo *raizSubarbol)
{
  if(raiz->hijoIzquierdo == NULL && raiz->hijoDerecho == NULL)
  {
    return true;
  }
  else if(raiz->hijoIzquierdo == NULL && raiz->hijoDerecho != NULL)
  {
    if(raizSubarbol->hijoDerecho->contenido > raizSubarbol->contenido)
    {
      return esSubABB(raizSubarbol->hijoDerecho);
    }
    return false;
  }
  else if (raiz->hijoIzquierdo != NULL && raiz->hijoDerecho == NULL)
  {
    if(raizSubarbol->hijoIzquierdo->contenido < raizSubarbol->contenido)
    {
      return esSubABB(raizSubarbol->hijoIzquierdo);
    }
    return false;
  }
  else
  {
    if(raizSubarbol->hijoIzquierdo->contenido < raizSubarbol->contenido && raizSubarbol->hijoDerecho->contenido > raizSubarbol->contenido)
    {
      if(esSubABB(raizSubarbol->hijoIzquierdo) && esSubABB(raizSubarbol->hijoDerecho))
      {
        return true;
      }
    }
    return false;
  }
}

bool ABB::esSubAVL(Nodo *raizSubarbol)
{
  if(abs(alturaNodo(raizSubarbol->hijoIzquierdo) - alturaNodo(raizSubarbol->hijoDerecho)) < 2)
  {
    return true;
  }
  return false;
}

Nodo * ABB::leerSubarbol(Nodo *padre)
{
  int contenido;
  cin>>contenido;
  if(contenido>=0)
    {
      Nodo *arbol = new Nodo();
      arbol->contenido=contenido;
      arbol->hijoIzquierdo=leerSubarbol(arbol);
      arbol->hijoDerecho=leerSubarbol(arbol);
      arbol->padre=padre;
      return arbol;
    }
  else
    {
      return NULL;
    }
}
