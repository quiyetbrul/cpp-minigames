#ifndef QUARTZPARCHMENTSHEARSGAMEPLAY_H
#define QUARTZPARCHMENTSHEARSGAMEPLAY_H

#include "ClassPlayer.h"

class QuartzParchmentShears : public Player {
private:
public:
  // default constructor
  // Precondition:
  // Postcondition: initializes data members
  QuartzParchmentShears();

  // Reset
  // Precondition:
  // Postcondition: initializes data members
  void Reset();

  // DetermineWinner
  // Precondition:
  // Postcondition: returns the winner
  void DetermineWinner();

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
