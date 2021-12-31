#include "GameQuartzParchmentShears.h"

static Player playerOne;
static Player computer;

const std::string FILENAME = "{GameQuartzParchmentShears.cpp}";

QuartzParchmentShears::~QuartzParchmentShears() {
  std::cout << "Destructor called" << std::endl;
} // -----------------------------------------------------------------------------

QuartzParchmentShears::QuartzParchmentShears() {
  playerName = "";
  startRange = 1;
  endRange = 3;
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::Reset(bool keepScore) {
  playerOne.reset(keepScore);
  computer.reset(keepScore);
  startRange = 1;
  endRange = 3;
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::showChoice(int player) {
  playerName =
      player == 1 ? playerOne.getPlayerName() : computer.getPlayerName();

  switch (player == 1 ? playerOne.getPlayerChoice()
                      : computer.getPlayerChoice()) {
  case 1:
    std::cout << playerName << " chose: Rock" << std::endl;
    break;
  case 2:
    std::cout << playerName << " chose: Paper" << std::endl;
    break;
  case 3:
    std::cout << playerName << " chose: Scissors" << std::endl;
    break;
  default:
    std::cout << playerName << " chose: Invalid" << std::endl;
    break;
  }
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::WinnerMechanics(int player) {
  if (player == 2) {
    // computer wins
    playerOne.setIsWinner(false);
    computer.setIsWinner(true);

    std::cout << std::endl;

    // show winner
    playerOne.showWinner();
    computer.showWinner();

    // add score
    computer.addScore();
  } else if (player == 1) {
    // player wins
    playerOne.setIsWinner(true);
    computer.setIsWinner(false);

    std::cout << std::endl;

    // show winner
    playerOne.showWinner();
    computer.showWinner();

    // add score
    playerOne.addScore();
  }
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::DetermineWinner() {
  // show player's and computer's choices
  showChoice(1); // player
  showChoice(2); // computer

  // tie
  if (playerOne.getPlayerChoice() == computer.getPlayerChoice()) {
    std::cout << "Tie!" << std::endl;
  }
  // computer winner
  else if ((playerOne.getPlayerChoice() + startRange) %
               (endRange + startRange) ==
           computer.getPlayerChoice()) {
    WinnerMechanics(2);

  }
  // player winner
  else {
    WinnerMechanics(1);
  }

  std::cout << std::endl;

  // show score
  playerOne.showScore();
  computer.showScore();
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::GameMechanics() {
  std::string gameName = "Quarts Parchment Shears";
  Welcome(gameName, false);
  std::cout << "Choose your weapon: " << std::endl;
  std::cout << "1 - Rock" << std::endl;
  std::cout << "2 - Paper" << std::endl;
  std::cout << "3 - Scissors" << std::endl;

  computer.setPlayerName("Computer");
  playerOne.setPlayerName("Player One");

  std::string prompt = ", enter your choice: ";

  std::cout << std::endl;

  // get/set player choice
  playerOne.setPlayerChoice(playerOne.playerPrompt(
      prompt, startRange, endRange,
      FILENAME + "QuartzParchmentShears::GameMechanics()"));

  // generate computer choice
  computer.setPlayerChoice(
      computer.randomNumber(startRange, endRange + startRange));

  // determine winner
  DetermineWinner();

  std::cout << std::endl;

} // -----------------------------------------------------------------------------

void QuartzParchmentShears::GamePlay() {
  char ans = ' ';

  do {
    system("clear");

    // start game
    GameMechanics();

    ans = inputChar("Play again? (y/n): ", 'y', 'n',
                    FILENAME + "QuartzParchmentShears::GamePlay()");

    // reset game and keep score
    Reset(true);

  } while (ans == 'y' || ans == 'Y');

  // reset game without keeping score
  Reset(false);
} // -----------------------------------------------------------------------------
