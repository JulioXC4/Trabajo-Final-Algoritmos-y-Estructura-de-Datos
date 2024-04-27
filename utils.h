#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Producto.h"

bool existeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    return archivo.good();
}

void guardarProductos(const std::vector<Producto>& productos, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (const auto& producto : productos) {
            archivo << producto.serializar() << "\n";
        }
        archivo.close();
        std::cout << "Productos guardados correctamente en " << nombreArchivo << "\n";
    }
    else {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << "\n";
    }
}


std::vector<Producto> cargarProductos(const std::string& nombreArchivo) {
    std::vector<Producto> productos;
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            productos.push_back(Producto::deserializar(linea));
        }
        archivo.close();
        std::cout << "Productos cargados correctamente desde " << nombreArchivo << "\n";
    }
    else {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << "\n";
    }
    return productos;
}

void crearYGuardarProductosDePrueba(const std::string& nombreArchivo) {
    std::vector<Producto> productosPrueba;
    productosPrueba.push_back(Producto(10.99, "Marca1", "SKU1", 100));
    productosPrueba.push_back(Producto(20.49, "Marca2", "SKU2", 50));
    productosPrueba.push_back(Producto(15.75, "Marca3", "SKU3", 75));

    guardarProductos(productosPrueba, nombreArchivo);

    if (existeArchivo(nombreArchivo)) {
        std::cout << "Archivo creado y productos de prueba guardados correctamente en " << nombreArchivo << "\n";
    }
    else {
        std::cerr << "Error al crear el archivo o guardar los productos de prueba\n";
    }
}
#endif