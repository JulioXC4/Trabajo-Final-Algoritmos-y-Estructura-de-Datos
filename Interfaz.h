#pragma once
#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "InterfazCliente.h"
#include "InterfazAdministrador.h"

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
        std::cout << "Panel de Usuario \n";
        std::cout << "1. Ver lista de productos\n";
        std::cout << "2. Agregar productos al carrito de compras\n";
        std::cout << "3. Quitar productos del carrito de compras\n";
        std::cout << "4. Ver productos del carrito de compras\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese su elección: ";

        std::cin >> opcion;
        switch (opcion) {
        case 1:
            mostrarProductosUsuario();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
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
        std::cout << "Panel de Administrador \n";
        std::cout << "1. Ver lista de productos\n";
        std::cout << "2. Crear producto\n";
        std::cout << "3. Quitar producto\n";
        std::cout << "4. Modificar producto\n";
        std::cout << "5. Ver pedidos\n";
        std::cout << "6. Volver\n";
        std::cout << "Ingrese su elección: ";

        std::cin >> opcion;
        switch (opcion) {
        case 1:
            mostrarProductosAdministrador();
            break;
        case 2:
            crearProducto();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            std::cout << "Opción inválida\n";
            break;
        }
    } while (opcion != 6);

}

#endif