#include <iostream>
#include <list>
#include "Usuario.h"
#include "Bloque.h"
#include "Transaccion.h"
using namespace std;
class Blockchain
{
private:
    list<Usuario<Transaccion<float>>> usuarios;
    list<Bloque<Transaccion<float>>> bloques;

public:
    Blockchain()
    {
        // cout << bloques.size() << endl;
    }

    int getCantidadBloques()
    {
        return bloques.size();
    }

    // void AgregarUsuario(U usuario)
    // {
    //     this->usuarios.push_back(usuario);
    // }

    void insertarBloque()
    {
        // TODO: Anadir un bloque
        bloques.push_back(Bloque<Transaccion<float>>());
        cout << "Bloque insertado correctamente..." << endl;
    }

    void ingresarTransaccion(int index, string emisor, string receptor, float monto)
    {
        auto it = bloques.begin();
        advance(it, index);
        // cout << "Numero de transacciones: ";
        // (*it).getNumeroTransacciones();
        // cout << endl;
        // return;
        (*it).ingresarTransaccion(Transaccion<float>(emisor, receptor, monto));
        cout << "Transaccion ingresada al bloque " << index + 1 << " correctamente..." << endl;
    }

    bool estaIndexado(int index)
    {
        auto it = bloques.begin();
        advance(it, index);

        return (*it).getEstaIndexado();
    }

    bool sePuedeIndexar(int index)
    {
        auto it = bloques.begin();
        advance(it, index);
        cout << (*it).getNumeroTransacciones();
        return (*it).getNumeroTransacciones() >= 2;
    }

    void mostrarTransacciones()
    {
        int i = 1;
        for (auto ite = bloques.begin(); ite != bloques.end(); ++ite, i++)
        {
            cout << "Bloque " << i << endl;
            (*ite).mostrarTransacciones();
        }
    }
};