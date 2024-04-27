#pragma once
#include "Electrodomestico.h"

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
    Lavadora(double precio, const std::string& marca, const std::string& sku, int stock, const std::string& tipo, const std::string& tipoCarga)
        : Electrodomestico(precio, marca, sku, stock, tipo), tipoCarga(tipoCarga) {}

    std::string getTipoCarga() const { return tipoCarga; }
    void setTipoCarga(const std::string& nuevoTipoCarga) { tipoCarga = nuevoTipoCarga; }

    std::string serializar() const {
        return Electrodomestico::serializar() + "," + tipoCarga;
    }

    static Lavadora deserializar(const std::string& cadena) {
        std::stringstream ss(cadena);
        std::string electrodomesticoSerializado, tipoCarga;

        if (std::getline(ss, electrodomesticoSerializado, ',')) {
            Electrodomestico electrodomestico = Electrodomestico::deserializar(electrodomesticoSerializado);
            if (std::getline(ss, tipoCarga)) {
                return Lavadora(electrodomestico.getPrecio(), electrodomestico.getMarca(), electrodomestico.getSku(),
                    electrodomestico.getStock(), electrodomestico.getTipo(), tipoCarga);
            }
        }

        std::cerr << "Error al deserializar la cadena\n";
        return Lavadora(0.0, "", "", 0, "", "");
    }
};
#endif