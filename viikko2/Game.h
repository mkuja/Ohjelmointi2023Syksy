//
// Created by mkuja on 4.9.2023.
//

#ifndef VIIKKOTEHTAVAT_GAME_H
#define VIIKKOTEHTAVAT_GAME_H


class Game {
public:
    explicit Game(int maximumNumToGuess);
    ~Game();

    void play();

private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

    void printGameResult();
};


#endif //VIIKKOTEHTAVAT_GAME_H
