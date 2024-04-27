#pragma once
#include "Producto.h"
#include "utils.h"

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
    Electrodomestico(const std::string& sku, const std::string& marca, double precio, int stock, const std::string& tipo)
        : Producto(sku, marca, precio, stock), tipo(tipo) {}

    std::string getTipo() const { return tipo; }
    void setTipo(const std::string& nuevoTipo) { tipo = nuevoTipo; }

    std::string serializar() const {
        return Producto::serializar() + "," + tipo;
    }

    static Electrodomestico deserializar(const std::string& cadena) {
        std::stringstream ss(cadena);
        std::string marca, sku, tipo;
        double precio;
        int stock;

        if (std::getline(ss, sku, ',') &&
            std::getline(ss, marca, ',') &&
            (ss >> precio).ignore() &&
            (ss >> stock).ignore() &&
            std::getline(ss, tipo)) {
            return Electrodomestico(sku, marca, precio, stock, tipo);
        }

        std::cerr << "Error al deserializar la cadena\n";
        return Electrodomestico("", "", 0.0, 0, "");
    }
};

#endif