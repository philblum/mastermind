/* Copyright (C) 2019 Philip C. Blum.
 * This program is distributed under the terms of the GNU General Public
 * License version 3 or any later version.
 */
#include <string>
#include <iostream>
#include "console.h"
#include "guesser.h"

namespace mastermind {
namespace gameInterface {

using namespace gamePlay;
using namespace strategy;

// read codebreaker's guess from console
std::string Console::get_next_guess() const
{
    std::string next_guess = read_line();
    return next_guess;
}

Score Console::score_guess(const std::string& guess) const
{
    std::cout << "Enter score for " << guess << std::endl;
    std::string response = read_line();
    return Score(count(response, '+'), count(response, '-'));
}

void Console::announce_game_over() const
{
    std::cout << "Game Over." << std::endl;
}

void Console::announce_winning_code(const std::string& code) const
{
    std::cout << "Winning code: " << code << std::endl;
}

void Console::announce_tries(const int tries) const
{
    std::cout << "tries: " << tries << std::endl;
}

void Console::announce_bad_scoring() const
{
    std::cout << "Sorry, but you're scoring was less than perfectly accurate." << std::endl;
}

void Console::announce_new_code() const
{
    std::cout << "Guess " << Guesser::NUM_PEGS << " letter code selected from pattern \'ABCDEF\'" << std::endl;
}

void Console::announce_score(const Score& score) const
{
    std::cout << score << std::endl;
}

void Console:: announce_guess_already_tried() const
{
    std::cout << "Guess already tried" << std::endl;
}

std::string Console::read_line() const
{
    std::string line;
    std::getline(std::cin, line);
    return line;
}

int Console::count(const std::string& s, const char c) const
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == c)
            count++;
    return count;
}

} }

