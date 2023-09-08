
#include <QApplication>
#include "src/Calculator.h"

int main(int argc, char* argv[]) {
    auto app = QApplication(argc, argv);
    auto counter = Calculator();
    counter.show();
    app.exec();
}
