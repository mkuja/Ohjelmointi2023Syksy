//
// Created by mkuja on 6.9.2023.
//

#include "Kerros.h"

void Kerros::maaritaAsunnot() {
    std::cout << "Määritetään 4 kpl kerroksen asuntoja\n";
    as1.maarita(2, 100);
    as2.maarita(2, 100);
    as3.maarita(2, 100);
    as4.maarita(2, 100);
}

double Kerros::laskeKulutus(double d) {
    return d * 2.0;
}

Kerros::Kerros() {
    std::cout << std::format("Kerros luotu\n");
}

Kerros::~Kerros() {
    std::cout << std::format("Kerros tuhottu\n");
}
