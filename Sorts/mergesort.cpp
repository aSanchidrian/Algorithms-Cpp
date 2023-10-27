#include<iostream>
using namespace std;

void combinar(int a[] , int len_a , int b[] , int len_b , int c[])
{
  /*Añadir código que permite combinar dos arrays 
  solo hay bucles aqui*/
  int i = 0, j = 0; //"i" es el indice para recorrer "a" y "j" para "b"

  while(i + j < len_a + len_b)
  {
    if(i == len_a)
    {
      c[i + j] = b[j];
      j++;
    }
    else if(j == len_b)
    {
      c[i + j] = a[i];
      i++;
    }
    else if(a[i] == b[j])
    {
      c[i + j] = a[i];
      i++;
      c[i + j] = b[j];
      j++;
    }
    else if(a[i] < b[j])
    {
      c[i + j] = a[i];
      i++;
    }
    else if(a[i] > b[j])
    {
      c[i + j] = b[j];
      j++;
    }
  }
}

void ordenarMergeSort(int x[], int len)
{
  int temp[len];
  int mid = 0;
  int len_b = 0;

  if(len <= 1)    //caso basico
  {
    return;
  }
  else
  {
    // dividimos los arrays en 2 partes
    mid = (len / 2);  //la primera desde el 0 a la mitad
    len_b = (len - mid);  //la segundo desde la mitad hasta el final

    ordenarMergeSort(x, mid); //llamamos a la funcion con la primera mitad
    ordenarMergeSort(&x[mid], len_b); //despues con la segunda mitad
    
    combinar(x, mid, &x[mid], len_b, temp);   //Llamamos a la funcion con los dos arrays, sus tamanos, y el array destino

    for(int i = 0; i < len; i++)
    {
      x[i] = temp[i];
    }

    for(int k = 0; k < len; k++)
    {
      x[k] = temp[k];
      cout<<x[k]<<" ";
    }
    cout<<endl;
  }
}

int main()
{
  int n;
  cin>>n;
  int *x=new int[n];
  for(int i=0;i<n;i++)
    cin>>x[i];
  ordenarMergeSort(x,n);
  return 0;
}

