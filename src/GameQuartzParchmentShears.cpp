#include "GameQuartzParchmentShears.h"
#include <cstdlib>

static Player playerOne;
static Player computer;

QuartzParchmentShears::QuartzParchmentShears() {}

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
  playerOne.setPlayerChoice(
      playerOne.playerPrompt(prompt, startRange, endRange));

  // generate computer choice
  computer.setPlayerChoice(computer.randomNumber(startRange, endRange));

  std::cout << std::endl;

  // determine winner
  if (playerOne.getPlayerChoice() == computer.getPlayerChoice()) {
    // show player's and computer's choices
    playerOne.showChoice();
    computer.showChoice();

    // tie
    std::cout << "Tie!" << std::endl;

    // show score
    playerOne.showScore();
    computer.showScore();

  } else if ((playerOne.getPlayerChoice() == 1 &&
              computer.getPlayerChoice() == 3) ||
             (playerOne.getPlayerChoice() == 2 &&
              computer.getPlayerChoice() == 1) ||
             (playerOne.getPlayerChoice() == 3 &&
              computer.getPlayerChoice() == 2)) {
    // show player's and computer's choices
    playerOne.showChoice();
    computer.showChoice();

    // player wins
    playerOne.setIsWinner(true);

    // show winner
    playerOne.showWinner();

    // add score
    playerOne.addScore();

    // show score
    playerOne.showScore();
    computer.showScore();

  } else if ((playerOne.getPlayerChoice() == 3 &&
              computer.getPlayerChoice() == 1) ||
             (playerOne.getPlayerChoice() == 1 &&
              computer.getPlayerChoice() == 2) ||
             (playerOne.getPlayerChoice() == 2 &&
              computer.getPlayerChoice() == 3)) {
    // show player's and computer's choices
    playerOne.showChoice();
    computer.showChoice();

    // player wins
    computer.setIsWinner(true);

    // show winner
    computer.showWinner();

    // add score
    computer.addScore();

    // show score
    playerOne.showScore();
    computer.showScore();
  }

  std::cout << std::endl;
}

void QuartzParchmentShears::GamePlay() {
  system("clear");
  char ans = ' ';

  do {
    GameMechanics();
    ans = inputChar("Play again? (y/n): ", 'y', 'n',
                    "{GameQuartzParchmentShears.cpp}QuartzParchmentShears::GamePlay()");
    system("clear");
  } while (ans == 'y' || ans == 'Y');
}
