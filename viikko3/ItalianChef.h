//
// Created by mkuja on 6.9.2023.
//

#ifndef VIIKKOTEHTAVAT_ITALIANCHEF_H
#define VIIKKOTEHTAVAT_ITALIANCHEF_H

#include "Chef.h"

class ItalianChef: public Chef {
public:
    ItalianChef(std::string name, int vesi, int jauhot);

    std::string getName();
    void makePasta(int vesi, int jauhot);

private:
    int vesi;
    int jauhot;
};


#endif //VIIKKOTEHTAVAT_ITALIANCHEF_H
