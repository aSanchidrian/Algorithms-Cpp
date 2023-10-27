#include <iostream>
#include <string.h>
using namespace std;

#define MAX_TAM 20

/* Identifica si una palabra es palindromo (que se escriba igual de principio a fin que de fin a principio)
	   Parametro: Palabra, donde incia la palabra, donde acaba la palabra
	   Retorno: 0 si no es palindromo, 1 si lo es
	   Precondicion: Ninguna.
	   Complejidad Temporal: T(n) = T(n-2) + 1
	   Complejidad Espacial: M(n) = M(n-2) + 1
*/
int palindromo(const char cadena[], int inicio, int final)
{
    if(inicio >= final)
    {
        return 1;
    }

    if(cadena[inicio] == cadena[final-1])
    {
        return palindromo(cadena, inicio + 1, final - 1);
    }
    else
    {
        return 0;
    }
}

int main()
{
    char cadena[MAX_TAM];
    cin>>cadena;

    int tamCadena = strlen(cadena);
    int sol = palindromo(cadena, 0, tamCadena);

    cout<<sol<<endl;

    return 0;
}