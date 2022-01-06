#ifndef GAMETICTACTOE_H
#define GAMETICTACTOE_H

#include "ClassPlayer.h"

class TicTacToe : public Player {
private:
  int board[3][3];
  int player;
  int row;
  int column;
  int sumRow;
  int sumColumn;
  int sumDiagonalRight;
  int sumDiagonalLeft;
  int startRange;
  int endRange;

public:
  // destructor
  // Precondition:
  // Postcondition:
  ~TicTacToe();
  
  // default constructor
  // Precondition:
  // Postcondition: initializes data members
  TicTacToe();

  // Reset
  // Precondition:
  // Postcondition: initializes data members
  void Reset();

  // IsWinner
  // Precondition:
  // Postcondition: returns true if there is a winner, false otherwise
  void CheckWinner();

  // IsDraw
  // Precondition:
  // Postcondition: returns true if there is a draw, false otherwise
  bool IsDraw();

  // displayBoard
  // Precondition: 
  // Postcondition: board is displayed
  void DisplayBoard();

  // GetChoices
  // Precondition: player is Player object, bool is true if computer is playing
  // Postcondition: takes in player's choice and updates data members
  void GetChoices(Player &player, bool isAI);

  // GameMechanics
  // Precondition:
  // Postcondition: game mechanics are run
  void GameMechanics();

  // GamePlay
  // Precondition:
  // Postcondition: game play is run
  void GamePlay();
};

#endif // GAMETICTACTOE_H
