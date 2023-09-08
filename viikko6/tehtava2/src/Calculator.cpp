//
// Created by mkuja on 8.9.2023.
//

#include <format>
#include "Calculator.h"

std::unique_ptr<Button> Calculator::createButton(const QString &text, const char *slot) {
    auto button = std::make_unique<Button>(text, this);
    connect(button.get(), SIGNAL(clicked()), slot);
    return button;
}

void Calculator::eq() {
    auto num1 = displays[0].second->toInt();
    auto num2 = displays[1].second->toInt();
    int result;
    switch (op) {
        case ADD:
            result = num1 + num2;
            break;
        case SUB:
            result = num1 - num2;
            break;
        case MUL:
            result = num1 * num2;
            break;
        case DIV:
            result = num1 / num2;
            break;
        default:
            return;
    }
    displays[2].second->push_back(QString::number(result));
    displays[2].first->setText(*displays[2].second);
    resetOperandInputFocus();
}

void Calculator::reset() {
    displays[0].second->clear();
    displays[0].first->setText( *displays[0].second );
    displays[1].second->clear();
    displays[1].first->setText( *displays[1].second );
    displays[2].second->clear();
    displays[2].first->setText( *displays[2].second );
    resetOperandInputFocus();
}

void Calculator::num() {
    auto s = qobject_cast<QPushButton*>(sender());
    qDebug() << s->text();
    displays[targetInputFocus].second->push_back(s->text());
    updateNumBoxesContent();
}

void Calculator::switchOperandInputFocus() {
    targetInputFocus = ++targetInputFocus % 2;
}

void Calculator::resetOperandInputFocus() {
    targetInputFocus = 0;
}

void Calculator::createLayout() {
    rootLayout = std::make_unique<QVBoxLayout>();
    displaysLayout = std::make_unique<QHBoxLayout>();
    buttonGridLayout = std::make_unique<QGridLayout>();
    rootLayout->addLayout(displaysLayout.get());
    rootLayout->addLayout(buttonGridLayout.get());
    std::array<const char*, 3> legend = {"op1", "op2", "result"};
    for (int i = 0; i < 3; i++) {
        // Add legend.
        operandDisplayLayout[i] = std::make_unique<QVBoxLayout>();
        displayTags[i] = std::make_unique<QLabel>(legend[i]);
        operandDisplayLayout[i]->addWidget(displayTags[i].get());

        // Add number box.
        displays[i].second = std::make_unique<QString>();
        displays[i].first = std::make_unique<QLineEdit>();
        operandDisplayLayout[i]->addWidget(displays[i].first.get());

        // Attach to parent layout.
        displaysLayout->addLayout(operandDisplayLayout[i].get());
    }
    resetOperandInputFocus();

    // Last two buttonsh
    resetBtn = createButton("reset", SLOT(reset()));
    enterBtn = createButton("enter", SLOT(eq()));
    buttonGridLayout->addWidget(resetBtn.get(), 3, 1);
    buttonGridLayout->addWidget(enterBtn.get(), 3, 2);
}

Calculator::Calculator(QWidget *parent, const Qt::WindowFlags &f)
: QWidget(parent, f) {
    createLayout();
    populateNumBtns();
    populateOpBtns();
    resetOperandInputFocus();
    setLayout(rootLayout.get());
}

void Calculator::populateNumBtns() {
    // Create and add number buttons from 1 to 9.
    for (char i = '1'; i <= '9'; i++) {
        const char str[2] = {i, '\0'};
        auto btn = createButton(str, SLOT(num()));
        numBtns[i-'0'] = std::move(btn);
        buttonGridLayout->addWidget(numBtns[i-'0'].get(),
                           (i - '1') / 3,
                           (i - '1') % 3);
    }
    numBtns[0] = createButton("0", SLOT(num()));
    buttonGridLayout->addWidget(numBtns[0].get(), 3, 0);
}

void Calculator::populateOpBtns() {
    auto counter = 0;
    for (const char* s: {"+", "-", "*", "/"}) {
        auto btn = createButton(s, SLOT(calculations()));
        opBtns[counter] = std::move(btn);
        buttonGridLayout->addWidget(opBtns[counter].get(), counter, 3);
        counter++;
    }
}

void Calculator::calculations() {
    auto operator_ = qobject_cast<QPushButton*>(sender());
    auto op_l = operator_->text();
    if (op_l == "+") {
        op = Op::ADD;
    }
    else if (op_l == "-") {
        op = Op::SUB;
    }
    else if (op_l == "*") {
        op = Op::MUL;
    }
    else if (op_l == "/") {
        op = Op::DIV;
    }
    switchOperandInputFocus();
}

void Calculator::updateNumBoxesContent() {
    for (const auto& p : displays) {
        p.first->setText(*p.second);
    }
}

