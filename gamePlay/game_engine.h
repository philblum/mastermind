/* Copyright (C) 2019 Philip C. Blum.
 * This program is distributed under the terms of the GNU General Public
 * License version 3 or any later version.
 */
#pragma once

#include <functional>
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
    Game_Engine(Console con, unsigned mode):
        console(con),
        mode(mode),
        guesser(std::move(Guess_Checker())),
        game_over(false),
        tries(0)
        { //play = (mode == 0) ? play1 : play2;
          //if(mode == 0) play = play1;
          //else play = play2;
        }
    void play(), play1(), play2();

private:

    void try_next_guess(const std::string& guess);
    void score_one_guess(const std::string& guess);
    bool is_perfect_match(Score& score) { return score.get_position() == 4; }
    void win(const std::string& guess);
    void code_not_found();
    Console console;
    Guesser guesser;
    std::string code;
    bool game_over;
    int tries;
    unsigned mode;
};

} }
