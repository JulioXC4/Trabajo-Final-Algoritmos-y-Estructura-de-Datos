#pragma once
#include <string>
#include <fstream>
#include <sstream>

class Producto {
private:
    double precio;
    std::string marca;
    std::string sku;
    int stock;

public:
    virtual ~Producto() {}
    Producto(double precio, const std::string& marca, const std::string& sku, int stock)
        : precio(precio), marca(marca), sku(sku), stock(stock) {}

    double getPrecio() const { return precio; }
    std::string getMarca() const { return marca; }
    std::string getSku() const { return sku; }
    int getStock() const { return stock; }

    void setPrecio(double nuevoPrecio) { precio = nuevoPrecio; }
    void setMarca(const std::string& nuevaMarca) { marca = nuevaMarca; }
    void setSku(const std::string& nuevoSku) { sku = nuevoSku; }
    void setStock(int nuevoStock) { stock = nuevoStock; }

    std::string serializar() const {
        return marca + "," + sku + "," + std::to_string(precio) + "," + std::to_string(stock);
    }
    static Producto deserializar(const std::string& cadena) {
        std::stringstream ss(cadena);
        std::string marca, sku;
        double precio;
        int stock;

        // Leer valores desde el stringstream
        if (ss >> marca >> sku >> precio >> stock) {
            return Producto(precio, marca, sku, stock);
        }
        else {
            std::cerr << "Error al deserializar la cadena\n";
            return Producto(0.0, "", "", 0);
        }
    }
};