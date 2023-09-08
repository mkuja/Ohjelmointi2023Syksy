//
// Created by mkuja on 8.9.2023.
//

#ifndef VIIKKOTEHTAVAT_CALCULATOR_H
#define VIIKKOTEHTAVAT_CALCULATOR_H

#include <memory>
#include <array>
#include <map>
#include <QtCore>
#include <QtWidgets>
#include <QLineEdit>
#include <QLabel>
#include "Button.h"

enum Op {
    INDETERMINATE,
    ADD,
    SUB,
    MUL,
    DIV
};

class Calculator : public QWidget {
    Q_OBJECT
public:
    explicit Calculator(QWidget *parent = nullptr, const Qt::WindowFlags &f = Qt::WindowFlags());

private slots:
    void calculations(); // Used whenever user clicks an operator.
    void eq();
    void reset();
    void num();
private:
    Op op {Op::INDETERMINATE};
    std::array<std::unique_ptr<Button>, 10> numBtns;
    std::array<std::unique_ptr<Button>, 4> opBtns; // Order of buttons is: +, -, *, /
    std::unique_ptr<Button> resetBtn;
    std::unique_ptr<Button> enterBtn;
    std::array<std::unique_ptr<QLabel>, 3> displayTags;
    std::array<std::pair<std::unique_ptr<QLineEdit>, std::unique_ptr<QString>>, 3> displays;

    int targetInputFocus {}; // Auxiliary ptr to either of the operand fields. Slot num() will input to this field more digits.

    // Auxiliary function for creating all the buttons.
    std::unique_ptr<Button> createButton(const QString& text, const char* slot);

    // Layout objects
    std::unique_ptr<QVBoxLayout> rootLayout;
    std::unique_ptr<QHBoxLayout> displaysLayout;
    std::array<std::unique_ptr<QVBoxLayout>, 3> operandDisplayLayout;
    std::unique_ptr<QGridLayout> buttonGridLayout;

    void createLayout();
    void populateNumBtns();
    void populateOpBtns();
    void switchOperandInputFocus();
    void resetOperandInputFocus();
    void updateNumBoxesContent();
};


#endif //VIIKKOTEHTAVAT_CALCULATOR_H
