//
// Created by mkuja on 4.9.2023.
//

#include <iostream>
#include <format>
#include <ctime>
#include <cstdlib>
#include "Game.h"

Game::Game(int maximumNumToGuess)
: maxNumber(maximumNumToGuess), playerGuess(-1), numOfGuesses(0), randomNumber((rand()%maximumNumToGuess)+1) {
    std::cout << std::format(
            "GAME CONSTRUCTOR: object initialized with {} as maximum value\n",
            maxNumber);
}

void Game::printGameResult() {
    std::cout << std::format("You guessed the right answer = {} with {} guesses\n",
                             this->randomNumber,
                             this->numOfGuesses);
}

void Game::play() {
    while (playerGuess != randomNumber) {
        std::cout << std::format("Give your guess between 1-{}\n",
                                 this->maxNumber);
        std::cin >> playerGuess;

        if (playerGuess < randomNumber) {
            std::cout << "Your guess is too small\n";
        }
        else if (playerGuess > randomNumber) {
            std::cout << "Your guess is too big\n";
        }
        numOfGuesses++;
    }
    printGameResult();
}

Game::~Game() {
    std::cout << "GAME DESTRUCTOR: object cleared from stack memory\n";
}
