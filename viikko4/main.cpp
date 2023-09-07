#include "Kerrostalo.h"
#include "Katutaso.h"


int main() {
    auto kt = Kerrostalo();
    std::cout << kt.laskeKulutus(15.0) << "\n";
    return 0;
}