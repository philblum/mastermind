
# C++ MasterMind

Simple, text-based implementation of the game of MasterMind. In this
version the computer guesses the player's secret code. Later versions
will have the user guessing the computer's secret, showing possible
responses, finding patterns in guesses and responses, etc.

Enjoy!

### Compile

The code is compiled with g++ version 5.4.0 following the C++11 standard.

```sh
$ g++ -std=c++11 -O3 sudoku.cpp main.cpp -o sudoku
$ g++ -std=c++11 -O3 -IgameInterface -IgamePlay -Istrategy gameInterface/console.cpp gamePlay/game_engine.cpp strategy/guesser.cpp strategy/scorer.cpp mmind.cpp -o mmind
```

### Run

Below is a sample run.

```sh
$ ./mmind
MasterMind version 1.0
All tests pass
Enter score for AAAA
+
Enter score for ABBB
-+
Enter score for CABC
+--
Enter score for CBAD
----
Enter score for DACB
+---
Enter score for DCBA
++++
Game Over.
Winning code = DCBA
tries = 6
```

### Improve

Reducing the number of guesses

The basic algorithm uses a counter to represent the guesses. In the standard
game with four positions and six colors, the counter has 4 digits in base 6
(taking on the values 0, 1, 2, 3, 4, 5) and a static assignment of colors to
values. The initial guess is 0000. Responses are added to the history and
the counter increments until a guess compatible with the history is found.
If the counter wraps, then the opponent has made an error in scoring.

The second improvement on the basic algorithm is prevent the opponent from
discovering the basic strategy. This is done in one or both of two ways:
permuting the peg order and permuting the colors/letters.

### Reference

Wolfram, below, has a brief description of the game and a summary of 
codebreaking strategies and a nice list of references.

http://mathworld.wolfram.com/Mastermind.html

