#ifndef CLASSPLAYER_H
#define CLASSPLAYER_H

#include "GameObject.h"
#include "InputValidation.h"

class Player : public GameObject {
private:
  std::string playerName;
  int playerChoice;
  int playerScore;

public:
  // default constructor
  // Precondition:
  // Postcondition: initializes data members
  Player();

  // parameterized constructor
  // Precondition:
  // Postcondition: initializes data members
  Player(int playerChoice, int playerScore);

  // setPlayerChoice
  // Precondition: playerName is a valid string
  // Postcondition: sets the playerName data member
  void setPlayerName(std::string playerName);

  // getPlayerChoice
  // Precondition:
  // Postcondition: returns the playerName data member
  std::string getPlayerName();

  // setPlayerChoice
  // Precondition: playerChoice is an integer
  // Postcondition: sets the playerChoice data member
  void setPlayerChoice(int playerChoice);

  // getPlayerChoice
  // Precondition:
  // Postcondition: returns the playerChoice data member
  int getPlayerChoice();

  // setPlayerScore
  // Precondition: playerScore is an integer
  // Postcondition: sets the playerScore data member
  void setPlayerScore(int playerScore);

  // getPlayerScore
  // Precondition:
  // Postcondition: returns the playerScore data member
  int getPlayerScore();

  // playerPrompt
  // Precondition: prompt is a valid string, startRange and endRange are integers
  // Postcondition: prompts the user for their choice
  int playerPrompt(std::string prompt, int startRange, int endRange);

  // generateComputerChoice
  // Precondition: endRange is an integer
  // Postcondition: generates a random number between 1 to x
  int generateComputerChoice(int startRange, int endRange);

  // showChoice
  // Precondition:
  // Postcondition: displays the player's choice
  void showChoice();

  // addScore
  // Precondition:
  // Postcondition: adds a point to the player's score
  void addScore();

  // showResult
  // Precondition: playerWins is a boolean, hasScore determines if the game
  // has scoring functionality Postcondition: displays the result of the
  // game
  void showWinner(bool isWinner);

  // showScore
  // Precondition:
  // Postcondition: displays the player's score
  void showScore();
};

#endif // CLASSPLAYER_H
