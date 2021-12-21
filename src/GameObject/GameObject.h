#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../InputValidation/InputValidation.h"

class GameObject
{
private:
  int playerChoice;
  int computerChoice;
  int playerScore;
  int computerScore;

public:
  // default constructor
  // Precondition:
  // Postcondition: initializes data members
  GameObject();

  // parameterized constructor
  // Precondition:
  // Postcondition: initializes data members
  GameObject(int playerChoice, int computerChoice, int playerScore, int computerScore);

  // setPlayerChoice
  // Precondition: playerChoice is an integer
  // Postcondition: sets the playerChoice data member
  void setPlayerChoice(int playerChoice);
  // setComputerChoice
  // Precondition: computerChoice is an integer
  // Postcondition: sets the computerChoice data member
  void setComputerChoice(int computerChoice);

  // getPlayerChoice
  // Precondition:
  // Postcondition: returns the playerChoice data member
  int getPlayerChoice();
  // getComputerChoice
  // Precondition:
  // Postcondition: returns the computerChoice data member
  int getComputerChoice();

  // setPlayerScore
  // Precondition: playerScore is an integer
  // Postcondition: sets the playerScore data member
  void setPlayerScore(int playerScore);
  // setComputerScore
  // Precondition: computerScore is an integer
  // Postcondition: sets the computerScore data member
  void setComputerScore(int computerScore);

  // getPlayerScore
  // Precondition:
  // Postcondition: returns the playerScore data member
  int getPlayerScore();
  // getComputerScore
  // Precondition:
  // Postcondition: returns the computerScore data member
  int getComputerScore();

  // playerPrompt
  // Precondition: endRange is an integer
  // Postcondition: prompts the user for their choice
  void playerPrompt(int endRange);

  // generateComputerChoice
  // Precondition: endRange is an integer
  // Postcondition: generates a random number between 1 to x
  int generateComputerChoice(int endRange);

  // showResult
  // Precondition: playerWins is a boolean
  // Postcondition: displays the result of the game
  void showResult(bool playerWins);
};

#endif // GAMEOBJECT_H
