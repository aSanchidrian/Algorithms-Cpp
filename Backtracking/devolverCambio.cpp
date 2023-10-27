#include <iostream>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

int *devolverCambio(int n, int result[])
{
    int monedas[8] = {500, 200, 100, 50, 25, 10, 5, 1};

    for(int i = 0; i < 8; i++)
    {
        result[i] = 0;
    }
    
    while(n>0)
    {
        for(int i = 0; i < 8; i++)
        {
            while(n - monedas[i] >= monedas[i])
            {
                n -= monedas[i];
                result[i]++;
            }
            
            if(n - monedas[i] >= 0)
            {
                n -= monedas[i];
                result[i]++;
            }
        }
    }
    return result;
}

int main()
{
    int result[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int n;
    cin>>n;

    while(n >= 0)
    {
        assertdomjudge(n>0);
        devolverCambio(n, result);
        
        for(int i = 0; i < 8; i++)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
        cin>>n;
    }
    return 0;
}