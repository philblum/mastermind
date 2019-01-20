
#pragma once

#include <iostream>

class Score 
{
public:
    Score() = default;
    Score(const int position, const int code):
        in_position(position), in_code(code) { }
    int get_position() { return in_position; }
    int get_code() { return in_code; }

    friend bool operator==(const Score& lhs, const Score& rhs)
            { return lhs.in_position == rhs.in_position &&
              lhs.in_code == rhs.in_code; }
    friend bool operator!=(const Score& lhs, const Score& rhs)
            { return !(lhs == rhs); }
    friend std::ostream& operator<<(std::ostream& os, const Score& score)
    { os << score.in_position << " " << score.in_code;
      return os; }

private:
    int in_position;
    int in_code;
};


