#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define reset "\e[0m"

bool guessing_game(unsigned max_num, unsigned attempts);
int prompt_int(std::string prompt);

int main() {
    std::cout << "Hello! Let's play a guessing game.\n" <<
                 "Press Ctrl+D (Ctrl+Z on Windows) to quit.\n" << std::endl;

    while (std::cin.good()) {
        int max = prompt_int("Please input largest positive integer to be guessed: ");
        int attempts = prompt_int(("\nThanks. Now please state how many attempts you want to have at it: "));
        if (max < 0 || attempts < 0) break;

        if (guessing_game(max, attempts) && !std::cin.eof()) {
            std::cout << BGRN << "\nYay! You got it!" << reset << "\n";
        }
        else {
            std::cout << BRED << "\nOh woes! You failed." << reset << "\n";
        }
    }
    return 0;
}

bool guessing_game(unsigned max_num, unsigned attempts) {
    static bool rand_initialized {};
    if (!rand_initialized) {
        std::srand(time(0));
    }

    auto the_num = (1+ rand()) % (max_num + 1);
    while (attempts-- && std::cin.good()) {
        int guess {};
        std::cout << "Guess. What number is it? ";
        std::cin >> guess;

        if (guess < the_num) {
            std::cout << "It's bigger.\n";
        }
        else if (guess > the_num) {
            std::cout << "It's smaller.\n";
        }
        else {
            std::cout << "You got it right!\n";
            return true;
        }
    }

    return false;
}

int prompt_int(std::string prompt) {
    std::cout << prompt;
    int result = -1;
    while (result < 1 && std::cin.good()) {
        std::cin >> result;
        if (result < 1) {
            std::cout << "Input must be a positive integer.\n\n";
        }
    }
    if (std::cin.eof()) return -1;
    return result;
}


