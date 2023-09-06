//
// Created by mkuja on 6.9.2023.
//

#include <iostream>
#include <format>
#include "ItalianChef.h"
#include "Chef.h"

ItalianChef::ItalianChef(std::string name, int vesi, int jauhot) : Chef(name), vesi(vesi), jauhot(jauhot) {
    std::cout << std::format("ItalianChef {} konstruktori\n", name);
}

std::string ItalianChef::getName() {
    return name;
}

void ItalianChef::makePasta(int vesi, int jauhot) {
    std::cout << std::format("Chef {} makes pasta with special recipe\n", name, vesi, jauhot);
    std::cout << std::format("Chef {} uses {} jauhot\n", name, jauhot);
    std::cout << std::format("Chef {} uses {} vesi\n", name, vesi);
}

