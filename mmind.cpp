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

void print_version_notice() { std::cout << "MasterMind version 1.5" << std::endl; }

void print_copyright_notice()
{
    std::cout << "mmind  Copyright (C) 2019 Philip C. Blum" << std::endl;
    std::cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'." << std::endl;
    std::cout << "This is free software, and you are welcome to redistribute it" << std::endl;
    std::cout << "under certain conditions; type `show c' for details." << std::endl;
}

int main()
{
    print_version_notice();
    print_copyright_notice();

    unit_test();

    Game_Engine game_engine(std::move(Console()), 1);
    game_engine.play();

}
