#pragma once
#ifndef INTERFAZADMINISTRADOR_H
#define INTERFAZADMINISTRADOR_H
#include <iostream>
#include "utils.h"
int mostrarProductos() {
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

#endif