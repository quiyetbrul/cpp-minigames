#include "include/GameTicTacToe.h"

const std::string FILENAME = "{GameTicTacToe.cpp}";

Move::Move() {
} // -----------------------------------------------------------------------------

TicTacToe::~TicTacToe() {
} // -----------------------------------------------------------------------------

TicTacToe::TicTacToe() {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      board[row][column] = ' ';
    }
  }
} // -----------------------------------------------------------------------------

void TicTacToe::Reset() {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      board[row][column] = ' ';
    }
  }

  player = ' ';
  computer = ' ';
} // -----------------------------------------------------------------------------

bool TicTacToe::IsWinner() {
  int winStates[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
                         {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
  for (int i = 0; i < 8; i++) {
    bool win = true;
    int firstRow = winStates[i][0] / 3, firstColumn = winStates[i][0] % 3;
    for (int j = 0; j < 3; j++) {
      int row = winStates[i][j] / 3, col = winStates[i][j] % 3;
      if (board[firstRow][firstColumn] == ' ' ||
          board[firstRow][firstColumn] != board[row][col]) {
        win = false;
      }
    }
    if (win)
      return true;
  }
  return false;
} // -----------------------------------------------------------------------------

bool TicTacToe::IsDraw() {
  if (IsWinner())
    return false;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
} // -----------------------------------------------------------------------------

void TicTacToe::PlayerMove() {
  while (true) {
    int cell = inputInteger("Enter an empty square: ", 1, 9,
                            FILENAME + "TicTacToe::GameMechanics()");
    int row = (cell - 1) / 3, column = (cell - 1) % 3;
    if (board[row][column] == ' ') {
      board[row][column] = player;
      break;
    } else
      std::cout << invalidInput(FILENAME + "TicTacToe::PlayerMove()",
                                "an empty square")
                << std::endl;
  }
} // -----------------------------------------------------------------------------

void TicTacToe::ComputerMove() {
  Move bestMove = Minimax(true);
  board[bestMove.getRow()][bestMove.getColumn()] = computer;
} // -----------------------------------------------------------------------------

Move TicTacToe::Minimax(bool isMaximizing) {
  Move bestMove;
  if (IsWinner()) {
    bestMove.setScore(isMaximizing ? -1 : 1);
    return bestMove;
  }

  bestMove.setScore(isMaximizing ? INT_MIN : INT_MAX);

  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {

      // check if the square is empty
      if (board[row][column] == ' ') {
        // whos maximizing?
        board[row][column] = isMaximizing ? computer : player;

        // recursively call minimax
        Move boardStates = Minimax(!isMaximizing);

        if (isMaximizing) {
          if (boardStates.getScore() > bestMove.getScore()) {
            bestMove.setScore(boardStates.getScore());
            bestMove.setRow(row);
            bestMove.setColumn(column);
          }
        } else {
          if (boardStates.getScore() < bestMove.getScore()) {
            bestMove.setScore(boardStates.getScore());
            bestMove.setRow(row);
            bestMove.setColumn(column);
          }
        }
        // reset the square
        board[row][column] = ' ';
      }
    }
  }
  return bestMove;
} // -----------------------------------------------------------------------------

void TicTacToe::DisplayBoard() {
  std::cout << std::endl;
  for (int row = 0; row < 3; row++) {
    if (row) {
      std::cout << "-----------" << std::endl;
    }
    for (int column = 0; column < 3; column++) {
      if (column) {
        std::cout << "|";
      }
      std::cout << ' ';
      if (board[row][column] == ' ') {
        std::cout << 3 * row + column + 1;
      } else {
        std::cout << board[row][column];
      }
      std::cout << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
} // -----------------------------------------------------------------------------

void TicTacToe::GameMechanics() {
  std::string gameName = "Tic Tac Toe";
  Welcome(gameName, false);
  std::cout << std::endl;
  std::cout << "Computer goes first." << std::endl;

  computer = 'X';
  player = 'O';

  while (true) {
    std::cout << "Computer's move: ";
    ComputerMove();
    DisplayBoard();
    if (IsWinner()) {
      std::cout << "Computer wins!" << std::endl;
      return;
    } else if (IsDraw()) {
      std::cout << "Tie!" << std::endl;
      return;
    }
    PlayerMove();
    DisplayBoard();
    if (IsWinner()) {
      std::cout << "Player wins!" << std::endl;
      return;
    } else if (IsDraw()) {
      std::cout << "Tie!" << std::endl;
      return;
    }
  }
} // -----------------------------------------------------------------------------

void TicTacToe::GamePlay() {
  char ans = ' ';

  do {
    system("clear");

    // start game
    GameMechanics();

    ans = inputChar("Play again? (y/n): ", 'y', 'n',
                    FILENAME + "GuessNumber::GamePlay()");

    // reset game
    Reset();
  } while (ans == 'y' || ans == 'Y');
} // -----------------------------------------------------------------------------
