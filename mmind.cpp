/* Copyright (C) 2019 Philip C. Blum.
 * This program is distributed under the terms of the GNU General Public
 * License version 3 or any later version.
 */
#include <iostream>
#include "console.h"
#include "game_engine.h"

using namespace std;
using namespace mastermind::gamePlay;
using namespace mastermind::strategy;

void unit_test()
{
    Scorer scorer;
    scorer.unit_test();

    Guesser guesser(std::move(Guess_Checker()));
    guesser.unit_test();

    std::cout << "All tests pass" << std::endl << std::endl;
}

void print_version() { std::cout << "MasterMind version 1.5" << std::endl; }

void print_copyright()
{
    std::cout << "mmind  Copyright (C) 2019 Philip C. Blum" << std::endl;
    std::cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'." << std::endl;
    std::cout << "This is free software, and you are welcome to redistribute it" << std::endl;
    std::cout << "under certain conditions; type `show c' for details." << std::endl;
    std::cout << std::endl;
}

void print_usage()
{
    std:: cout << "usage: mmind (1|2)" << std::endl;
    std:: cout << "mmind 1: Computer guesses your pattern" << std::endl;
    std:: cout << "mmind 2: You guess computer's pattern" << std::endl;
}

int main(int argc, char *argv[])
{
    print_version();
    print_copyright();

    if(argc != 2) { print_usage(); return -1; }
    unsigned mode = stoul(argv[1]);
    if(mode != 1 && mode != 2) { print_usage(); return -1; }

    Game_Engine game_engine(std::move(Console()), mode);
    game_engine.play();

    return 0;

}
