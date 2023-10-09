#include <QApplication>
#include "ui/ui_main_window.h"

int main(int argc, char **argv) {
    auto a = QApplication(argc, argv);
    auto w = Ui_MainWindow(nullptr);
    auto mw = QMainWindow();
    w.setupUi(&mw);
    mw.show();
    return a.exec();
}