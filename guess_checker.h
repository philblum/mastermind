
#pragma once

#include <string>
#include <vector>
#include "score.h"
#include "scorer.h"

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

