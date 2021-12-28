#ifndef GAMEGUESSNUMBER_H
#define GAMEGUESSNUMBER_H

#include "ClassPlayer.h"

class GuessNumber : public Player {
private:
  std::string playerName;
  std::vector<int> guessHistory;
  int player;
  int startRange;
  int endRange;
  int playerGuess;
  int numberToGuess;
  int numberOfGuess;

public:
  // default constructor
  // Precondition:
  // Postcondition: initializes data members
  GuessNumber();

  // Reset
  // Precondition:
  // Postcondition: initializes data members
  void Reset();

  // setNumberOfGuess
  // Precondition: numberOfGuess is an integer
  // Postcondition: sets the numberOfGuess data member
  void setNumberOfGuess(int numberToGuess);

  // getNumberOfGuess
  // Precondition:
  // Postcondition: returns the numberOfGuess data member
  int getNumberOfGuess();

  // PrintGuessHistory
  // Precondition:
  // Postcondition: returns the guessHistory data member
  void GuessHistory();

  // GuessRange
  // Precondition:
  // Postcondition: prints the guessHistory data member
  void PrintGuessHistory();

  // GuessRange
  // Precondition:
  // Postcondition: checks if guess per given range
  void GuessRange();

  // GameMechanics
  // Precondition:
  // Postcondition: returns player's guess
  void GuessMechanics();

  // GameMechanics
  // Precondition:
  // Postcondition: game mechanics are run
  void GameMechanics();

  // GamePlay
  // Precondition:
  // Postcondition: game play is run
  void GamePlay();
};

#endif // GAMEGUESSNUMBER_H
