
#include <string>
#include "guess_checker.h"
#include "score.h"

namespace mastermind {
namespace strategy {

class Guesser 
{
public:
    static const std::string LETTERS;
    static const unsigned MAX_LETTERS;
    static const unsigned MAX_CODES;

    Guesser(Guess_Checker gc): guess_checker(gc) { }
    static std::string make_guess(int guess_index);
    std::string get_next_guess();
    void remember_score(const std::string& guess, const Score& score);
    void unit_test();

private:
    static std::string build_guess(int guess_index);
    Guess_Checker guess_checker;
    int guess_index = 0;

};

} }

