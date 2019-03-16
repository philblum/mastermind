
#include <iostream>
#include "console.h"
#include "game_engine.h"

using namespace std;
#if 0
void unit_test()
{
    Scorer scorer;
    scorer.unit_test();

    //Guess_Checker gc;
    Guesser(Guess_Checker gc): guess_checker(gc) { }
    Guesser guesser(std::move(Guess_Checker()));
    guesser.unit_test();
    std::cout << "All tests pass" << std::endl;
}
#endif

int main()
{
    std::cout << "MasterMind version 0.1\n";
    //unit_test();

    //Game_Engine game_engine(std::move(Console()));
    Console console;
    Game_Engine game_engine(console);
    //game_engine.guess_checker = new RememberingGuessChecker();
    //game_engine.console(std::move(Console()));
    game_engine.play();
#if 0
    Guess_Checker gc;
    gc.add_score_to_history(string("ABCD"), Score(0, 0));
    std::cout << gc.should_try(string("ABCD")) << ", " << gc.should_try(string("BCDE")) << std::endl;
#endif

}
