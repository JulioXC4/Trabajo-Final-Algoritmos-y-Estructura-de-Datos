#pragma once
#ifndef INTERFAZADMINISTRADOR_H
#define INTERFAZADMINISTRADOR_H

#include <iostream>

#include "utils.h"
#include "Lavadora.h"

void mostrarProductosAdministrador() {
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
void crearProducto() {
    int opcionTipo;
    do {
        std::cout << "Seleccione el tipo de producto a crear:\n";
        std::cout << "1. Lavadora\n";

        std::cout << "Ingrese su elección: ";
        std::cin >> opcionTipo;

        switch (opcionTipo) {
        case 1: {
            std::string marca, sku, tipoCarga;
            double precio;
            int stock;

            std::cout << "Ingrese el SKU: ";
            std::cin >> sku;
            std::cout << "Ingrese la marca: ";
            std::cin >> marca;
            std::cout << "Ingrese el precio: ";
            std::cin >> precio;
            std::cout << "Ingrese el stock: ";
            std::cin >> stock;
            std::cout << "Ingrese el tipo de carga: ";
            std::cin >> tipoCarga;

            Producto* nuevoProducto = new Lavadora(sku, marca, precio, stock, "Lavadora", tipoCarga);
            break;
        }

        default:
            std::cout << "Opción inválida\n";
            break;
        }
    } while (opcionTipo != 1);
}
#endif