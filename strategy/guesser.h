/* Copyright (C) 2019 Philip C. Blum.
 * This program is distributed under the terms of the GNU General Public
 * License version 3 or any later version.
 */
#include <string>
#include "guess_checker.h"
#include "score.h"

namespace mastermind {
namespace strategy {

class Guesser 
{
public:
    static const std::string LETTERS;
    static const std::string PERMUTED_LETTERS;
    static const unsigned MAX_LETTERS;
    static const unsigned MAX_CODES;

    Guesser(Guess_Checker gc): guess_checker(gc) { }
    static std::string get_random_code();
    static std::string make_guess(int guess_index);
    static std::string make_permuted_guess(int guess_index);
    std::string get_next_guess();
    void remember_score(const std::string& guess, const Score& score);
    void unit_test();

private:
    static std::string build_guess(int guess_index);
    static std::string build_permuted_guess(int guess_index);
    Guess_Checker guess_checker;
    int guess_index = 0;

};

} }

