//
// Created by mkuja on 6.9.2023.
//

#include "Kerros.h"

void Kerros::maaritaAsunnot() {
    std::cout << "Määritetään 4 kpl kerroksen asuntoja\n";
    as1->maarita(2, 100);
    as2->maarita(2, 100);
    as3->maarita(2, 100);
    as4->maarita(2, 100);
}

double Kerros::laskeKulutus(double d) {
    return d * 2.0;
}

Kerros::Kerros() {
    std::cout << std::format("Kerros luotu\n");
    as1 = new Asunto();
    as2 = new Asunto();
    as3 = new Asunto();
    as4 = new Asunto();
}

Kerros::~Kerros() {
    delete as1;
    delete as2;
    delete as3;
    delete as4;
    std::cout << std::format("Kerros tuhottu\n");
}
