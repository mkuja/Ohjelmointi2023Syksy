//
// Created by mkuja on 7.9.2023.
//

#include <memory>
#include "Counter.h"
#include "Button.h"

void Counter::countClicked() {
    counter++;
    displayText = std::make_unique<QString>(QString::number(counter));
    display->setText(*displayText);
}

void Counter::resetClicked() {
    counter = 0;
    displayText = std::make_unique<QString>(QString::number(counter));
    display->setText(*displayText);
}

std::unique_ptr<Button> Counter::createButton(const QString &str, const char* slot) {
    auto button = std::make_unique<Button>(str, this);
    connect(button.get(), SIGNAL(clicked()), slot);
    return button;
}

Counter::Counter(QWidget *parent)
: QWidget(parent), counter(0), display(std::make_unique<QLineEdit>(this)),
  countBtn(createButton("Count", SLOT(countClicked()))), resetBtn(createButton("Reset", SLOT(resetClicked()))),
  displayText(std::make_unique<QString>(QString::number(counter))),
  layout(std::make_unique<QGridLayout>()) {

    display->setText(*displayText);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    layout->addWidget(countBtn.get(), 0, 0);
    layout->addWidget(resetBtn.get(), 1, 0);
    layout->addWidget(display.get(), 0, 1);
    setLayout(layout.get());
}

