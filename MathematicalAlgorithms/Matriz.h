#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
 public:
  Matriz();
  Matriz(int, int);
  Matriz(const Matriz &m);
  ~Matriz();
  
  Matriz operator+ (const Matriz &m);
  Matriz operator- (const Matriz &m);
  Matriz operator* (const Matriz &m);
  Matriz operator* (double a);
  Matriz& operator= (const Matriz &m);
  Matriz calcularTraspuesta();
  
  bool esSimetrica();
  
  double obtenerMaximo();
  double obtenerMinimo();

/* Calcula el determinante de una matriz
	   Parametro: Ninguno
	   Retorno: El determinante de la matriz
	   Precondicion: Matriz cuadrada
	   Complejidad Temporal: 
	   Complejidad Espacial: 
*/
  double calcularDeterminante();
  
  void rellenarManual();
  void rellenarAleatorio(long seed);
  void mostrarMatriz();
  
 private:
  double **matriz;
  
  int n_filas;
  int n_columnas;
};

#endif // MATRIZ_H
