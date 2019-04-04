
#include <string>
#include <iostream>
#include "console.h"

Score Console::score_guess(const std::string& guess)
{
    std::cout << "Enter score for " << guess << std::endl;
    std::string next_guess = read_line();
    return Score(count(next_guess, '+'), count(next_guess, '-'));
}

void Console::announce_game_over() const
{
    std::cout << "Game Over." << std::endl;
}

void Console::announce_winning_code(const std::string& code) const
{
    std::cout << "Winning code = " << code << std::endl;
}

void Console::announce_tries(const int tries) const
{
    std::cout << "tries = " << tries << std::endl;
}

void Console::announce_bad_scoring() const
{
    std::cout << "Sorry, but you're scoring was less than perfectly accurate." << std::endl;
}

std::string Console::read_line() const
{
    std::string line;
    std::getline(std::cin, line);
    return line;
}

int Console::count(std::string& s, char c)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == c)
            count++;
    return count;
}

