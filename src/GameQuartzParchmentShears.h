#ifndef QUARTZPARCHMENTSHEARSGAMEPLAY_H
#define QUARTZPARCHMENTSHEARSGAMEPLAY_H

#include "ClassPlayer.h"

class QuartzParchmentShears : public Player {
private:
public:
  // default constructor
  QuartzParchmentShears();

  // game mechanics
  // Precondition:
  // Postcondition: game mechanics are run
  void GameMechanics();

  // game play
  // Precondition:
  // Postcondition: game play is run
  void GamePlay();
};

#endif // QUARTZPARCHMENTSHEARSGAMEPLAY_H
