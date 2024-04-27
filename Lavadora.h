#pragma once
#include "Electrodomestico.h"
#include "utils-f.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#ifndef LAVADORA_H
#define LAVADORA_H


class Lavadora : public Electrodomestico {
private:
    std::string tipoCarga;
    
public:
    Lavadora(const std::string& sku, const std::string& marca, double precio, int stock, const std::string& tipo, const std::string& tipoCarga)
        : Electrodomestico(generarSkuAleatorio(), marca, precio, stock, tipo), tipoCarga(tipoCarga) {}
    
    std::string getTipoCarga() const { return tipoCarga; }
    void setTipoCarga(const std::string& nuevoTipoCarga) { tipoCarga = nuevoTipoCarga; }

    std::string serializar() const {
        return Electrodomestico::serializar() + "," + tipoCarga;
    }

    static Lavadora deserializar(const std::string& cadena) {
        std::stringstream ss(cadena);
        std::string sku, marca, tipo, tipoCarga;
        double precio;
        int stock;

        if (std::getline(ss, sku, ',') &&
            std::getline(ss, marca, ',') &&
            (ss >> precio).ignore() &&
            (ss >> stock).ignore() &&
            std::getline(ss, tipo, ',') &&
            std::getline(ss, tipoCarga)) {

            return Lavadora(sku, marca, precio, stock, tipo, tipoCarga);
        }

        std::cerr << "Error al deserializar la cadena\n";
        return Lavadora("", "", 0.0, 0, "", "");
    }
};
#endif