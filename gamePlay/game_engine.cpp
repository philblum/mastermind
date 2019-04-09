/* Copyright (C) 2019 Philip C. Blum.
 * This program is distributed under the terms of the GNU General Public
 * License version 3 or any later version.
 */
#include <string>
#include "game_engine.h"

namespace mastermind {
namespace gamePlay {

void Game_Engine::try_next_guess(const std::string& guess)
{
    if (guess.empty())
      code_not_found();
    else
      score_one_guess(guess);
}

void Game_Engine::play2()
{
    console.announce_new_code();
    code = guesser.get_random_code();
    for(tries=1; !game_over; tries++)
    { 
      std::string guess = console.get_next_guess();
      Score score = Scorer(code, guess).score_it();
      console.announce_score(score);
      if (is_perfect_match(score)) {
        win(guess);
      } else {
        guesser.remember_score(guess, score);
#if 0
        if(!guesser.should_try(guess))
          console.announce_guess_already_tried();
        else
          guesser.remember_score(guess, score);
#endif
      }
      //score_next_guess(next_guess);
      //try_next_guess(console.get_next_guess());
    }
}

void Game_Engine::play1()
{
    for(tries=1; !game_over; tries++)
    {
      std::string next_guess = guesser.get_next_guess();
      try_next_guess(guesser.get_next_guess());
    }
}

void Game_Engine::play()
{
    if(mode == 0) play1();
    else play2();
}

void Game_Engine::score_one_guess(const std::string& guess)
{
    Score score = console.score_guess(guess);
    std::cout << score << std::endl;
    if (is_perfect_match(score)) {
      win(guess);
    } else {
      guesser.remember_score(guess, score);
    }
}

void Game_Engine::win(const std::string& guess)
{
    console.announce_game_over();
    console.announce_winning_code(guess);
    console.announce_tries(tries);
    game_over = true;
}

void Game_Engine::code_not_found()
{
    console.announce_game_over();
    console.announce_tries(tries - 1);
    console.announce_bad_scoring();
    game_over = true;
}

} }

