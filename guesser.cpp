
#include "guesser.h"

using std::string;

const std::string Guesser::LETTERS = "ABCDEF";
const unsigned Guesser::MAX_LETTERS = LETTERS.length();
const unsigned Guesser::MAX_CODES = MAX_LETTERS * MAX_LETTERS * MAX_LETTERS * MAX_LETTERS;

std::string Guesser::make_guess(int guess_index)
{
    if (guess_index < 0 || guess_index >= (MAX_CODES))
        return "";
    else
        return build_guess(guess_index);
}

std::string Guesser::build_guess(int guess_index)
{
    static auto n = MAX_LETTERS;
    int d1 = guess_index % n;
    int d2 = (guess_index / n) % n;
    int d3 = (guess_index / (n * n)) % n;
    int d4 = (guess_index / (n * n * n) % n);

    return std::string() + LETTERS.at(d4) + LETTERS.at(d3) + LETTERS.at(d2) + LETTERS.at(d1);
}

std::string Guesser::get_next_guess()
{
    while(true)
    {
        std::string guess = make_guess(guess_index++);
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
    assert(string("AAAF") == make_guess(MAX_LETTERS - 1));
    assert(string("BAAA") == make_guess(MAX_LETTERS*MAX_LETTERS*MAX_LETTERS));
    assert(string("FAAA") == make_guess(MAX_LETTERS*MAX_LETTERS*MAX_LETTERS*(MAX_LETTERS-1)));
    assert(string("FFFF") == make_guess(MAX_CODES - 1));
    assert(string("") == make_guess(MAX_CODES));
    assert(string("") == make_guess(-1));

    Guesser guesser(std::move(Guess_Checker()));
    assert(string("AAAA") == guesser.get_next_guess());
}
