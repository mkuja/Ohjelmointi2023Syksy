
#include <cstdlib>
#include <ctime>
#include "Game.h"

int main() {
    srand(time(0));
    auto g = Game(10);
    g.play();
}