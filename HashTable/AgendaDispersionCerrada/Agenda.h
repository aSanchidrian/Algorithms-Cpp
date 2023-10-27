#include <iostream>
#include <string>
using namespace std;

class Agenda
{
	int capacidad;  //Capacidad maxima de la tabla
    int n;  //Numero actual de elementos de la tabla
    string *nombres;    //Array de nombres
    long *telefonos;    //Array de telefonos
    bool *vacias;   //Array de posiciones ocupadas
    bool *borradas; //Array de posiciones borradas

public:
    Agenda(int capacidad);
    ~Agenda();
    int obtenerPosicion(long telefono);
    int buscarContacto(long telefono);
    int buscarHueco(long telefono);
    bool isLlena();
    bool existeContacto(long telefono);
    string getContacto(long telefono);
    void introducirContacto(long telefono, string contacto);
    void eliminarContacto(long telefono);
    void imprimir();
};