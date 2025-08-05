//
// Created by vitor on 01/08/2025.
//

#include "ConsoleUtils.h"
#include <iostream>

void ConsoleUtils::printTituloCentralizado(const std::string& titulo, int largura) {
    if ((int)titulo.size() >= largura) {
        std::cout << titulo << "\n";
        return;
    }

    int espacos = (largura - (int)titulo.size()) / 2;
    std::string linha(largura, '=');

    std::cout << linha << "\n";
    std::cout << std::string(espacos, ' ') << titulo << "\n";
    std::cout << linha << "\n";
}
