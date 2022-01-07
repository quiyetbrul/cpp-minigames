#ifndef GAMETICTACTOE_H
#define GAMETICTACTOE_H

#include "ClassPlayer.h"

class Move {
  protected:
    int row, column, score;

  public:
    Move();
    Move(int row, int column, int score);
    int getRow(){return row;}
    int getColumn(){return column;}
    int getScore(){return score;}

    void setRow(int row) {this->row = row;}
    void setColumn(int column) {this->column = column;}
    void setScore(int score) {this->score = score;}
};

class TicTacToe : public Player, public Move {
private:
  char board[3][3];
  char player;
  char computer;

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
  bool IsWinner();

  // IsDraw
  // Precondition:
  // Postcondition: returns true if there is a draw, false otherwise
  bool IsDraw();

  void PlayerMove();

  void ComputerMove();

  Move Minimax(bool isMaximizing);

  // displayBoard
  // Precondition:
  // Postcondition: board is displayed
  void DisplayBoard();

  // // GetChoices
  // // Precondition: player is Player object, bool is true if computer is
  // playing
  // // Postcondition: takes in player's choice and updates data members
  // void GetChoices(Player &player, bool isAI);

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
