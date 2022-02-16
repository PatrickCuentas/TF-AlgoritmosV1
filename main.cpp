#include "BlockChain.h"
using namespace std;
void menuMostrarBlockchain(BlockChain* myblockchain) {
    int ope = 0;
    system("clear");
    cout << "BlockChain";
    cout << "\n--------------\n";
    myblockchain->mostrarTodasLasTransacciones();

    while (ope != 1) {
        cout << "\nIngrese [1] para salir:\t";
        cin >> ope;
    }
}

void menuFiltrar(BlockChain* myblockchain) {}

void menuIngresarUsuario(BlockChain* myblockchain) {}

void menuAdminTransaccion(BlockChain* myblockchain, string usersession) {
    string temp_key;
    string emisor, receptor;
    double monto;
    int ope;
    int index = -1;
    while (ope != 4) {
        system("clear");
        cout << "Bienvenid@," << usersession << "\n\n";
        cout << "Ingresar Transacciones";
        cout << "\n--------------\n";
        cout << "\n[1]\tInsertar transaccion en un bloque Nuevo";
        cout << "\n[2]\tInsertar transaccion en un bloque Existente";
        cout << "\n[3]\tRegresar";
        cout << "\n\nIngrese una opcion: \t"; cin >> ope;

        if (ope == 1) {
            cout << "\n\nIngresando Transaccion en un bloque nuevo";
            cout << "\n--------------\n";
            Bloque temp_bloque;
            index = myblockchain->getHashSize();
            temp_bloque.setIndex(index);

            cout << "\n Ingresando Transaccion en el bloque:\t" << index + 1;
            cout << endl;
            cout << "\nIngrese el monto de la transaccion:\t"; cin >> monto;
            cout << "Asumiendo el usuario actual como emisor ...\t"; emisor = usersession;
            cout << "\nIngrese el nombre del receptor de la transaccion:\t"; cin >> receptor;

            Transaccion temp_trans = Transaccion(emisor, receptor, monto);
            temp_bloque.insertarTransaccion(temp_trans);
            myblockchain->setBlockinHashTable(temp_bloque);
        }

        if (ope == 2) {
            system("clear");
            cout << "Ingresando Transaccion en un bloque existente";
            cout << "\n--------------\n";
            do {
                cout << "\nPorfavor ingrese el Hashcode del bloque a modificar:\t";
                cin >> temp_key;
            } while (!myblockchain->verificarExistenciaBloque(temp_key));

            Bloque temp_bloque = myblockchain->retornarBloque(temp_key);

            cout << "\n Ingresando Transaccion en el bloque:\t" << temp_bloque.getIndex();
            cout << endl;
            cout << temp_bloque.mostrarTransacciones();
            cout << "\nIngrese el monto de la transaccion:\t"; cin >> monto;
            cout << "Asumiendo el usuario actual como emisor ...\t"; emisor = usersession;
            cout << "\nIngrese el nombre del receptor de la transaccion:\t"; cin >> receptor;

            Transaccion temp_trans = Transaccion(emisor, receptor, monto);
            temp_bloque.insertarTransaccion(temp_trans);
            myblockchain->setBlockinHashTable(temp_bloque);
        }
    }
    return;
}

void menuPrincipal(BlockChain* myblockchain, string usersession){
    int ope;
    while (ope != 5) {
        system("clear");
        cout << "Bienvenid@," << usersession << "\n\n";
        cout << "Menu principal";
        cout << "\n--------------\n";
        cout << "\n[1]\tAdministrar Transacciones";
        cout << "\n[2]\tIngresar Usuario";
        cout << "\n[3]\tMostrar Blockchain";
        cout << "\n[4]\tFiltrar/Buscar";
        cout << "\n[5]\tsalir";
        cout << "\n\nIngrese una opcion: \t";
        cin >> ope;
        switch (ope) {
            case 1: menuAdminTransaccion(myblockchain, usersession); break;
            case 2: menuIngresarUsuario(myblockchain); break;
            case 3: menuMostrarBlockchain(myblockchain); break;
            case 4: menuFiltrar(myblockchain); break;
        }
    }
}

string authUser() {
    string usersession;
    system("clear");
    cout << "Autenticacion de Usuario";
    cout << "\n--------------\n";
    cout << "\nPorfavor ingrese su nombre:\t";
    cin >> usersession;
    return usersession;
}

int main()
{
    BlockChain* myblockchain = new BlockChain();

    string usersession = authUser();
    menuPrincipal(myblockchain, usersession);
    system("PAUSE");
    return 0;
}
