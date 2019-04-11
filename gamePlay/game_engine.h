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

/* #define CALL_MEMBER_FUNC(object, ptrToMember)  ((object).*(ptrToMember)) */
/* #define CALL_MEMBER_FUNC(ptrToMember) (this->*(ptrToMember)) */

class Game_Engine
{
    typedef void (Game_Engine::*GameEngineFunc)(void);

public:
    Game_Engine(Console con, unsigned mode):
        console(con),
        mode(mode),
        guesser(std::move(Guess_Checker())),
        game_over(false),
        tries(0)
        { fp = (mode == 1 ? &Game_Engine::play_mode1 : &Game_Engine::play_mode2); }
    void play() { (this->*fp)(); }
    void play_mode1(), play_mode2();

private:
    void try_next_guess(const std::string& guess);
    void score_one_guess(const std::string& guess);
    bool is_perfect_match(Score& score) { return score.get_position() == 4; }
    void win(const std::string& guess);
    void code_not_found();
    GameEngineFunc fp;
    Console console;
    Guesser guesser;
    std::string code;
    bool game_over;
    int tries;
    unsigned mode;
};

} }
