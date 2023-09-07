//
// Created by mkuja on 7.9.2023.
//

#ifndef VIIKKOTEHTAVAT_COUNTER_H
#define VIIKKOTEHTAVAT_COUNTER_H

#include <memory>
#include <QTCore>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include "Button.h"

class Counter: public QWidget {
    Q_OBJECT
public:
    Counter(QWidget *parent = nullptr);

private slots:
    void countClicked();
    void resetClicked();
private:
    int counter;
    std::unique_ptr<QLineEdit> display;
    std::unique_ptr<Button> countBtn;
    std::unique_ptr<Button> resetBtn;
    std::unique_ptr<QString> displayText;
    std::unique_ptr<QGridLayout> layout;

    std::unique_ptr<Button> createButton(const QString& str, const char* slot);
};


#endif //VIIKKOTEHTAVAT_COUNTER_H
