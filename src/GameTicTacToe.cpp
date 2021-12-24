#include "GameTicTacToe.h"
#include "InputValidation.h"

Player playerOne;
Player playerTwo;

void reset(int board[][3]) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      board[row][column] = 0;
    }
  }
}

bool isWinner(const int board[][3], int &player) {
  // all rows
  for (int row = 0; row < 3; row++)
    if (board[row][0] + board[row][1] + board[row][2] == 3) {
      player = 1;
      return true;
    } else if (board[row][0] + board[row][1] + board[row][2] == -3) {
      player = -1;
      return true;
    }

  // all columns
  for (int column = 0; column < 3; column++)
    if (board[0][column] + board[1][column] + board[2][column] == 3) {
      player = 1;
      return true;
    } else if (board[0][column] + board[1][column] + board[2][column] == -3) {
      player = -1;
      return true;
    }
  
  // all diagonal
  if ((board[0][0] + board[1][1] + board[2][2] == 3) ||
      (board[0][2] + board[1][1] + board[2][0] == 3)) {
    player = 1;
    return true;
  } else if ((board[0][0] + board[1][1] + board[2][2] == -3) ||
             (board[0][2] + board[1][1] + board[2][0] == -3)) {
    player = -1;
    return true;
  }

  return false;
}

bool isDraw(const int board[][3]) {
  for (int row = 0; row < 3; row++)
    for (int column = 0; column < 3; column++)
      if (board[row][column] == 0)
        return false;
  return true;
}

void displayBoard(const int b[][3]) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++)
      if (b[row][column] == 0)
        std::cout << "[ ]";
      else if (b[row][column] == 1)
        std::cout << "[X]";
      else if (b[row][column] == -1)
        std::cout << "[O]";
    std::cout << std::endl;
  }
}

void checkGameStatus(const int board[][3], int &player){
  if (isWinner(board, player)) {
    player == 1 ? playerOne.showWinner(true) : playerTwo.showWinner(true);
  } else if (isDraw(board)) {
    std::cout << "It is a draw\n";
  }
}

void PlayTicTacToe() {
  std::cout << "Welcome to the game of Quartz Parchment Shears!" << std::endl;
  std::cout << "This is a two-player game." << std::endl;

  std::string playerOneName = inputString("Enter player one's name (X): ");
  std::string playerTwoName = inputString("Enter player two's name (O): ");

  playerOne.setPlayerName(playerOneName);
  playerTwo.setPlayerName(playerTwoName);

  int board[3][3];

  // reset
  reset(board);

  int player = 0; // determine which player
  int player1 = 1;  // 1 represent X
  int player2 = -1; // 2 represent O

  int startRange = 0;
  int endRange = 2;

  std::string promptRow = " choose row: ";
  std::string promptColumn = " choose column: ";
  std::string ERROR = "ERROR: Square has been played. Choose again.\n";

  while (true) {

    displayBoard(board);

    while (true) {
      int row = playerOne.playerPrompt(promptRow, startRange, endRange);
      int column = playerOne.playerPrompt(promptColumn, startRange, endRange);

      if (board[row][column] == 0) {
        board[row][column] = player1;
        break;
      } else {
        std::cout << ERROR;
      }
    }

    displayBoard(board);

    if (isWinner(board, player)) {
      playerOne.showWinner(true);
      break;
    } else if (isDraw(board)) {
      std::cout << "It is a draw\n";
      break;
    }

    while (true) {
      int row = playerTwo.playerPrompt(promptRow, startRange, endRange);
      int column = playerTwo.playerPrompt(promptColumn, startRange, endRange);

      if (board[row][column] == 0) {
        board[row][column] = player2;
        break;
      } else {
        std::cout << ERROR;
      }

      displayBoard(board);

      if (isWinner(board, player)) {
        playerTwo.showWinner(true);
        break;
      } else if (isDraw(board)) {
        std::cout << "It is a draw\n";
        break;
      }
    }
  }
}

void GameTicTactoe() {
  system("clear");

  char ans = ' ';

  do {
    PlayTicTacToe();
    ans = inputChar("Play again? (y/n): ", 'y', 'n');
  } while (ans == 'y' || ans == 'Y');
}
