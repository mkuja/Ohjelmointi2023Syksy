#include <QApplication>
#include "src/chessclock.h"

int main(int argc, char *argv[]) {
    auto app = QApplication(argc, argv);
    auto cc = ChessClock();
    cc.show();
    app.exec();
}