#include "include/GameTicTacToe.h"
#include "include/InputValidation.h"

static Player playerOne;
static Player playerTwo;

const std::string FILENAME = "{GameTicTacToe.cpp}";

const int SIZE = 3;

TicTacToe::~TicTacToe() {
  std::cout << "Destructor called" << std::endl;
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

void TicTacToe::CheckWinner() {

  for (int i = 0; i < SIZE; i++) {
    // check rows
    if (board[i][0] + board[i][1] + board[i][2] == SIZE) {
      playerOne.setIsWinner(true);
      return;
    } else if (board[i][0] + board[i][1] + board[i][2] == -SIZE) {
      playerTwo.setIsWinner(true);
      return;
    }
    // check columns
    if (board[0][i] + board[1][i] + board[2][i] == SIZE) {
      playerOne.setIsWinner(true);
      return;
    } else if (board[0][i] + board[1][i] + board[2][i] == -SIZE) {
      playerTwo.setIsWinner(true);
      return;
    }
  }

  // all diagonal
  if ((board[0][0] + board[1][1] + board[2][2] == SIZE) ||
      (board[0][2] + board[1][1] + board[2][0] == SIZE)) {
    playerOne.setIsWinner(true);
    return;
  } else if ((board[0][0] + board[1][1] + board[2][2] == -SIZE) ||
             (board[0][2] + board[1][1] + board[2][0] == -SIZE)) {
    playerTwo.setIsWinner(true);
    return;
  }

  // for (int row = 0; row < SIZE; row++) {
  //   for (int column = 0; column < SIZE; column++) {
  //     // add rows
  //     sumRow += board[row][column];

  //     // add columns
  //     sumColumn += board[column][row];

  //     // check diagonals
  //     if (row == column)
  //       sumDiagonalLeft += board[row][column];
  //     else if ((row + column) == (SIZE - 1))
  //       sumDiagonalRight += board[row][SIZE - column - 1];
  //   } // end nested inner for loop

  //   // check for winner
  //   if (sumRow == SIZE || sumColumn == SIZE || sumDiagonalLeft == SIZE ||
  //       sumDiagonalRight == SIZE)
  //     playerOne.setIsWinner(true);
  //   if (sumRow == -SIZE || sumColumn == -SIZE || sumDiagonalLeft == -SIZE ||
  //       sumDiagonalRight == -SIZE)
  //     playerTwo.setIsWinner(true);
  // } // end nested outer for loop

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
      printf((board[row][column] == 1)    ? " [ X ]\t"
             : (board[row][column] == -1) ? " [ O ]\t"
                                          : "[%d, %d]\t",
             row, column);
    }
    std::cout << std::endl;
  }
} // -----------------------------------------------------------------------------

void TicTacToe::GetChoices(Player &player, bool isAI) {
  std::string promptRow = " choose row: ";
  std::string promptColumn = " choose column: ";

  if (!isAI) {
    row = player.playerPrompt(promptRow, startRange, endRange,
                              FILENAME + "TicTacToe::GameMechanics()");
    column = player.playerPrompt(promptColumn, startRange, endRange,
                                 FILENAME + "TicTacToe::GameMechanics()");
  }
} // -----------------------------------------------------------------------------

void TicTacToe::GameMechanics() {
  std::string gameName = "Tic Tac Toe";

  char multiplayerPrompt =
      inputChar("(M)ultiplayer or (S)ingleplayer? ", 'm', 's',
                FILENAME + "TiceTacToe::GameMechanics()");
  bool multiplayerGame = (multiplayerPrompt == 'm') ? true : false;

  Welcome(gameName, multiplayerGame);
  std::cout << std::endl;

  playerOne.setPlayerName("Player One");
  playerTwo.setPlayerName(multiplayerGame ? "Player Two" : "Computer");

  DisplayBoard();

  std::string promptRow = " choose row: ";
  std::string promptColumn = " choose column: ";
  std::string ERROR = "ERROR: Square has been played. Choose again.\n";

  while (true) {
    while (true) {
      if (player == 1) {
        GetChoices(playerOne, false);
      } else if (player == -1) {
        if (multiplayerGame)
          GetChoices(playerTwo, false);
      }

      if (board[row][column] == 0) {
        board[row][column] = player;
        break;
      } else {
        std::cout << ERROR << std::endl;
      }
    }

    std::cout << std::endl;
    CheckWinner();

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

    // switch player
    player *= -1;
  }
  std::cout << std::endl;
} // -----------------------------------------------------------------------------

void TicTacToe::GamePlay() {
  char ans = ' ';

  do {
    system("clear");

    // reset game
    Reset();

    // start game
    GameMechanics();

    ans = inputChar("Play again? (y/n): ", 'y', 'n',
                    FILENAME + "TiceTacToe::GamePlay()");
  } while (ans == 'y' || ans == 'Y');
} // -----------------------------------------------------------------------------
