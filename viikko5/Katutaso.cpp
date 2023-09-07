//
// Created by mkuja on 6.9.2023.
//

#include <iostream>
#include <format>
#include "Katutaso.h"

void Katutaso::maaritaAsunnot() {
    std::cout << "Maaritetaan 2 kpl katutason asuntoja\n";
    as1 = new Asunto();
    as2 = new Asunto();
    as1->maarita(2, 100);
    as2->maarita(2, 100);
}

Katutaso::Katutaso() {
    std::cout << "Katutaso luotu\n";
}

Katutaso::~Katutaso() {
    delete as1;
    delete as2;
    std::cout << "Katutaso tuhottu\n";

}

double Katutaso::laskeKulutus(double jotain) {
    return jotain * 1200.0;
}
