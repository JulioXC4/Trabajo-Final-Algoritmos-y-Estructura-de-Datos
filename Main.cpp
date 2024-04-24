#include <iostream>
#include "Interfaz.h"

int main() {
    int opcion;
    mostrarMenu();
    do {
       
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "Opción 1 seleccionada: Agregar producto" << std::endl;
            break;
        case 2:
            std::cout << "Opción 2 seleccionada: Mostrar carrito" << std::endl;
            break;
        case 3:
            std::cout << "Saliendo del programa..." << std::endl;
            break;
        default:
            std::cout << "Opción inválida. Inténtelo de nuevo." << std::endl;
            break;
        }
    } while (opcion != 3);

    return 0;
}
