//
// Created by mkuja on 6.9.2023.
//

#include <iostream>
#include <format>
#include "Asunto.h"

void Asunto::maarita(int asukkaita, int nelioita) {
    asukasmaara = asukkaita;
    neliot = nelioita;
    std::cout << std::format("Asunto maaritetty asukkaita= {} nelioita= {}\n", asukasmaara, neliot);
}

double Asunto::laskeKulutus(double) {
    return 400.0;
}

Asunto::Asunto() {
    std::cout << std::format("asunto luotu\n");
}
