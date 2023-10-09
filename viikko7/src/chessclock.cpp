//
// Created by mkuja on 8.10.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ChessClock.h" resolved

#include <QTimer>
#include "chessclock.h"
#include "ui_ChessClock.h"


ChessClock::ChessClock(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::ChessClock), p_timer(new QTimer(this)) {
    ui->setupUi(this);
    p_timer->setInterval(100);
    connect(p_timer, &QTimer::timeout, this, &ChessClock::updateBars);
    p_timer->start();
    ui->player1_progress->setMinimum(0);
    ui->player2_progress->setMinimum(0);
    ui->player1_progress->setMaximum(100);
    ui->player2_progress->setMaximum(100);
    ui->player1_progress->setValue(0);
    ui->player2_progress->setValue(0);
}

ChessClock::~ChessClock() {
    delete ui;
}

void ChessClock::updateBars() {
    if (gameIsRunning) {
        *selectedPlayerTimeLeft -= 0.1;
        ui->player1_progress->setValue(100.0 * (player2TimeLeft / timeAtStart));
        ui->player2_progress->setValue(100.0 * (player1TimeLeft / timeAtStart));
        ui->player1_progress->update();
        ui->player2_progress->update();
        if (ui->player1_progress->value() == 0) {
            ui->label->setText("Player 1 ran out of time!");
        }
        else if (ui->player2_progress->value() == 0) {
            ui->label->setText("Player 2 ran out of time!");
        }
    }
}

void ChessClock::setTwoMinutes() {
    timeAtStart = 120.0;
    player1TimeLeft = timeAtStart;
    player2TimeLeft = timeAtStart;
}

void ChessClock::setFiveMinutes() {
    timeAtStart = 60.0 * 5.0;
    player1TimeLeft = timeAtStart;
    player2TimeLeft = timeAtStart;
}

void ChessClock::startGame() {
    gameIsRunning = true;
    if (selectedPlayerTimeLeft == &player1TimeLeft) {
        ui->label->setText("Player 2 to move...");
    }
    else {
        ui->label->setText("Player 1 to move...");
    }
}

void ChessClock::endGame() {
    gameIsRunning = false;
    ui->label->setText("Game timer paused.");
}

void ChessClock::player1Move() {
    if (!gameIsRunning) return;
    selectedPlayerTimeLeft = &player1TimeLeft;
    ui->label->setText("Player 2 to move...");
}

void ChessClock::player2Move() {
    if (!gameIsRunning) return;
    selectedPlayerTimeLeft = &player2TimeLeft;
    ui->label->setText("Player 1 to move...");
}
