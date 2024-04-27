#include <iostream>
#include "Interfaz.h"
#include "Producto.h"
#include "utils.h"

int main() {
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

        /*if (opcionSeleccionada == 1 || opcionSeleccionada == 2) {
            std::string nombreArchivo = "productos_prueba.csv";
            
            crearYGuardarProductosDePrueba(nombreArchivo);

            std::vector<Producto> productosCargados = cargarProductos(nombreArchivo);
            for (const auto& producto : productosCargados) {
                std::cout << "Precio: " << producto.getPrecio() << std::endl;
                std::cout << "Stock: " << producto.getStock() << std::endl;
                std::cout << "-------------------" << std::endl;
            }
        }*/


}
