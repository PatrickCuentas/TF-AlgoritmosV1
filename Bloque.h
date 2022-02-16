#include "double.h"
#include "Usuario.h"

struct Bloque
{
    Node<Bloque>* node;
    string key;
    string prev_key;
    int index;
    DoubleList<Transaccion>* transacciones;
    int limiteTransacciones;

    Bloque() {
        // key = hashFunction(key);
        limiteTransacciones = 5;
        transacciones = nullptr;

        transacciones = new DoubleList<Transaccion>();
    }

    int getNumeroTransacciones() { return this->transacciones->size(); }
    string returnKey() { return this->key; }
     
    void insertarTransaccion(Transaccion transaccion) {
        //if (getNumeroTransacciones() >= this->limiteTransacciones)
        //    return;
        this->transacciones->push_back(transaccion);
        // TODO: Debo de insertar un puntero al arreglo o lista de transacciones del usuario que realizo la transaccion
        return;
    }

    string mostrarTransacciones() {
        if (this->transacciones == nullptr) {
            return "Esto es nulo :)";
        }
        string output = "";
        DoubleList<Transaccion>::Iterator it = transacciones->begin();
        for (it; it != transacciones->end(); ++it) {
            output.append((*it).getString());
            output.append("\n");
        }
        /*transacciones;
        for (auto it : *transacciones) {
            output = output + it.getString() + "\n";
        }*/
        return output;
    }

    string generarKey() {
        string temp_string = "000";
        temp_string = temp_string + to_string(transacciones->back().getEmisor()[0]) + to_string(transacciones->back().getEmisor()[0] * 1);
        temp_string = temp_string + to_string(transacciones->back().getReceptor()[0]) + to_string(transacciones->back().getReceptor()[0] * 1);
        temp_string = temp_string + to_string(transacciones->back().getMonto())[0] + to_string(transacciones->back().getMonto())[1];
        this->key = temp_string;
        return temp_string;
    }

    void setPrevKey(string _prevkey) {
        this->prev_key = _prevkey;
    }

    void setIndex(int _index) {
        this->index = _index;
    }

    int getIndex() { return this->index + 1; }

    string getKey() { return this->key; }
};
