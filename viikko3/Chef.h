//
// Created by mkuja on 6.9.2023.
//

#ifndef VIIKKOTEHTAVAT_CHEF_H
#define VIIKKOTEHTAVAT_CHEF_H

#include <string>

class Chef {
public:
    Chef(std::string name);

    virtual ~Chef();

    void makeSalad();
    void makeSoup();

protected:
    std::string name;
};


#endif //VIIKKOTEHTAVAT_CHEF_H
