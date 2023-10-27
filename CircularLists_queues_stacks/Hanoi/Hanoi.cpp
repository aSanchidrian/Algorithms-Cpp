#include<iostream>
#include"Pila.h"
#include"assertdomjudge.h"
using namespace std;

void Hanoi(int n, Pila *origen, Pila *temporal, Pila *destino) 
{ 
  int num = 0;

  if(n != 1)
  {
    Hanoi(n - 1, origen, destino, temporal);
    num = origen->desapilar();
    destino->apilar(num);
    Hanoi(n - 1, temporal, origen, destino);
  }
  else
  {
    num = origen->desapilar();
    destino->apilar(num);
  }
}

int main()
{  
  Pila *A=new Pila("A");
  Pila *B=new Pila("B");
  Pila *C=new Pila("C");

  int n;
  cin>>n;

  assertdomjudge(n > 0);
  
  for(int i=n;i>0;i--)
    A->apilar(i);

  Hanoi(n,A,B,C);
  
  for(int i=0;i<n;i++)
    C->desapilar();

  return 0;
}

