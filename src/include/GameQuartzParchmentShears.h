#ifndef QUARTZPARCHMENTSHEARSGAMEPLAY_H
#define QUARTZPARCHMENTSHEARSGAMEPLAY_H

#include "ClassPlayer.h"

class QuartzParchmentShears : public Player {
private:
  std::vector<int> choiceHistoryPlayer;
  std::vector<int> choiceHistoryComputer;
  std::vector<int> winHistoryPlayer;
  std::vector<int> winHistoryComputer;
  int rockWeight;
  int paperWeight;
  int scissorsWeight;
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

  // Reset
  // Precondition:
  // Postcondition: initializes data members
  void Reset(bool keepScore);

  // ResetWeights
  // Precondition:
  // Postcondition: initializes weights data members
  void ResetWeights();

  // WinHistory
  // Precondition:
  // Postcondition: adds player and computer wins to history
  void WinHistory();

  // PrintChoiceHistory
  // Precondition:
  // Postcondition: prints history of player and computer wins/losses
  void PrintWinHistory();

  // ChoiceHistory
  // Precondition:
  // Postcondition: adds player and computer choice to history
  void ChoiceHistory();

  // PrintChoiceHistory
  // Precondition:
  // Postcondition: prints history of player and computer choices
  void PrintChoiceHistory();

  // showChoice
  // Precondition: player is an integer
  // Postcondition: displays the player's choice
  void ShowChoice(Player &player);

  // ShowWeights
  // Precondition:
  // Postcondition: displays the weights of the player's choices
  void ShowWeights();

  // GetStats
  // Precondition: player is a class Player object
  // Postcondition: player's stats are calculated
  double CalculateStats(Player &player);

  // ShowStats
  // Precondition: player is a class Player object
  // Postcondition: player's stats are displayed
  void ShowStats(Player &player);

  // CalculateComputerChoice
  // Precondition:
  // Postcondition: returns an integer based on frequency of player choices
  int CalculateComputerChoice();

  // WinnerMechanics
  // Precondition: player is an integer
  // Postcondition: handles the winner's mechanics
  void WinnerMechanics(bool player);

  // DetermineWinner
  // Precondition:
  // Postcondition: determines the winner
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
