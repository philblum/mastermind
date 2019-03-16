
#pragma once

#include "console.h"
#include "guess_checker.h"
#include "guesser.h"
#include "score.h"

class Game_Engine
{
public:
    //static Guess_Checker guess_checker;
    //Guesser(Guess_Checker gc): guess_checker(gc) { }
    Game_Engine(Console con):
        console(con),
        guesser(std::move(Guess_Checker())),
        game_over(false),
        tries(0) { }
    void play();
    Console console;

private:
    void try_next_guess(std::string guess);
    void score_one_guess(const std::string& guess);
    bool is_perfect_match(Score score) { return score.get_position() == 4; }
    void win(const std::string& guess);
    void code_not_found();

    Guesser guesser;
    bool game_over;
    int tries;
};

