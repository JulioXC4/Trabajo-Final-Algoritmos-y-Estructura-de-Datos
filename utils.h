#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <random>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "Producto.h"
#include "Lavadora.h"
#include "Electrodomestico.h"

bool existeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    return archivo.good();
}

void guardarProductos(const std::vector<Producto*>& productos, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (const auto& producto : productos) {
            if (auto lavadora = dynamic_cast<Lavadora*>(producto)) {
                archivo << lavadora->serializar() << "\n"; 
            }
            /*else if (auto televisor = dynamic_cast<Televisor*>(producto)) {
                archivo << televisor->serializar() << "\n"; 
            }
            else if (auto cafetera = dynamic_cast<Cafetera*>(producto)) {
                archivo << cafetera->serializar() << "\n"; 
            }
            else if (auto tostadora = dynamic_cast<Tostadora*>(producto)) {
                archivo << tostadora->serializar() << "\n"; 
            }*/
            else {
                archivo << producto->serializar() << "\n"; 
            }
        }
        archivo.close();
        std::cout << "Productos guardados correctamente en " << nombreArchivo << "\n";
    }
    else {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << "\n";
    }
}

std::vector<Producto*> cargarProductos(const std::string& nombreArchivo) {
    std::vector<Producto*> productos;
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream ss(linea);
            std::string marca, sku, precio, stock, tipo;

            std::getline(ss, sku, ',');
            std::getline(ss, marca, ',');
            std::getline(ss, precio, ',');
            std::getline(ss, stock, ',');
            std::getline(ss, tipo, ','); 

            Producto* nuevoProducto = nullptr;
            if (tipo == "Lavadora") {
                nuevoProducto = new Lavadora(Lavadora::deserializar(linea));
            }
            else {
                nuevoProducto = new Producto(Producto::deserializar(linea));
            }

            productos.push_back(nuevoProducto);
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
    std::vector<Producto*> productos;
    productos.push_back(new Lavadora("LAV001", "Samsung",500.0, 10, "Lavadora", "Carga Frontal"));
    productos.push_back(new Lavadora("LAV002", "LG", 600.0, 8, "Lavadora", "Carga Trasera"));

    guardarProductos(productos, nombreArchivo);

    for (auto& producto : productos) {
        delete producto;
    }

    if (existeArchivo(nombreArchivo)) {
        std::cout << "Archivo creado y productos de prueba guardados correctamente en " << nombreArchivo << "\n";
    }
    else {
        std::cerr << "Error al crear el archivo o guardar los productos de prueba\n";
    }
}

void agregarProductoAlArchivo(Producto* producto, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::out | std::ios::app);

    if (archivo.is_open()) {
        if (auto lavadora = dynamic_cast<Lavadora*>(producto)) {
            archivo << lavadora->serializar() << "\n";
        }
        /*else if (auto televisor = dynamic_cast<Televisor*>(producto)) {
            archivo << televisor->serializar() << "\n";
        }
        else if (auto cafetera = dynamic_cast<Cafetera*>(producto)) {
            archivo << cafetera->serializar() << "\n";
        }
        else if (auto tostadora = dynamic_cast<Tostadora*>(producto)) {
            archivo << tostadora->serializar() << "\n";
        }*/
        else {
            archivo << producto->serializar() << "\n";
        }

        archivo.close();
        std::cout << "Producto agregado correctamente al archivo " << nombreArchivo << "\n";
    }
    else {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << "\n";
    }
}

//void modificarProductoAlArchivo(Producto* producto, const std::string& nombreArchivo) {
//    std::ofstream archivo(nombreArchivo, std::ios::app);
//
//    if (archivo.is_open()) {
//        if (auto lavadora = dynamic_cast<Lavadora*>(producto)) {
//            archivo << lavadora->serializar() << "\n";
//        }
//        /*else if (auto televisor = dynamic_cast<Televisor*>(producto)) {
//            archivo << televisor->serializar() << "\n";
//        }
//        else if (auto cafetera = dynamic_cast<Cafetera*>(producto)) {
//            archivo << cafetera->serializar() << "\n";
//        }
//        else if (auto tostadora = dynamic_cast<Tostadora*>(producto)) {
//            archivo << tostadora->serializar() << "\n";
//        }*/
//        else {
//            archivo << producto->serializar() << "\n";
//        }
//
//        archivo.close();
//        std::cout << "Producto agregado correctamente al archivo " << nombreArchivo << "\n";
//    }
//    else {
//        std::cerr << "Error al abrir el archivo " << nombreArchivo << "\n";
//    }
//}

#endif