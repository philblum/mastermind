/* Copyright (C) 2019 Philip C. Blum.
 * This program is distributed under the terms of the GNU General Public
 * License version 3 or any later version.
 */
#pragma once

#include <string>
#include "score.h"

namespace mastermind {
namespace gameInterface {

using namespace gamePlay;

class Console
{
public:
    std::string get_next_guess() const;
    Score score_guess(const std::string& guess) const;
    void announce_game_over() const;
    void announce_winning_code(const std::string& code) const;
    void announce_tries(const int tries) const;
    void announce_bad_scoring() const;
    void announce_new_code() const;
    void announce_score(const Score& score) const;
    void announce_guess_already_tried() const;

private:
    std::string read_line() const;
    int count(const std::string& s, const char c) const;
};

}}

