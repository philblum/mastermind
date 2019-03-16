
#pragma once
#include <string>
#include "score.h"

class Console
{
public:
    Score score_guess(const std::string& guess);
    void announce_game_over();
    void announce_winning_code(const std::string& code);
    void announce_tries(const int tries);
    void announce_bad_scoring();

private:
    std::string read_line();
    int count(std::string& s, char c);
};

