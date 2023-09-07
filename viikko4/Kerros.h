//
// Created by mkuja on 6.9.2023.
//

#ifndef VIIKKOTEHTAVAT_KERROS_H
#define VIIKKOTEHTAVAT_KERROS_H

#include <iostream>
#include <format>
#include "Asunto.h"

class Kerros {
public:
    Kerros();

    Asunto as1;
    Asunto as2;
    Asunto as3;
    Asunto as4;

    virtual void maaritaAsunnot();

    virtual ~Kerros();

    virtual double laskeKulutus(double d);
};


#endif //VIIKKOTEHTAVAT_KERROS_H
