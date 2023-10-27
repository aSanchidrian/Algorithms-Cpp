#include <iostream>
#include <stdlib.h>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

void movimiento(char **mapa, int x, int y, int *tesoroX, int *tesoroY, bool *exito)
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int u = 0, v = 0;
    
    if(!*exito)
    {
        if((0 <= x) && (x < 10) && (0 <= y) && (y < 10))  
        {
            if(mapa[x][y] == '.') 
            {
                mapa[x][y] = 'X';   
                
                for(int i = 0; i < 4; i++)  
                {              
                    u = x + dx[i]; 
                    v = y + dy[i];  
                    movimiento(mapa, u, v, tesoroX, tesoroY, exito);
                }
                if(!*exito) 
                {
                    mapa[x][y] = '.';
                }
            }
            else if(mapa[x][y] == 'T') 
            {
                *tesoroX = x;
                *tesoroY = y;
                *exito = true;
                return;
            }
        }
    }
}

int main()
{
    char **mapa;
    int x = 0, y = 0;
    bool exito;
    int tesoroX = 0;
    int tesoroY = 0;

    mapa = new char *[10];

    for(int i = 0; i < 10; i++)
    {
        mapa[i] = new char[10];
    }
    
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cin>>mapa[i][j];
        }
    }

    movimiento(mapa, x, y, &tesoroX, &tesoroY, &exito);

    if(exito == true)
    {
        for(int i = 0; i < 10; i++)
        {
            cout<<endl;
            for(int j = 0; j < 10; j++)
            {
                cout<<mapa[i][j];
            }
        }
        cout<<endl;
        cout<<"ENCONTRADO "<<tesoroX<<" "<<tesoroY<<endl;
    }
    else
    {
        cout<<"INALCANZABLE"<<endl;
    }

    return 0;
}