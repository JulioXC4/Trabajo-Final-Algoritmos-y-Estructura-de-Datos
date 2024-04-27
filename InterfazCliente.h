#pragma once
#ifndef INTERFAZCLIENTE_H
#define INTERFAZCLIENTE_H
#include "utils.h"
#include <iostream>

void mostrarProductos() {
    std::string nombreArchivo = "productos_prueba.csv";
    std::vector<Producto> productosCargados = cargarProductos(nombreArchivo);
    int opcion;
    system("cls");
    do {
        std::cout << "Seccion de productos \n";
        std::cout << "1. Ver detalle de producto\n";
        std::cout << "2. Salir\n";
        std::cout << "Ingrese su elección: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "Detalles de productos:\n";
            for (const auto& producto : productosCargados) {
                std::cout << "Precio: " << producto.getPrecio() << std::endl;
                std::cout << "Stock: " << producto.getStock() << std::endl;
                std::cout << "-------------------" << std::endl;
            }
            break;
        case 2:
            // Salir
            break;
        default:
            std::cout << "Opción inválida\n";
            break;
        }
    } while (opcion != 2);

}

#endif