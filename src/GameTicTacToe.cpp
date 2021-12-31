#include "GameTicTacToe.h"

static Player playerOne;
static Player playerTwo;

const std::string FILENAME = "{GameTicTacToe.cpp}";

const int SIZE = 3;

TicTacToe::~TicTacToe() {
  std::cout<<"Destructor called"<<std::endl;
} // -----------------------------------------------------------------------------

TicTacToe::TicTacToe() {
  player = 1;
  row = 0;
  column = 0;
  sumRow = 0;
  sumColumn = 0;
  sumDiagonalRight = 0;
  sumDiagonalLeft = 0;
  startRange = 0;
  endRange = 2;
} // -----------------------------------------------------------------------------

void TicTacToe::Reset() {
  playerOne.reset(false);
  playerTwo.reset(false);

  player = 1;
  sumRow = 0;
  sumColumn = 0;
  sumDiagonalRight = 0;
  sumDiagonalLeft = 0;

  for (int row = 0; row < SIZE; row++) {
    for (int column = 0; column < SIZE; column++) {
      board[row][column] = 0;
    }
  }
} // -----------------------------------------------------------------------------

void TicTacToe::IsWinner() {
  for (int row = 0; row < SIZE; row++) {
    for (int column = 0; column < SIZE; column++) {
      // add rows
      sumRow += board[row][column];

      // add columns
      sumColumn += board[column][row];

      // check diagonals
      if (row == column)
        sumDiagonalLeft += board[row][column];
      else if ((row + column) == (SIZE - 1))
        sumDiagonalRight += board[row][SIZE - column - 1];
    } // end nested inner for loop

    // check for winner
    if (sumRow == SIZE || sumColumn == SIZE || sumDiagonalLeft == SIZE ||
        sumDiagonalRight == SIZE)
      playerOne.setIsWinner(true);
    if (sumRow == -SIZE || sumColumn == -SIZE || sumDiagonalLeft == -SIZE ||
        sumDiagonalRight == -SIZE)
      playerTwo.setIsWinner(true);
  } // end nested outer for loop
} // -----------------------------------------------------------------------------

bool TicTacToe::IsDraw() {
  for (int row = 0; row < SIZE; row++)
    for (int column = 0; column < SIZE; column++)
      if (board[row][column] == 0)
        return false;
  return true;
} // -----------------------------------------------------------------------------

void TicTacToe::DisplayBoard() {
  for (int row = 0; row < SIZE; row++) {
    for (int column = 0; column < SIZE; column++) {
      std::cout << ((board[row][column] == 1)    ? "[X]"
                    : (board[row][column] == -1) ? "[O]"
                                                 : "[ ]");
    }
    std::cout << std::endl;
  }
} // -----------------------------------------------------------------------------

void TicTacToe::GameMechanics() {
  std::string gameName = "Tic Tac Toe";
  Welcome(gameName, true);

  playerOne.setPlayerName("Player One");
  playerTwo.setPlayerName("Player Two");

  DisplayBoard();

  std::string promptRow = " choose row: ";
  std::string promptColumn = " choose column: ";
  std::string ERROR = "ERROR: Square has been played. Choose again.\n";
  int row = 0;
  int column = 0;

  while (true) {
    while (true) {
      if (player == 1) {
        row = playerOne.playerPrompt(promptRow, startRange, endRange,
                                     FILENAME + "TicTacToe::GameMechanics()");
        column =
            playerOne.playerPrompt(promptColumn, startRange, endRange,
                                   FILENAME + "TicTacToe::GameMechanics()");
      } else if (player == -1) {
        row = playerTwo.playerPrompt(promptRow, startRange, endRange,
                                     FILENAME + "TicTacToe::GameMechanics()");
        column =
            playerTwo.playerPrompt(promptColumn, startRange, endRange,
                                   FILENAME + "TicTacToe::GameMechanics()");
      }

      if (board[row][column] == 0) {
        board[row][column] = player;
        break;
      } else {
        std::cout << ERROR;
      }
    }

    IsWinner();

    if (playerOne.getIsWinner()) {
      DisplayBoard();
      playerOne.showWinner();
      break;
    } else if (playerTwo.getIsWinner()) {
      DisplayBoard();
      playerTwo.showWinner();
      break;
    } else if (IsDraw()) {
      DisplayBoard();
      std::cout << "It's a draw!" << std::endl;
      break;
    }

    DisplayBoard();
    player *= -player;
  }
} // -----------------------------------------------------------------------------

void TicTacToe::GamePlay() {
  char ans = ' ';

  do {
    system("clear");

    // start game
    GameMechanics();

    ans = inputChar("Play again? (y/n): ", 'y', 'n',
                    FILENAME + "TiceTacToe::GamePlay()");
    // reset
    Reset();
  } while (ans == 'y' || ans == 'Y');
} // -----------------------------------------------------------------------------
