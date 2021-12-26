#ifndef GAMETICTACTOE_H
#define GAMETICTACTOE_H

#include "ClassPlayer.h"

class TicTacToe : public Player {
private:

public:
  // default constructor
  TicTacToe();

  // reset board
  // Precondition: board is a 3x3 array
  // Postcondition: board is reset to all 0s
  void reset(int board[3][3]);

  // isWinner
  // Precondition: board is a 3x3 array, player is an int &
  // Postcondition: returns true if there is a winner, false otherwise
  void isWinner(const int board[3][3]);

  // isDraw
  // Precondition: board is a 3x3 array
  // Postcondition: returns true if there is a draw, false otherwise
  bool isDraw(const int board[3][3]);

  // displayBoard
  // Precondition: board is a 3x3 array
  // Postcondition: board is displayed
  void displayBoard(const int board[3][3]);

  // checkGameStatus
  // Precondition: board is a 3x3 array, player is an int &
  // Postcondition: shows winner if there is one, shows draw if there is one,
  void checkGameStatus(const int board[3][3], int &player);

  // game mechanics
  // Precondition:
  // Postcondition: game mechanics are run
  void GameMechanics();

  // game play
  // Precondition:
  // Postcondition: game play is run
  void GamePlay();
};

#endif // GAMETICTACTOE_H
