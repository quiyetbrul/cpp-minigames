#ifndef GAMEHANGMAN_H
#define GAMEHANGMAN_H

#include "ClassPlayer.h"

class Hangman : public Player {
private:
public:
  ~Hangman();
  
  Hangman();
  // GameMechanics
  // Precondition:
  // Postcondition: game mechanics are run
  void GameMechanics();

  // GamePlay
  // Precondition:
  // Postcondition: game play is run
  void GamePlay();
};

#endif // GAMEHANGMAN_H
