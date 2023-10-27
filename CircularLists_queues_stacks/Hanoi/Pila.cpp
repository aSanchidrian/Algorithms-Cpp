#include "Pila.h"

Pila::Pila(string name)
{
  this->name = name;
  this->cima = NULL;
}

string Pila::nombrePila()
{
  return this->name;
}

void Pila::apilar(int num)
{
  assertdomjudge(num > 0);

  Nodo *aux = new Nodo(num, NULL);

  aux->siguiente = cima;
  cima = aux;

  cout<<"Apilando disco "<<num<<" en poste "<<name<<endl;
} 

int Pila::desapilar()
{
  assertdomjudge(!estaVacia());

  int resultado = 0;

  resultado = cima->valor;
  cima = cima->siguiente;

  cout<<"Desapilando disco "<<resultado<<" del poste "<<name<<endl;

  return resultado;
}

bool Pila::estaVacia() 
{
  return cima == NULL;
}
