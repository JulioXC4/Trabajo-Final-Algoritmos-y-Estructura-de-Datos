#pragma once
#include "Producto.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#ifndef ELECTRODOMESTICO_H
#define ELECTRODOMESTICO_H

class Electrodomestico : public Producto {
private:
    std::string tipo;

public:
    Electrodomestico(double precio, const std::string& marca, const std::string& sku, int stock, const std::string& tipo)
        : Producto(precio, marca, sku, stock), tipo(tipo) {}

    std::string getTipo() const { return tipo; }
    void setTipo(const std::string& nuevoTipo) { tipo = nuevoTipo; }

    std::string serializar() const {
        return Producto::serializar() + "," + tipo;
    }

    static Electrodomestico deserializar(const std::string& cadena) {
        std::stringstream ss(cadena);
        std::string productoSerializado, tipo;

        if (std::getline(ss, productoSerializado, ',')) {
            Producto producto = Producto::deserializar(productoSerializado);
            if (std::getline(ss, tipo)) {
                return Electrodomestico(producto.getPrecio(), producto.getMarca(), producto.getSku(),
                    producto.getStock(), tipo);
            }
        }

        std::cerr << "Error al deserializar la cadena\n";
        return Electrodomestico(0.0, "", "", 0, "");
    }
};

#endif