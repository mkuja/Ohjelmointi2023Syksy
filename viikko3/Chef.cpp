//
// Created by mkuja on 6.9.2023.
//

#include <iostream>
#include <format>
#include "Chef.h"

Chef::Chef(std::string name) : name(name) {
    std::cout << std::format("Chef {} konstruktori\n", name);
}

void Chef::makeSalad() {
    std::cout << std::format("Chef {} makes salad\n", name);
}

void Chef::makeSoup() {
    std::cout << std::format("Chef {} makes soup\n", name);
}

Chef::~Chef() {
    std::cout << std::format("Chef {} destruktori\n", name);
}
