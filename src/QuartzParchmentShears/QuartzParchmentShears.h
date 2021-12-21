#ifndef QUARTZPARCHMENTSHEARS_H
#define QUARTZPARCHMENTSHEARS_H

class QuartzParchmentShears
{
private:
  int playerChoice;
  int computerChoice;
  bool playerWins;
  int playerScore;
  int computerScore;

public:
  // default constructor
  // Precondition:
  // Postcondition: initializes data members
  QuartzParchmentShears();

  // parameterized constructor
  // Precondition:
  // Postcondition: initializes data members
  QuartzParchmentShears(int playerChoice, int computerChoice, bool playerWins, int playerScore, int computerScore);

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

  void playerPrompt();

  // play
  // Precondition:
  // Postcondition: determines the winner and updates the score
  void play();
};

#endif // QUARTZPARCHMENTSHEARS_H
