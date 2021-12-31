#ifndef QUARTZPARCHMENTSHEARSGAMEPLAY_H
#define QUARTZPARCHMENTSHEARSGAMEPLAY_H

#include "ClassPlayer.h"

class QuartzParchmentShears : public Player {
private:
  int rockRating;
  int paperRating;
  int scissorsRating;
  int startRange;
  int endRange;

public:
  // destructor
  // Precondition:
  // Postcondition:
  ~QuartzParchmentShears();

  // default constructor
  // Precondition:
  // Postcondition: initializes data members
  QuartzParchmentShears();

  // showChoice
  // Precondition: player is an integer
  // Postcondition: displays the player's choice
  void ShowChoice(int player);

  // CalculateComputerChoice
  // Precondition:
  // Postcondition: returns an integer based on frequency of player choices
  int CalculateComputerChoice();

  // Reset
  // Precondition:
  // Postcondition: initializes data members
  void Reset(bool keepScore);

  // DetermineWinner
  // Precondition:
  // Postcondition: determines the winner
  void DetermineWinner();

  // WinnerMechanics
  // Precondition: player is an integer
  // Postcondition: handles the winner's mechanics
  void WinnerMechanics(int player);

  // GameMechanics
  // Precondition:
  // Postcondition: game mechanics are run
  void GameMechanics();

  // GamePlay
  // Precondition:
  // Postcondition: game play is run
  void GamePlay();
};

#endif // QUARTZPARCHMENTSHEARSGAMEPLAY_H
