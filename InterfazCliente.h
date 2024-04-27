#pragma once
#ifndef INTERFAZCLIENTE_H
#define INTERFAZCLIENTE_H
#include "utils.h"
#include "Lavadora.h"

#include <iostream>

void mostrarProductosUsuario() {
    system("cls");
    std::string nombreArchivo = "productos_prueba.txt";
    std::vector<Producto*> productosCargados = cargarProductos(nombreArchivo);
    std::cout << "Cantidad de productos cargados: " << productosCargados.size() << std::endl;

    std::cout << "Lista de productos:\n";
    for (const auto& producto : productosCargados) {
        std::cout << "Marca: " << producto->getMarca() << std::endl;
        std::cout << "Precio: " << producto->getPrecio() << std::endl;
        std::cout << "Stock: " << producto->getStock() << std::endl;

        if (Electrodomestico* electrodomestico = dynamic_cast<Electrodomestico*>(producto)) {
            std::cout << "Tipo: " << electrodomestico->getTipo() << std::endl;

            if (Lavadora* lavadora = dynamic_cast<Lavadora*>(electrodomestico)) {
                std::cout << "Tipo de carga: " << lavadora->getTipoCarga() << std::endl;
            }
        }
        std::cout << "-------------------" << std::endl;
    }

    std::cout << "Presione Enter para continuar...";
    std::cin.ignore();
    std::cin.get();

    int opcion;
    system("cls");
    do {
        std::cout << "Seccion de productos \n";
        std::cout << "1. Aplicar filtros por categorias\n";
        std::cout << "2. Volver\n";
        std::cout << "Ingrese su elección: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "Detalles del producto siguiente ...\n";
            break;
        case 2:
            break;
        default:
            std::cout << "Opción inválida\n";
            break;
        }
    } while (opcion != 2);
}

#endif