#include "double.h"
#include "Bloque.h"

const int maxColision = 3;
const float maxFillFactor = 0.5;

class HashTable
{
private:
    DoubleList<Bloque>* array;
    int capacity; // tamanio del array
    int size;   // cantidad de elementos totales
    string lastKeyGen;

public:
    HashTable() {
        this->capacity = 10;
        this->array = new DoubleList<Bloque>[capacity];
        this->size = 0;
    }

    void setCapacity(int c) { this->capacity = c; }
    int getCapacity() { return this->capacity; }
    int getSize() {return this->size; }

    void set(Bloque block) {
        
        string key = block.generarKey();
        if (size == 0)
            this->lastKeyGen = "00000000000";
        else this->lastKeyGen = key;

        block.setPrevKey(lastKeyGen);

        double factor = this->fillFactor();
        if (fillFactor() >= maxFillFactor) {
            rehashing();
        }
        size_t hashcode = getHashCode(key);
        int index = hashcode % this->capacity;
        this->array[index].push_back(block);
        size++;
    }

    size_t getHashCode(string key) {
        size_t hash = 0;
        for (int i = 0; i < key.length(); ++i)
            hash = hash + (key[i] * 1) * i;
        return hash;
    }

    bool keyExists(string key) {
        size_t hashcode = getHashCode(key);
        int index = hashcode % this->capacity;

        //if (array[index].generarKey() == key)
        if (array->_find(index)->data.generarKey() == key)
            return true;
        else
            return false;
    }

    Bloque* searchInList(int index, string key)
    {
        //array->_find()
    }

    Bloque* get(string key)
    {
        size_t hashcode = getHashCode(key);
        int index = hashcode % this->capacity;
        return searchInList(index, key);

        //Bloque<Transaccion>* bloque = searchInList(index, key);
        //if ( bloque != nullptr){return result; }
        //else{ return nullptr; }
    }

    void mostrarTransacciones()
    {
        for (int i = 0; i < capacity; ++i) {
            cout << endl << "Lista" << endl;
            for (auto bloque : this->array[i]) {
                cout << "--------------------------------------" << endl;
                cout<<"\tBloque " << bloque.getIndex()<< endl;
                cout << "\tKey: " << bloque.getKey() << endl;
                cout << "--------------------------------------" << endl;
                cout << "\tTransacciones" << endl;
                cout << bloque.mostrarTransacciones() << endl;
            }
            cout << endl;
        }
    }

    float bucket_count()
    {
        return this->size;
    }

    Bloque operator[](int index)
    {
        return array->_find(index)->data;
    }

    auto begin(int i)
    {
        return this->array[i].begin();
    }
    auto end(int i)
    {
        return this->array[i].end();
    }

    int bucket_size(int index)
    {
        return this->array[index].size();
    }

    Bloque retornarBloque(string key) {
        int index = getHashCode(key) % capacity;
        return array->_find(index)->data;
    }

private:
    float fillFactor()
    {
        return size / (capacity * maxColision);
    }

    void rehashing()
    {
        cout << "rehashing" << endl;
        DoubleList<Bloque>* array2 = new DoubleList<Bloque>[this->capacity * 2];

        //for (int i = 0; i < this->capacity; ++i)
        //{
        //    for (auto iter = this->array[i].begin(); iter != this->array[i].end(); ++iter)
        //    {
        //        if (!iter->isEmpty())
        //        {
        //            size_t hashcode = getHashCode((*iter).key);
        //            int index = hashcode % (this->capacity * 2);
        //            array2[index].push_back(Bloque((*iter).key, (*iter).value));
        //        }
        //    }
        //}



        setCapacity(this->capacity * 2);
        delete[] array;
        array = array2;
    }
};


