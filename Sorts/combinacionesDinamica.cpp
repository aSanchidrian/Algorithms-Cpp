#include <iostream>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//void crearTriangulo(int **matriz)

int main()
{
    int **matriz;
    matriz = new int *[11];

    for(int i = 0; i < 11; i++)
    {
        matriz[i] = new int[11];
    }

    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0 && j == i)
            {
                matriz[i][j] = 1;
            }
            else
            {
                matriz[i][j] = matriz[i-1][j-1] + matriz[i-1][j];
            }
        }
    }

    int n, r;
    cin>>n>>r;

    while(n >= 0 && r >= 0)
    {
        assertdomjudge(n>=r);
        cout<<matriz[n][r]<<endl;
        cin>>n>>r;
    }
    return 0;
}