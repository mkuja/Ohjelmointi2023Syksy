//
// Created by mkuja on 6.9.2023.
//

#ifndef VIIKKOTEHTAVAT_ASUNTO_H
#define VIIKKOTEHTAVAT_ASUNTO_H


class Asunto {
public:
    Asunto();
    int asukasmaara;
    int neliot;

    void maarita(int, int);
    double laskeKulutus(double);
};


#endif //VIIKKOTEHTAVAT_ASUNTO_H
