#include "HashTable.h"

class BlockChain {
    private:
    DoubleList<Usuario>* usuarios;
    //BSTree<Bloque<Transaccion>*>* porNombre;
    //BSTree<Bloque<Transaccion>*>* porNonce; // rango inicial : 20-100 , puede salir repetidos, cada 5 o 10 repetidos aumentar el rango de 20 a 120
    //BSTree<bloque<Transaccion>*>* por;

    HashTable* hashTable;

    public:
    BlockChain() {
        hashTable = new HashTable();
        usuarios = new DoubleList<Usuario>();
    }

    void setBlockinHashTable(Bloque bloque) {
        hashTable->set(bloque);
    }

    int getHashSize() {
        return hashTable->getSize();
    }

    bool verificarExistenciaBloque(string key) {
        return hashTable->keyExists(key);
    }

    void mostrarTodasLasTransacciones()
    {
        hashTable->mostrarTransacciones();
    }

    Bloque retornarBloque(string key)
    {
        return hashTable->retornarBloque(key);
    }
};
