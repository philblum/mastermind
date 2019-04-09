/* Copyright (C) 2019 Philip C. Blum.
 * This program is distributed under the terms of the GNU General Public
 * License version 3 or any later version.
 */
#include "scorer.h"

using namespace std;

namespace mastermind {
namespace strategy {

bool Scorer::is_in_position(int i)
{
  if (code[i] == guess[i])
    return code_position_used[i] = guess_position_used[i] = true;
  else
    return false;
}

int Scorer::count_letters_in_position()
{
  int in_position = 0;
  for (int i = 0; i < code.size(); i++)
    if (is_in_position(i))
      in_position++;
  return in_position;
}

bool Scorer::is_out_of_position(int ic)
{
  for (int ig = 0; ig < guess.size(); ig++)
    if (!code_position_used[ic] && !guess_position_used[ig] &&
            (ig != ic) && (guess[ig] == code[ic]))
      return code_position_used[ic] = guess_position_used[ig] = true;
  return false;
}

int Scorer::count_letters_out_of_position()
{
  int out_of_position = 0;
  for (int ic = 0; ic < code.size(); ic++)
    if (is_out_of_position(ic))
      out_of_position++;
  return out_of_position;
}

void Scorer::unit_test_in_position()
{
    assert_in_position(0, string("ABCD"), string("DCBA"));
    assert_in_position(1, string("ABBB"), string("ACCC"));
    assert_in_position(2, string("AABB"), string("AACC"));
    assert_in_position(2, string("ABAB"), string("ACAC"));
    assert_in_position(3, string("DEEE"), string("AEEE"));
    assert_in_position(3, string("BABB"), string("BCBB"));
    assert_in_position(4, string("AAAA"), string("AAAA"));
    assert_in_position(1, string("ABBB"), string("AAAA"));
}

void Scorer::unit_test_not_in_position()
{
    assert_not_in_position(0, string("AAAA"), string("BBBB"));
    assert_not_in_position(0, string("ABBB"), string("ACCC"));
    assert_not_in_position(1, string("ABBB"), string("CACC"));
    assert_not_in_position(4, string("ABCD"), string("DCBA"));
    assert_not_in_position(2, string("ABBA"), string("CAAC"));
    assert_not_in_position(3, string("ABCD"), string("CADF"));
    assert_not_in_position(0, string("ABBB"), string("AAAA"));
    assert_not_in_position(1, string("ABBB"), string("CAAA"));
    assert_not_in_position(1, string("AABB"), string("CCAC"));
}

void Scorer::assert_in_position(int in_position,
        const std::string& code, const std::string& guess)
{
    assert(in_position == score_guess(code, guess).get_position());
}

void Scorer::assert_not_in_position(int in_position,
        const std::string& code, const std::string& guess)
{
    assert(in_position == score_guess(code, guess).get_code());
}

Score score_guess(const std::string& code, const std::string& guess)
{ 
    return Scorer(code, guess).score_it();
}

} }

