#include "GameTicTacToe.h"
#include "InputValidation.h"

Player playerOne;
Player playerTwo;

const int SIZE = 3;

TicTacToe::TicTacToe() {}

void TicTacToe::reset(int board[SIZE][SIZE]) {
  for (int row = 0; row < SIZE; row++) {
    for (int column = 0; column < SIZE; column++) {
      board[row][column] = 0;
      playerOne.setIsWinner(false);
      playerOne.setPlayerName("");
      playerTwo.setIsWinner(false);
      playerTwo.setPlayerName("");
    }
  }
}

void TicTacToe::isWinner(const int board[SIZE][SIZE]) {
  int sumRow = 0;
  int sumColumn = 0;
  int sumDiagonalRight = 0;
  int sumDiagonalLeft = 0;

  for (int row = 0; row < SIZE; row++) {
    for (int column = 0; column < SIZE; column++) {
      // check rows and columns
      sumRow += board[row][column];
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
}

bool TicTacToe::isDraw(const int board[SIZE][SIZE]) {
  for (int row = 0; row < SIZE; row++)
    for (int column = 0; column < SIZE; column++)
      if (board[row][column] == 0)
        return false;
  return true;
}

void TicTacToe::displayBoard(const int board[SIZE][SIZE]) {
  for (int row = 0; row < SIZE; row++) {
    for (int column = 0; column < SIZE; column++) {
      std::cout << ((board[row][column] == 1)    ? "[X]"
                    : (board[row][column] == -1) ? "[O]"
                                                 : "[ ]");
    }
    std::cout << std::endl;
  }
}

void TicTacToe::GameMechanics() {

  int board[SIZE][SIZE];

  // reset
  reset(board);

  std::cout << "Welcome to the game of Tic Tac Toe!" << std::endl;
  std::cout << "This is a two-player game." << std::endl;

  playerOne.setPlayerName(inputString("Enter player one's name (X): "));
  playerTwo.setPlayerName(inputString("Enter player two's name (O): "));

  displayBoard(board);

  int startRange = 0;
  int endRange = 2;
  std::string promptRow = " choose row: ";
  std::string promptColumn = " choose column: ";
  std::string ERROR = "ERROR: Square has been played. Choose again.\n";
  int row = 0;
  int column = 0;

  int player = 1; // 1 represent X and -1 represent O
  while (true) {
    while (true) {
      if (player == 1) {
        row = playerOne.playerPrompt(promptRow, startRange, endRange);
        column = playerOne.playerPrompt(promptColumn, startRange, endRange);
      } else if (player == -1) {
        row = playerTwo.playerPrompt(promptRow, startRange, endRange);
        column = playerTwo.playerPrompt(promptColumn, startRange, endRange);
      }

      if (board[row][column] == 0) {
        board[row][column] = player;
        break;
      } else {
        std::cout << ERROR;
      }
    }

    isWinner(board);

    if (playerOne.getIsWinner()) {
      displayBoard(board);
      playerOne.showWinner();
      break;
    } else if (playerTwo.getIsWinner()) {
      displayBoard(board);
      playerTwo.showWinner();
      break;
    } else if (isDraw(board)) {
      std::cout << "It's a draw!" << std::endl;
      break;
    }
    
    displayBoard(board);
    player *= -player;
  }
}

void TicTacToe::GamePlay() {
  system("clear");

  char ans = ' ';

  do {
    GameMechanics();
    ans = inputChar("Play again? (y/n): ", 'y', 'n');
    system("clear");
  } while (ans == 'y' || ans == 'Y');
}
