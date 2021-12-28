#ifndef CLASSPLAYER_H
#define CLASSPLAYER_H

#include "GameObject.h"
#include "GameWelcome.h"
#include "InputValidation.h"

class Player : public GameObject {
protected:
  std::string playerName;
  int playerChoice;
  int playerScore;
  bool isWinner;

public:
  // default constructor
  // Precondition:
  // Postcondition: initializes data members
  Player();

  // parameterized constructor
  // Precondition:
  // Postcondition: initializes data members
  Player(std::string playerName, int playerChoice, int playerScore,
         bool isWinner);

  // reset player object
  // Precondition: keepScore is true if player score should not be reset
  // Postcondition: resets data members
  void reset(bool keepScore);
  
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

  // setIsWinner
  // Precondition: isWinner is a boolean
  // Postcondition: sets the isWinner data member
  void setIsWinner(bool isWinner);

  // getIsWinner
  // Precondition:
  // Postcondition: returns the isWinner data member
  bool getIsWinner();

  // playerPrompt
  // Precondition: prompt is a valid string, startRange and endRange are
  // integers Postcondition: prompts the user for their choice
  // Postcondition: returns the playerChoice data member
  int playerPrompt(std::string prompt, int startRange, int endRange);

  // showChoice
  // Precondition:
  // Postcondition: displays the player's choice
  void showChoice();

  // addScore
  // Precondition:
  // Postcondition: adds a point to the player's score
  void addScore();

  // showResult
  // Precondition: 
  // Postcondition: displays the result of the game
  void showWinner();

  // showScore
  // Precondition:
  // Postcondition: displays the player's score
  void showScore();

  // generateComputerChoice
  // Precondition: endRange is an integer
  // Postcondition: generates a random number between ranges
  int randomNumber(int startRange, int endRange);

  // intBinarySearch
  // Precondition: startRange, endRange, and target are integers
  // Postcondition: returns target if it is found in the array
  int intBinarySearch(int startRange, int endRange, int target);
};

#endif // CLASSPLAYER_H
