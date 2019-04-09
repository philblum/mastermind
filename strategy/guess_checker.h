/* Copyright (C) 2019 Philip C. Blum.
 * This program is distributed under the terms of the GNU General Public
 * License version 3 or any later version.
 */
#pragma once

#include <string>
#include <vector>
#include "score.h"
#include "scorer.h"

namespace mastermind {
namespace strategy {

class Guess_Checker
{
public:
    bool should_try(const std::string& guess) const
    {  return is_guess_consistent(guess); }

    void add_score_to_history(const std::string& guess, const Score& score)
    {
      score_history.push_back(Score_Record(guess, score));
    }

private:
    class Score_Record
    {
    public:
        Score_Record(const std::string& guess, const Score& score):
          guess(guess), score(score) { }
        std::string guess;
        Score score;
    };

    bool is_guess_consistent(const std::string& guess) const
    {
      for (auto previous: score_history)
        if ((score_guess(guess, previous.guess) == previous.score) == false)
          return false;
      return true;
    }

    std::vector<Score_Record> score_history;

};

} }

