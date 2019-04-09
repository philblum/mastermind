/* Copyright (C) 2019 Philip C. Blum.
 * This program is distributed under the terms of the GNU General Public
 * License version 3 or any later version.
 */
#pragma once

#include <iostream>

namespace mastermind {
namespace gamePlay {

class Score 
{
public:
    Score() = default;
    Score(const int position, const int code):
        in_position(position), in_code(code) { }
    int get_position() const { return in_position; }
    int get_code() const { return in_code; }

    friend bool operator==(const Score& lhs, const Score& rhs)
            { return lhs.in_position == rhs.in_position &&
              lhs.in_code == rhs.in_code; }
    friend bool operator!=(const Score& lhs, const Score& rhs)
            { return !(lhs == rhs); }
    friend std::ostream& operator<<(std::ostream& os, const Score& score)
            { 
              //os << score.in_position << ", " << score.in_code;
              std::string s = {};
              for(int i = 0; i < score.get_position(); i++) s += '+';
              for(int i = 0; i < score.get_code(); i++) s += '-';
              if(s.empty()) s = "none";
              os << s;
              return os;
            }

private:
    int in_position;
    int in_code;
};

} }

