
#include <QApplication>
#include "src/Counter.h"

int main(int argc, char* argv[]) {
    auto app = QApplication(argc, argv);
    auto counter = Counter();
    counter.show();
    app.exec();
}