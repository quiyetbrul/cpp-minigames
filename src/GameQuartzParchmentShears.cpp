#include "GameQuartzParchmentShears.h"

static Player playerOne;
static Player computer;

const std::string FILENAME = "{GameQuartzParchmentShears.cpp}";

QuartzParchmentShears::QuartzParchmentShears() {}

void QuartzParchmentShears::Reset() {
  playerOne.reset(true);
  computer.reset(true);
}

void QuartzParchmentShears::DetermineWinner() {
  // show player's and computer's choices
  playerOne.showChoice();
  computer.showChoice();

  // tie
  if (playerOne.getPlayerChoice() == computer.getPlayerChoice()) {
    std::cout << "Tie!" << std::endl;
  }
  // player winner
  else if ((playerOne.getPlayerChoice() == 1 &&
            computer.getPlayerChoice() == 3) ||
           (playerOne.getPlayerChoice() == 2 &&
            computer.getPlayerChoice() == 1) ||
           (playerOne.getPlayerChoice() == 3 &&
            computer.getPlayerChoice() == 2)) {
    // player wins
    playerOne.setIsWinner(true);
    computer.setIsWinner(false);

    // show winner
    playerOne.showWinner();
    computer.showWinner();

    // add score
    playerOne.addScore();
  }
  // computer winner
  else if ((playerOne.getPlayerChoice() == 3 &&
            computer.getPlayerChoice() == 1) ||
           (playerOne.getPlayerChoice() == 1 &&
            computer.getPlayerChoice() == 2) ||
           (playerOne.getPlayerChoice() == 2 &&
            computer.getPlayerChoice() == 3)) {
    // player wins
    playerOne.setIsWinner(false);
    computer.setIsWinner(true);

    // show winner
    playerOne.showWinner();
    computer.showWinner();

    // add score
    computer.addScore();
  }

  // show score
  playerOne.showScore();
  computer.showScore();
}

void QuartzParchmentShears::GameMechanics() {
  std::string gameName = "Quarts Parchment Shears";
  Welcome(gameName, false);
  std::cout << "Choose your weapon: " << std::endl;
  std::cout << "1 - Rock" << std::endl;
  std::cout << "2 - Paper" << std::endl;
  std::cout << "3 - Scissors" << std::endl;

  // set players' names
  computer.setPlayerName("Computer");
  playerOne.setPlayerName("Player One");

  // prompt ranges
  int startRange = 1;
  int endRange = 3;
  std::string prompt = ", enter your choice: ";

  // get/set player choice
  playerOne.setPlayerChoice(playerOne.playerPrompt(
      prompt, startRange, endRange,
      FILENAME + "QuartzParchmentShears::GameMechanics()"));

  // generate computer choice
  computer.setPlayerChoice(computer.randomNumber(startRange, endRange));

  std::cout << std::endl;

  // determine winner
  DetermineWinner();

  std::cout << std::endl;
}

void QuartzParchmentShears::GamePlay() {
  system("clear");
  char ans = ' ';

  do {
    // start game
    GameMechanics();

    ans = inputChar("Play again? (y/n): ", 'y', 'n',
                    FILENAME + "QuartzParchmentShears::GamePlay()");

    // reset game
    Reset();

    system("clear");
  } while (ans == 'y' || ans == 'Y');
}
