
#include <string>
#include "Chef.h"
#include "ItalianChef.h"

using namespace std::literals;

int main() {
    Chef a("Pirkko");
    ItalianChef b("Pekka", 4, 4);
    a.makeSalad();
    a.makeSoup();
    b.makePasta(1,2);
}