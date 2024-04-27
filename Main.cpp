#include <iostream>
#include "Interfaz.h"
#include "Producto.h"
#include "utils.h"

int main() {
    std::string nombreArchivo = "productos_prueba.csv";
    crearYGuardarProductosDePrueba(nombreArchivo);

    int opcion;

    do {
        opcion = mostrarMenuInicio();

        switch (opcion) {
        case 1:
            mostrarMenuUsuario();
            break;
        case 2:
            mostrarMenuAdministrador();
            break;
        case 3:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opción inválida\n";
            break;
        }

    } while (opcion != 3);

    return 0;           

}
