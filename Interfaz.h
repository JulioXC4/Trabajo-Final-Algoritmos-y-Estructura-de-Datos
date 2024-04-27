#pragma once
#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "InterfazCliente.h"

#include <iostream>

int mostrarMenuInicio() {
    int opcion;
    do {
        system("cls");
        std::cout << "Bienvenido a Oeschl \n";
        std::cout << "1. Ingresar como usuario\n";
        std::cout << "2. Ingresar como administrador\n";
        std::cout << "3. Salir\n";
        std::cout << "Ingrese su elección: ";
        std::cin >> opcion;

    } while (opcion < 1 || opcion >3);


    return opcion;
}

void mostrarMenuUsuario() {
    int opcion;
    do {
        system("cls");
        std::cout << "Bienvenido al menu de usuario \n";
        std::cout << "1. Ver lista de productos\n";
        std::cout << "2. Agregar productos al carrito de compras\n";
        std::cout << "3. Quitar productos del carrito de compras\n";
        std::cout << "4. Ver productos del carrito de compras\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese su elección: ";

        std::cin >> opcion;
        switch (opcion) {
        case 1:
            mostrarProductos();
            break;
        case 2:
            // Agregar productos al carrito
            break;
        case 3:
            // Quitar productos del carrito
            break;
        case 4:
            // Ver productos del carrito
            break;
        case 5:
            // Salir
            break;
        default:
            std::cout << "Opción inválida\n";
            break;
        }
    } while (opcion != 5);

}

void mostrarMenuAdministrador() {
    int opcion;
    do {
        system("cls");
        std::cout << "Bienvenido al menu de administrador \n";
        std::cout << "1. Ver lista de productos\n";
        std::cout << "2. Crear nuevo producto\n";
        std::cout << "3. Quitar producto\n";
        std::cout << "4. Ver pedidos\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese su elección: ";

        std::cin >> opcion;
    } while (opcion != 5);

}

#endif