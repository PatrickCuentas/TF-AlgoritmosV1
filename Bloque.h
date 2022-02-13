#include <iostream>
using namespace std;

template <typename T>
struct Bloque
{
    // private:
    // Node<Bloque> *node;
    bool estaIndexado;
    string key;
    list<T> transacciones;
    int limiteTransacciones;

    Bloque()
    {
        // key = hashFunction(key);
        // index = key % capacity;
        estaIndexado = false;
        // key = " ";
        limiteTransacciones = 5;
    }

    bool getEstaIndexado()
    {
        return estaIndexado;
    }

    int getNumeroTransacciones()
    {
        return this->transacciones.size();
    }

    list<T> getLista()
    {
        return this->transacciones;
    }

    bool operator<(Bloque b)
    {
        // TODO:
        return this->nota < b.nota;
    }
    bool operator>(Bloque b)
    {
        // TODO:
        return this->nota < b.nota;
    }

    void ingresarTransaccion(T transaccion)
    {
        this->transacciones.push_back(transaccion);
    }

    void muestreAlgo()
    {
        cout << limiteTransacciones;
    }

    void indexarBloque()
    {
    }

    void InsertarEnHashTable()
    {

        // TODO: Obtener una key en base a las transacciones

        // TODO: Obtener el indice para insertar en la hashtable

        // TODO: Llamar al metodo set de la hashtable con el indice y el bloque

        // TODO:
    }

    void InsertarTransaccion(T transaccion)
    {
        if (this->transacciones.size() >= limiteTransacciones)
            return; // manejar un error de "excediste el tamanio del bloque..."
        this->transacciones.push_back(transaccion);
        // TODO: Debo de insertar un puntero al arreglo o lista de transacciones del usuario que realizo la transaccion

        return;
    }

    void mostrarTransacciones()
    {
        for (auto it = transacciones.begin(); it != transacciones.end(); ++it)
            cout << *it << endl;
        cout << '\n';
    }
};
