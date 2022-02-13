#include "Controladora.h"
int main()
{
    Controladora *controladora = new Controladora();
    controladora->insertarBloque();
    controladora->insertarBloque();
    controladora->getCantidadBloques();
    controladora->ingresarTransaccion(0, "Patrick", "Ana", 500.50);
    controladora->ingresarTransaccion(0, "Juan", "Antonio", 1000.50);
    controladora->ingresarTransaccion(0, "Jorge", "Antony", 100.50);
    controladora->ingresarTransaccion(1, "Miguel", "Tom", 200.50);
    controladora->ingresarTransaccion(1, "Fill", "Adam", 900.50);
    controladora->mostrarTransaccionesTotales();
    controladora->indexarBloque(0);
    // controladora->show();
    return 0;
}