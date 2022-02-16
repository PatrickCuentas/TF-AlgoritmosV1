#include <iostream>
#include "Transaccion.h"
using namespace std;
struct Usuario
{
    string nombre;
    DoubleList<Transaccion>* transaccionesEmitidas;
    DoubleList<Transaccion>* transaccionesRecibidas;
    Usuario(string _nombre = "")
    {
        transaccionesEmitidas = new DoubleList<Transaccion>();
        transaccionesRecibidas = new DoubleList<Transaccion>();
        nombre = _nombre;
    }
};
