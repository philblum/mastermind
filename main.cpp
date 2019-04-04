
#include <iostream>
#include "console.h"
#include "game_engine.h"

using namespace std;

void unit_test()
{
    Scorer scorer;
    scorer.unit_test();

    Guesser guesser(std::move(Guess_Checker()));
    guesser.unit_test();

    std::cout << "All tests pass" << std::endl;
}


int main()
{
    std::cout << "MasterMind version 1.0\n";
    unit_test();

    Game_Engine game_engine(std::move(Console()));
    game_engine.play();

}
