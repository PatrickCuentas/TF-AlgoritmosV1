#include <iostream>
#include <list>
using namespace std;
template <typename T>
struct Usuario
{
    string nombre;
    list<T> transaccionesEmitidas;
    list<T> transaccionesRecibidas;
    Usuario(string _nombre)
    {
        nombre = _nombre;
    }
};
