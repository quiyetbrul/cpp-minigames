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
  // default constructor
  // Precondition:
  // Postcondition: initializes data members
  TicTacToe();

  // Reset
  // Precondition:
  // Postcondition: initializes data members
  void Reset();

  // IsWinner
  // Precondition: board is a 3x3 array, player is an int &
  // Postcondition: returns true if there is a winner, false otherwise
  void IsWinner();

  // IsDraw
  // Precondition: board is a 3x3 array
  // Postcondition: returns true if there is a draw, false otherwise
  bool IsDraw();

  // displayBoard
  // Precondition: board is a 3x3 array
  // Postcondition: board is displayed
  void DisplayBoard();

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
