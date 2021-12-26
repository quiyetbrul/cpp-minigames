#ifndef GAMEGUESSNUMBER_H
#define GAMEGUESSNUMBER_H

#include "ClassPlayer.h"

class GuessNumber : public Player {
private:
  std::vector<int> guessHistory;
  int startRange;
  int endRange;
  int numberOfGuess;

public:
  GuessNumber();

  void Reset(std::vector<int> &guessHistory, int &numberOfGuess);

  int NumberOfGuess(int &numberOfGuess);

  void GuessMechanics(bool player, const int startRange, const int endRange,
                      const int guess, const int numberToGuess,
                      int &numberOfGuess);

  // game mechanics
  // Precondition:
  // Postcondition: game mechanics are run
  void GameMechanics();

  // game play
  // Precondition:
  // Postcondition: game play is run
  void GamePlay();
};

#endif // GAMEGUESSNUMBER_H
