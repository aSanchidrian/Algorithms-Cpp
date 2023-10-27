#include <iostream>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;

/* Calcula la raiz cuadrada de un numero
	   Parametro: numero para calcular la raiz y el error maximo
	   Retorno: raiz cuadrada del numero dado
	   Precondicion: raiz>0 && error>0
	   Complejidad Temporal: 
	   Complejidad Espacial: 
*/
float calculaRaiz(float raiz, float error, float izq, float der)
{
    float medio = ((izq + der) / 2);

    if((raiz - (medio * medio)) > error)
    {
        cout << medio << endl;
        return calculaRaiz(raiz, error, medio, der);
    }
    else if(((medio * medio) - raiz) > error)
    {
        
        cout << medio << endl;
        return calculaRaiz(raiz, error, izq, medio);
    }
    else
    {
        cout << medio << endl;
    }

    return 0;
}

int main()
{
    float raiz, error;   //raiz, error
    cin>>raiz>>error;
    float izq = 0, der = raiz;  //izq

    assertdomjudge(raiz >= 0 && error >= 0);

    calculaRaiz(raiz, error, izq, der);

    return 0;
}