#include<iostream>
using namespace std;
//mirar complejidad desde dentro hacia fuera
void ordenarBurbuja(int x[],int len)
{
    for(int i = 1; i < len; i++)
    {
        int aux;
        for(int j = 0; j < len-i; j++)
        {
            if(x[j] > x[j+1])
            {
                aux=x[j];
                x[j]=x[j+1];
                x[j+1]=aux;
            }
        }

      for(int k=0;k<len;k++)
	    cout<<x[k]<<" ";
      cout<<endl;
    }  
}


int main()
{
    int n;
    cin>>n;
    int *x=new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }

    ordenarBurbuja(x,n);
}