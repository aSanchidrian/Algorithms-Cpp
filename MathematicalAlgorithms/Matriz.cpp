#include "Matriz.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//constructor por defecto
Matriz::Matriz()
{
  n_filas = 0;
  n_columnas = 0;
  matriz = NULL;
}

//constructor por parametros
Matriz::Matriz(int n_filas, int n_columnas)
{
  this->n_filas = n_filas;
  this->n_columnas = n_columnas;

  matriz = new double*[n_filas];

  for(int i = 0; i < n_filas; i++)
  {
    matriz[i] = new double[n_columnas];
  }
}

//constructor copia
Matriz::Matriz(const Matriz &m)
{
  this->n_filas = m.n_filas;
  this->n_columnas = m.n_columnas;

  matriz = new double*[n_filas];

  for (int i = 0; i < n_filas; i++)
  {
    matriz[i] = new double[n_columnas];  
    for(int j=0; j <n_columnas; j++)
    {
      matriz[i][j]=m.matriz[i][j];
    }
  }
}

//destructor
Matriz::~Matriz()
{
  for(int i = 0; i < n_filas; i++)
  {
    delete[] matriz[i];
  }
  delete[] matriz;
}

//Asignacion de matrices
Matriz& Matriz::operator= (const Matriz &m)
{
  if(matriz!=NULL)
    {
      for (int i = 0; i < n_filas; i++)
  delete[] matriz[i];
      
      delete[] matriz;
      matriz=NULL;
    }

  this->n_filas=m.n_filas;
  this->n_columnas=m.n_columnas;
  this->matriz=NULL;
  if(n_filas>0 && n_columnas>0)
    {
      matriz= new double *[n_filas];
  
      for (int i = 0; i < n_filas; i++)
  {
    matriz[i] = new double[n_columnas];  
    for(int j=0; j <n_columnas; j++)
      matriz[i][j]=m.matriz[i][j];
  }
    }
  
    return(*this); 
}

//operador suma
Matriz Matriz::operator+ (const Matriz &m)
{
  assertdomjudge(n_filas == m.n_filas && n_columnas == m.n_columnas);

  Matriz m2(m.n_filas, m.n_columnas);

  for(int i = 0; i < n_filas; i++)
  {
    for(int j = 0; j < n_columnas; j++)
    {
      m2.matriz[i][j] = matriz[i][j] + m.matriz[i][j];
    }
  }

  return m2;
}

//operador resta
Matriz Matriz::operator- (const Matriz &m)
{
  assertdomjudge(n_filas == m.n_filas && n_columnas == m.n_columnas);

  Matriz m2(m.n_filas, m.n_columnas);
  
  for(int i = 0; i < n_filas; i++)
  {
    for(int j = 0; i < n_columnas; j++)
    {
      m2.matriz[i][j] = matriz[i][j] - m.matriz[i][j];
    }
  }

  return m2;
}

//operador producto por escalar
Matriz Matriz::operator* (const double escalar)
{
  Matriz m2(n_filas, n_columnas);
  
  for(int i = 0; i < n_filas; i++)
  {
    for(int j = 0; i < n_columnas; j++)
    {
      m2.matriz[i][j] = matriz[i][j] * escalar;
    }
  }
  return m2;
}

//Operador producto una matriz
Matriz Matriz::operator* (const Matriz &m)
{
  assertdomjudge(n_columnas == m.n_filas);

  Matriz m2(n_filas, m.n_columnas);
  double suma = 0;
  
  for(int i = 0; i < m.n_columnas; i++)
  {
    for(int j = 0; i < this->n_filas; j++)
    {
      suma = 0;

      for(int k = 0; k < this->n_columnas; k++)
      {
        suma += this->matriz[j][k] * m.matriz[k][i];
      }

      m2.matriz[i][j] = suma;
    }
  }
  return m2;
}

//calcula traspuesta de una matriz
Matriz Matriz::calcularTraspuesta()
{
  Matriz m(this->n_filas, this->n_columnas);

  for(int i = 0; i < this->n_filas; i++)
  {
    for(int j = 0; i < this->n_columnas; j++)
    {
      m.matriz[i][j] = this->matriz[j][i];
    }
  }

  return m;
}

//comprueba si la matriz es simetrica
bool Matriz::esSimetrica()
{
  if(n_filas != n_columnas)
  {
    return false;
  }

  for(int i = 0; i < this->n_filas; i++)
  {
    for(int j = 0; i < this->n_columnas; j++)
    {
      if(this->matriz[i][j] != this->matriz[j][i])
      {
        return false;
      }
    }
  }

  return true;
}

//obtiene el valor maximo
double Matriz::obtenerMaximo()
{
  double max = matriz[0][0];

  for (int i = 0; i < n_filas; i++)
  {
    for (int j = 0; j < n_columnas; j++)
    {
      if (matriz[i][j] > max)
      {
        max = matriz[i][j];
      }
    }
  }

  return max;
}

//obtiene el valor minimo
double Matriz::obtenerMinimo()
{
  double min = matriz[0][0];

  for (int i = 0; i < n_filas; i++)
  {
    for (int j = 0; j < n_columnas; j++)
    {
      if (matriz[i][j] < min)
      {
        min = matriz[i][j];
      }
    }
  }

  return min;
}

double Matriz::calcularDeterminante()
{
  assertdomjudge(n_filas==n_columnas);
  double det = 0;
  
  if(n_filas == 2)
  {
    return this->matriz[0][0] * this->matriz[1][1] - this->matriz[1][0] * this->matriz[0][1];
  }

  for(int i = 0; i < n_filas; i++)
  {
    Matriz m2(n_filas - 1, n_columnas - 1);

    for(int j = 0; j < n_filas; j++)
    {
      for(int k = 0; k < n_filas; k++)
      {
        
      }
    }
  }
  return det;
}

// Leer matriz
void Matriz::rellenarManual()
{
  double elemento;
  for (int i = 0; i < n_filas; i++)
    {
      cout << "Fila " << i << endl;
      for (int j = 0; j < n_columnas; j++)
  {
    cout << "Elemento " << j  << endl;
    cin >> elemento;
    matriz[i][j] = elemento;
        }
      cout << endl;
    }
  
}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed)
{
  srand(seed);
  for (int i = 0; i < n_filas; i++)
    for (int j = 0; j < n_columnas; j++)
      matriz[i][j]=rand();
  
}

// Imprimir Matriz
void Matriz::mostrarMatriz()
{
  for (int i = 0; i < n_filas; i++)
      {
  for (int j = 0; j < n_columnas; j++)
    cout << matriz[i][j] << " ";       
        cout << endl;
    }
}