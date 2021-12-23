#include <iostream>
#include <string>

#include "GameTicTacToe.h"

void reset(int board[][3]) {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      board[r][c] = 0;
    }
  }
}

bool isWinner(const int board[][3], int *player) {
  // all rows
  for (int r = 0; r < 3; r++)
    if (board[r][0] + board[r][1] + board[r][2] == 3) {
      *player = 1;
      return true;
    } else if (board[r][0] + board[r][1] + board[r][2] == -3) {
      *player = -1;
      return true;
    }
  // all columns
  for (int c = 0; c < 3; c++)
    if (board[0][c] + board[1][c] + board[2][c] == 3) {
      *player = 1;
      return true;
    } else if (board[0][c] + board[1][c] + board[2][c] == -3) {
      *player = -1;
      return true;
    }
  // all diagonal
  if ((board[0][0] + board[1][1] + board[2][2] == 3) ||
      (board[0][2] + board[1][1] + board[2][0] == 3)) {
    *player = 1;
    return true;
  } else if ((board[0][0] + board[1][1] + board[2][2] == -3) ||
             (board[0][2] + board[1][1] + board[2][0] == -3)) {
    *player = -1;
    return true;
  }

  return false;
}
