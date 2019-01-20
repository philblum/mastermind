
#pragma once

#include <string>
#include <vector>
#include "score.h"
#include "scorer.h"

class Guess_History
{
public:
    bool should_try(std::string& guess) { return is_guess_consistent(guess); }
    void add_score_to_history(std::string& guess, Score& score)
    {
      score_history.push_back(Score_Record(guess, score));
    }

private:
    class Score_Record
    {
    public:
        Score_Record(std::string& guess, Score& score):
          guess(guess), score(score) { }
        std::string guess;
        Score score;
    };

    std::vector<Score_Record> score_history;

    bool is_guess_consistent(std::string& guess)
    {
      for (auto previous: score_history)
        if ((score_guess(guess, previous.guess) == previous.score) == false)
          return false;
      return true;
    }
};

