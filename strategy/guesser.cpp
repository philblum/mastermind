/* Copyright (C) 2019 Philip C. Blum.
 * This program is distributed under the terms of the GNU General Public
 * License version 3 or any later version.
 */
#include <algorithm>
#include <random>
#include "guesser.h"

using std::string;

namespace mastermind {
namespace strategy {

// helper functions for permutations
unsigned int factorial(const unsigned int n);
void permutation(int k, string &s);
std::string permute_letters(const std::string& s);

const std::string Guesser::LETTERS = "ABCDEF";
const std::string Guesser::PERMUTED_LETTERS = permute_letters(Guesser::LETTERS);
const unsigned Guesser::NUM_LETTERS = LETTERS.length();
const unsigned Guesser::NUM_CODES = NUM_LETTERS * NUM_LETTERS * NUM_LETTERS * NUM_LETTERS;
const unsigned Guesser::NUM_PEGS = 4;

std::string Guesser::get_random_code()
{ 
    return permute_letters(Guesser::LETTERS).substr(0, 4);
}
    
std::string Guesser::make_guess(int guess_index)
{
    if (guess_index < 0 || guess_index >= (NUM_CODES))
        return "";
    else
        return build_guess(guess_index);
}

std::string Guesser::make_permuted_guess(int guess_index)
{
    if (guess_index < 0 || guess_index >= (NUM_CODES))
        return "";
    else
        return build_permuted_guess(guess_index);
}

std::string Guesser::build_guess(int guess_index)
{
    static auto n = NUM_LETTERS;
    int d1 = guess_index % n;
    int d2 = (guess_index / n) % n;
    int d3 = (guess_index / (n * n)) % n;
    int d4 = (guess_index / (n * n * n) % n);

    return std::string() + LETTERS.at(d4) + LETTERS.at(d3) + LETTERS.at(d2) + LETTERS.at(d1);
}

std::string Guesser::build_permuted_guess(int guess_index)
{
    static auto n = NUM_LETTERS;
    int d1 = guess_index % n;
    int d2 = (guess_index / n) % n;
    int d3 = (guess_index / (n * n)) % n;
    int d4 = (guess_index / (n * n * n) % n);

    return std::string() + PERMUTED_LETTERS.at(d4) + PERMUTED_LETTERS.at(d3)
                         + PERMUTED_LETTERS.at(d2) + PERMUTED_LETTERS.at(d1);
}

std::string Guesser::get_next_guess()
{
    while(true)
    {
        std::string guess = make_permuted_guess(guess_index++);
        if (guess.empty())
          return "";
        else if (guess_checker.should_try(guess))
          return guess;
    }
}

void Guesser::remember_score(const std::string& guess, const Score& score)
{
    guess_checker.add_score_to_history(guess, score);
}

void Guesser::unit_test()
{
    assert(string("AAAA") == make_guess(0));
    assert(string("AAAB") == make_guess(1));
    assert(string("AAAF") == make_guess(NUM_LETTERS - 1));
    assert(string("BAAA") == make_guess(NUM_LETTERS*NUM_LETTERS*NUM_LETTERS));
    assert(string("FAAA") == make_guess(NUM_LETTERS*NUM_LETTERS*NUM_LETTERS*(NUM_LETTERS-1)));
    assert(string("FFFF") == make_guess(NUM_CODES - 1));
    assert(string("") == make_guess(NUM_CODES));
    assert(string("") == make_guess(-1));

    assert(std::is_permutation(LETTERS.begin(), LETTERS.end(),
                                     PERMUTED_LETTERS.begin()));
}

unsigned int factorial(const unsigned int n)
{
    unsigned int fact = 1;
    for(unsigned int k = 1; k <= n; k++)
      fact *= k;
    return fact;
}

void permutation(int k, string &s)
{
    for(int j = 1; j < s.size(); ++j)
    {
        std::swap(s[k % (j + 1)], s[j]);
        k = k / (j + 1);
    }
}

std::string permute_letters(const std::string& s)
{
    std::random_device rd;  // used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()

    // select kth permutation of input string
    int n_fact = factorial(s.length());
    std::uniform_int_distribution<> dis(0, n_fact);
    const int k = dis(gen);

    std::string p(s);
    permutation(k, p);
    return p;
}

} }

