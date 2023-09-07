//
// Created by mkuja on 6.9.2023.
//

#ifndef VIIKKOTEHTAVAT_KATUTASO_H
#define VIIKKOTEHTAVAT_KATUTASO_H

#include "Asunto.h"
#include "Kerros.h"

class Katutaso: public Kerros {
public:
    Katutaso();

    Asunto as1;
    Asunto as2;

    void maaritaAsunnot() override;
    double laskeKulutus(double) override;

    ~Katutaso() override;
};


#endif //VIIKKOTEHTAVAT_KATUTASO_H
