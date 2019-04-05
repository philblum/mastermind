
#pragma once

#include "console.h"
#include "guess_checker.h"
#include "guesser.h"
#include "score.h"

namespace mastermind {
namespace gamePlay {

using namespace gameInterface;
using namespace strategy;

class Game_Engine
{
public:
    Game_Engine(Console con):
        console(con),
        guesser(std::move(Guess_Checker())),
        game_over(false),
        tries(0) { }
    void play();

private:
    void try_next_guess(const std::string& guess);
    void score_one_guess(const std::string& guess);
    bool is_perfect_match(Score& score) { return score.get_position() == 4; }
    void win(const std::string& guess);
    void code_not_found();

    Console console;
    Guesser guesser;
    bool game_over;
    int tries;
};

} }
