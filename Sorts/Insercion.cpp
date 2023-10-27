#include<iostream>
using namespace std;

void ordenarInsercion(int x[],int len)
{
    int aux;

    for(int i = 1; i < len; i++)
    {
        int j = i;
        while (j > 0 && x[j - 1] > x[j]) 
        {
            aux = x[j];
            x[j] = x[j - 1];
            x[j - 1] = aux;
            j--;
        }

      for(int k=0;k<len;k++)
	    cout<<x[k]<<" ";
      cout<<endl;
    }  
}

/*
5 4 3 2 1

*/

int main()
{
    int n;
    cin>>n;
    int *x=new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }

    ordenarInsercion(x,n);
}

