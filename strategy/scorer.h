/* Copyright (C) 2019 Philip C. Blum.
 * This program is distributed under the terms of the GNU General Public
 * License version 3 or any later version.
 */
#pragma once

// uncomment to disable assert()
//#define NDEBUG
#include <cassert>
#include <string>
#include <vector>
#include "score.h"

namespace mastermind {
namespace strategy {

using namespace gamePlay;

class Scorer
{
public:
  constexpr static int POSITIONS = 4;

  Scorer() = default;
  Scorer(const std::string& code, const std::string& guess):
    code(code), 
    guess(guess), 
    code_position_used(POSITIONS, false),
    guess_position_used(POSITIONS, false) { }
  
  Score score_it() { int ca = count_letters_in_position();
                     int cb = count_letters_out_of_position();
                     return Score(ca, cb); }
  void unit_test() { unit_test_in_position(); 
                     unit_test_not_in_position(); }

private:
  int count_letters_in_position();
  int count_letters_out_of_position();
  bool is_in_position(int i);
  bool is_out_of_position(int i);

  void assert_in_position(int in_position,
          const std::string& code, const std::string& guess);
  void assert_not_in_position(int in_position,
          const std::string& code, const std::string& guess);
  void unit_test_in_position();
  void unit_test_not_in_position();

  std::vector<bool> code_position_used;
  std::vector<bool> guess_position_used;
  std::string code;
  std::string guess;
};

Score score_guess(const std::string& code, const std::string& guess);

} }


