//
// Created by mkuja on 6.9.2023.
//

#ifndef VIIKKOTEHTAVAT_KERROSTALO_H
#define VIIKKOTEHTAVAT_KERROSTALO_H

#include "Katutaso.h"
#include "Kerros.h"

class Kerrostalo {
public:
    virtual ~Kerrostalo();

    Kerrostalo();

    double laskeKulutus(double);
private:
    Katutaso eka;
    Kerros toka;
    Kerros Kolmas;
};


#endif //VIIKKOTEHTAVAT_KERROSTALO_H
