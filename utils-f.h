#pragma once
#ifndef UTILS_F_H
#define UTILS_F_H

#include <random>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

std::string generarSkuAleatorio() {
    const std::string caracteresValidos = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    constexpr int longitudSku = 6;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribucion(0, caracteresValidos.size() - 1);

    std::string sku;
    for (int i = 0; i < longitudSku; ++i) {
        sku += caracteresValidos[distribucion(gen)];
    }
    return sku;
}
#endif