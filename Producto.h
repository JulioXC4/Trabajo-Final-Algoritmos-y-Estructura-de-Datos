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
    Producto(const std::string& sku, const std::string& marca, double precio, int stock)
        : sku(sku), marca(marca), precio(precio), stock(stock) {}

    std::string getSku() const { return sku; }
    std::string getMarca() const { return marca; }
    double getPrecio() const { return precio; }
    int getStock() const { return stock; }

    void setPrecio(double nuevoPrecio) { precio = nuevoPrecio; }
    void setMarca(const std::string& nuevaMarca) { marca = nuevaMarca; }
    void setSku(const std::string& nuevoSku) { sku = nuevoSku; }
    void setStock(int nuevoStock) { stock = nuevoStock; }

    std::string serializar() const {
        return sku + "," + marca + "," + std::to_string(precio) + "," + std::to_string(stock);
    }
    static Producto deserializar(const std::string& cadena) {
        std::stringstream ss(cadena);
        std::string marca, sku;
        double precio;
        int stock;

        // Leer valores desde el stringstream
        if (ss >> sku >> marca >> precio >> stock) {
            return Producto(sku, marca, precio, stock);
        }
        else {
            std::cerr << "Error al deserializar la cadena\n";
            return Producto("", "", 0.0, 0);
        }
    }
};