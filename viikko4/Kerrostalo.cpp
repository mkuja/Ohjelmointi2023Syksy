//
// Created by mkuja on 6.9.2023.
//

#include <iostream>
#include <format>
#include "Kerrostalo.h"

Kerrostalo::Kerrostalo() {
    std::cout << "Kerrostalo luotu\n";
    std::cout << "Määritetään kerrostalon kaikki asunnot.\n";
    eka.maaritaAsunnot();
    toka.maaritaAsunnot();
    Kolmas.maaritaAsunnot();
}

Kerrostalo::~Kerrostalo() {

}

double Kerrostalo::laskeKulutus(double a) {
    auto kulutus = eka.laskeKulutus(a) + toka.laskeKulutus(a) + Kolmas.laskeKulutus(a);
    std::cout << std::format("Kerrostalon kulutus,= {}\n", kulutus);
    return kulutus;
}
