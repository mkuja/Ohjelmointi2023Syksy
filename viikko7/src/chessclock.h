//
// Created by mkuja on 8.10.2023.
//

#ifndef VIIKKOTEHTAVAT_CHESSCLOCK_H
#define VIIKKOTEHTAVAT_CHESSCLOCK_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class ChessClock; }
QT_END_NAMESPACE

class ChessClock : public QMainWindow {
Q_OBJECT

public:
    explicit ChessClock(QWidget *parent = nullptr);
    ~ChessClock() override;

public slots:
    void player1Move();
    void player2Move();
    void startGame();
    void endGame();
    void setTwoMinutes();
    void setFiveMinutes();
    void updateBars();

private:
    double player1TimeLeft{};
    double player2TimeLeft{};
    double timeAtStart{};
    double *selectedPlayerTimeLeft {&player2TimeLeft};
    bool gameIsRunning{};
    QTimer* p_timer;


    Ui::ChessClock *ui;
};


#endif //VIIKKOTEHTAVAT_CHESSCLOCK_H
