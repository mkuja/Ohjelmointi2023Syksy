//
// Created by mkuja on 7.9.2023.
//

#ifndef VIIKKOTEHTAVAT_BUTTON_H
#define VIIKKOTEHTAVAT_BUTTON_H

#include <QtWidgets/QPushButton>

class Button: public QPushButton {
    Q_OBJECT
public:
    explicit Button(const QString &text, QWidget *parent = nullptr);
private:

};


#endif //VIIKKOTEHTAVAT_BUTTON_H
