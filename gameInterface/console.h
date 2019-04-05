
#pragma once

#include <string>
#include "score.h"

namespace mastermind {
namespace gameInterface {

using namespace gamePlay;

class Console
{
public:
    Score score_guess(const std::string& guess);
    void announce_game_over() const;
    void announce_winning_code(const std::string& code) const;
    void announce_tries(const int tries) const;
    void announce_bad_scoring() const;

private:
    std::string read_line() const;
    int count(std::string& s, char c);
};

}}

