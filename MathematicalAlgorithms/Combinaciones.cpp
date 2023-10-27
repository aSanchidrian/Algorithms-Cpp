#include <iostream>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;

/* Calcula las combinaciones posibles en base a los dos parametros que se pasan
	   Parametro: numero para calcular el factorial
	   Retorno: factorial del numero dado
	   Precondicion: n>=r
	   Complejidad Temporal: T(n) = T(n-1) + 1
	   Complejidad Espacial: M(n) = T(n-1) + 1
*/
int factorial(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1); 
    }
}

int main()
{
    int n, r;
    cin >> n >> r;

    while(n >= 0 && r >= 0)
    {
        assertdomjudge(n>=r);
        int sol = factorial(n) / (factorial(r) * factorial(n - r));
        cout<<sol<<endl;
        cin >> n >> r;
    }
    return 0;
}