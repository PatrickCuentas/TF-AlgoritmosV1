
// #include "HashTable.h"
// #include "BSTree.h"
#include "Blockchain.h"

using namespace std;
class Controladora
{
private:
    Blockchain *bc;
    // HashTable tablaHash;
    // BSTree bsTree;

public:
    Controladora()
    {
        bc = new Blockchain();
    }
    ~Controladora() {}

    void getCantidadBloques()
    {
        cout << "Cantidad de bloques " << bc->getCantidadBloques()<<endl;
    }

    void insertarBloque()
    {
        bc->insertarBloque();
    }

    void ingresarTransaccion(int index, string emisor, string receptor, float monto)
    {
        bc->ingresarTransaccion(index, emisor, receptor, monto);
    }

    void mostrarTransaccionesTotales()
    {
        bc->mostrarTransacciones();
    }

    // index = indice del bloque en la bc
    void indexarBloque(int index) // Evento desencadenado
    {
        if (bc->estaIndexado(index))
            return;

        if (!bc->sePuedeIndexar(index))
        {
            return;
        }

        // TODO: Obtener una key para la funcion hash y agregarlo a la hash table

        // TODO: Insertar la referencia del bloque al BST
        cout << "Indexando...";
    }
};
