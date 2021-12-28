#ifndef GAMEGUESSNUMBER_H
#define GAMEGUESSNUMBER_H

#include "ClassPlayer.h"

class GuessNumber : public Player {
private:
  std::vector<int> guessHistory;
  int player;
  int startRange;
  int endRange;
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

  // NumberOfGuess
  // Precondition: numberOfGuess is an integer
  // Postcondition: returns the numberOfGuess data member
  int NumberOfGuess(int &numberOfGuess);

  // PrintGuessHistory
  // Precondition: guessHistory is a vector of integers
  // Postcondition: returns the guessHistory data member
  void GuessHistory(std::string currentGuesser, std::vector<int> &guessHistory,
                    int guess);

  // GuessRange
  // Precondition: guessHistory is a vector of integers
  // Postcondition: prints the guessHistory data member
  void PrintGuessHistory(const std::vector<int> &guessHistory);

  // GuessRange
  // Precondition: currentGuesser is a string; startRange, endRange, guess,
  // numberToGuess, and numberOfGuess are integers
  //Postcondition: checks if guess is in the range of startRange and endRange
  void GuessRange(std::string currentGuesser, int startRange, int endRange,
                  int guess, int numberToGuess, int &numberOfGuess);

  // GameMechanics
  // Precondition: player is boolean, startRange, endRange, guess,
  // numberToGuess, and numberOfGuess are integers
  // Postcondition: returns player's guess
  void GuessMechanics(bool player, const int startRange, const int endRange,
                      const int guess, const int numberToGuess,
                      int &numberOfGuess);

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
