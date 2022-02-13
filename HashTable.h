#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxColision = 3;
const float maxFillFactor = 0.5;

template <typename TK, typename TV>
class HashTable
{
private:
    struct Entry
    {
        TK key = " ";
        TV value = " ";
        size_t hashcode;
        Entry(TK key, TV value)
        {
            this->key = key;
            this->value = value;
        }
        bool isEmpty()
        {
            return key == " " && value == " ";
        }
    };
    list<Entry> *array;
    int capacity; // tamanio del array
    float size;   // cantidad de elementos totales

public:
    ChainHash()
    {
        // TODO: asignar un tamanio inicial al array
        this->capacity = 10;
        this->array = new list<Entry>[capacity];
        this->size = 0;
    }

    void setCapacity(int c) { this->capacity = c; }

    int getCapacity() { return this->capacity; }

    void set(TK key, TV value)
    {

        double factor = this->fillFactor();
        // cout << "Factor " << factor << endl;
        if (fillFactor() >= maxFillFactor)
        {
            rehashing();
        }
        size_t hashcode = getHashCode(key);
        int index = hashcode % this->capacity;
        cout << "Para la key " << key << " y el value: " << value << " el indice es: " << index << endl;
        // TODO: insertar el Entry(key, value) en index, manejando colisiones
        if (keyExists(key))
        {
            this->remove(key);
        }
        this->array[index].push_back(Entry(key, value));
        size++;
    }

    bool keyExists(TK key)
    {
        size_t hashcode = getHashCode(key);
        int index = hashcode % this->capacity;
        Entry *result = searchInList(index, key);
        if (result != nullptr)
            return true;
        else
            return false;
    }

    TV get(TK key)
    {
        size_t hashcode = getHashCode(key);
        int index = hashcode % this->capacity;
        Entry *result = searchInList(index, key);

        if (result != nullptr)
        {
            return result->value;
        }
        else
        {
            throw("La llave no existe");
        }
    }

    void remove(TK key)
    {
        size_t hashcode = getHashCode(key);
        int index = hashcode % capacity;
        auto it = find(array[index].begin(), array[index].end(), key);
        if (it == array[index].end())
            return;
        array[index].erase(it);
        this->size--;
    }

    template <class InputIterator, class T>
    InputIterator find(InputIterator first, InputIterator last, const T &val)
    {
        while (first != last)
        {
            if ((*first).key == val)
                return first;
            ++first;
        }
        return last;
    }

    Entry *searchInList(int index, TK key)
    {
        for (auto ite = array[index].begin();
             ite != array[index].end();
             ++ite)
        {
            if ((*ite).key == key)
            {
                Entry *resultado = new Entry((*ite).key, (*ite).value);
                return resultado;
            }
        }
        return nullptr;
    }

    void show()
    {
        for (int i = 0; i < capacity; i++)
        {
            for (auto ite = array[i].begin(); ite != array[i].end(); ++ite)
            {
                if (!ite->isEmpty())
                {
                    cout << "Key " << ite->key << " Value ";
                    cout << ite->value << endl;
                }
            }
        }
    }

    float bucket_count()
    {
        return this->size;
    }

    // TODO: implementar el operador corchete [ ]

    list<Entry> operator[](int index)
    {
        return this->array[index];
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

private:
    float fillFactor()
    {
        return size / (capacity * maxColision);
    }

    size_t getHashCode(TK key)
    {
        std::hash<TK> ptr_hash;
        return ptr_hash(key);
    }

    void rehashing()
    {
        cout << "rehashing" << endl;
        list<Entry> *array2 = new list<Entry>[this->capacity * 2];

        for (int i = 0; i < this->capacity; ++i)
        {
            for (auto iter = this->array[i].begin(); iter != this->array[i].end(); ++iter)
            {
                if (!iter->isEmpty())
                {
                    size_t hashcode = getHashCode((*iter).key);
                    int index = hashcode % (this->capacity * 2);
                    array2[index].push_back(Entry((*iter).key, (*iter).value));
                }
            }
        }
        setCapacity(this->capacity * 2);
        delete[] array;
        array = array2;
    }
};