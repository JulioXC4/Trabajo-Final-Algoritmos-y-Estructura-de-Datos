#include <iostream>
#include "Interfaz.h"

int main() {
    int opcion;
    mostrarMenu();
    do {
       
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "Opci�n 1 seleccionada: Agregar producto" << std::endl;
            break;
        case 2:
            std::cout << "Opci�n 2 seleccionada: Mostrar carrito" << std::endl;
            break;
        case 3:
            std::cout << "Saliendo del programa..." << std::endl;
            break;
        default:
            std::cout << "Opci�n inv�lida. Int�ntelo de nuevo." << std::endl;
            break;
        }
    } while (opcion != 3);

    return 0;
}
