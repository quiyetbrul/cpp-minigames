#include "GameQuartzParchmentShears.h"

static Player playerOne;
static Player computer;

const std::string FILENAME = "{GameQuartzParchmentShears.cpp}";

QuartzParchmentShears::~QuartzParchmentShears() {
  std::cout << "Destructor called" << std::endl;
} // -----------------------------------------------------------------------------

QuartzParchmentShears::QuartzParchmentShears() {
  playerName = "";
  rockRating = 0;
  paperRating = 0;
  scissorsRating = 0;
  startRange = 1;
  endRange = 5;
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::Reset(bool keepScore) {
  playerOne.reset(keepScore);
  computer.reset(keepScore);
  rockRating = 0;
  paperRating = 0;
  scissorsRating = 0;
  startRange = 1;
  endRange = 5;
} // -----------------------------------------------------------------------------

int QuartzParchmentShears::CalculateComputerChoice() {
  // ALGO: https://daniel.lawrence.lu/programming/rps/#s2.1
  // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  // THE FREQUENTIST ALGORITHM
  playerOne.getPlayerChoice() == 1   ? rockRating += 1
  : playerOne.getPlayerChoice() == 2 ? paperRating += 1
                                     : scissorsRating += 1;

  return rockRating > paperRating && rockRating > scissorsRating ? 2
         : paperRating > scissorsRating                          ? 3
                                                                 : 1;
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::ShowChoice(int player) {
  playerName =
      player == 1 ? playerOne.getPlayerName() : computer.getPlayerName();

  std::cout << std::left << std::setw(10) << playerName << " chose: ";

  switch (player == 1 ? playerOne.getPlayerChoice()
                      : computer.getPlayerChoice()) {
  case 1:
    std::cout << "Rock";
    break;
  case 2:
    std::cout << "Paper";
    break;
  case 3:
    std::cout << "Scissors";
    break;
  default:
    std::cout << "Invalid input";
    break;
  }

  std::cout << std::endl;
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::WinnerMechanics(int player) {
  if (player == 1) {
    // player wins
    playerOne.setIsWinner(true);
    computer.setIsWinner(false);

    std::cout << std::endl;

    // show winner
    playerOne.showWinner();
    computer.showWinner();

    // add score
    playerOne.addScore();
  } else if (player == 2) {
    // computer wins
    playerOne.setIsWinner(false);
    computer.setIsWinner(true);

    std::cout << std::endl;

    // show winner
    playerOne.showWinner();
    computer.showWinner();

    // add score
    computer.addScore();
  }
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::DetermineWinner() {
  // show player's and computer's choices
  ShowChoice(1); // player
  ShowChoice(2); // computer

  // tie
  if (playerOne.getPlayerChoice() == computer.getPlayerChoice()) {
    std::cout << "Tie!" << std::endl;
  }
  // player winner
  else if (playerOne.getPlayerChoice() - computer.getPlayerChoice() % 3 == 1) {
    WinnerMechanics(1);
  }
  // computer winner
  else {
    WinnerMechanics(2);
  }

  std::cout << std::endl;

  // show score
  playerOne.showScore();
  computer.showScore();
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::GameMechanics() {
  std::string gameName = "Rock Paper Scissors";
  Welcome(gameName, false);

  std::cout << "RULES: " << std::endl;
  std::cout << "1 - Rock beats Scissors" << std::endl;
  std::cout << "2 - Paper beats Rock" << std::endl;
  std::cout << "3 - Scissors beats Paper" << std::endl;

  computer.setPlayerName("Computer");
  playerOne.setPlayerName("Player One");

  std::string prompt = ", enter your choice: ";

  std::cout << std::endl;

  // get/set player choice
  playerOne.setPlayerChoice(playerOne.playerPrompt(
      prompt, startRange, endRange,
      FILENAME + "QuartzParchmentShears::GameMechanics()"));

  // generate computer choice
  computer.setPlayerChoice(CalculateComputerChoice());

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

  } while (ans == 'y' || ans == 'Y');

  // reset game without keeping score
  Reset(false);
} // -----------------------------------------------------------------------------
