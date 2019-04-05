
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

void Game_Engine::play()
{
    for(tries=1; !game_over; tries++)
      try_next_guess(guesser.get_next_guess());
}

void Game_Engine::score_one_guess(const std::string& guess)
{
    Score score = console.score_guess(guess);
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

