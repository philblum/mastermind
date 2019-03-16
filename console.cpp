
#include <string>
#include <iostream>
#include "console.h"

Score Console::score_guess(const std::string& guess)
{
      std::cout << "Enter score for " << guess << std::endl;
      std::string next_guess = read_line();
      return Score(count(next_guess, '+'), count(next_guess, '-'));
}

void Console::announce_game_over()
{
      std::cout << "Game Over." << std::endl;
}

void Console::announce_winning_code(const std::string& code)
{
      std::cout << "Winning code = " << code << std::endl;
}

void Console::announce_tries(const int tries)
{
    std::cout << "tries = " << tries << std::endl;
}

void Console::announce_bad_scoring()
{
    std::cout << "Sorry, but you're scoring was less than perfectly accurate." << std::endl;
}

std::string Console::read_line()
{
    std::string line;
    std::getline(std::cin, line);
    return line;
}

int Console::count(std::string& s, char c)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
        if (s.at(i) == c)
            count++;
    return count;
}

