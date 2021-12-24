#include "GameQuartzParchmentShears.h"

void PlayQuartzParchmentShears() {
  std::cout << "Welcome to the game of Quartz Parchment Shears!" << std::endl;
  std::cout << "You are playing against a computer." << std::endl;
  std::cout << "Choose your weapon: " << std::endl;
  std::cout << "1 - Rock" << std::endl;
  std::cout << "2 - Paper" << std::endl;
  std::cout << "3 - Scissors" << std::endl;

  // instantiate player objects
  static Player computer;
  static Player playerOne;

  // set players' names
  computer.setPlayerName("Computer");
  playerOne.setPlayerName("Player One");

  // prompt ranges
  int startRange = 1;
  int endRange = 3;
  std::string prompt = ", enter your choice: ";
  
  // get/set player choice
  playerOne.setPlayerChoice(playerOne.playerPrompt(prompt, startRange, endRange));

  // generate computer choice
  computer.setPlayerChoice(computer.generateComputerChoice(startRange, endRange));

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

  } else if ((playerOne.getPlayerChoice() == 1 && computer.getPlayerChoice() == 3) ||
             (playerOne.getPlayerChoice() == 2 && computer.getPlayerChoice() == 1) ||
             (playerOne.getPlayerChoice() == 3 && computer.getPlayerChoice() == 2)) {
    // show player's and computer's choices
    playerOne.showChoice();
    computer.showChoice();

    // show winner
    playerOne.showWinner(true);

    // add score
    playerOne.addScore();

    // show score
    playerOne.showScore();
    computer.showScore();
    
  } else if ((playerOne.getPlayerChoice() == 3 && computer.getPlayerChoice() == 1) ||
             (playerOne.getPlayerChoice() == 1 && computer.getPlayerChoice() == 2) ||
             (playerOne.getPlayerChoice() == 2 && computer.getPlayerChoice() == 3)) {
    // show player's and computer's choices
    playerOne.showChoice();
    computer.showChoice();

    // show winner
    computer.showWinner(true);

    // add score
    computer.addScore();

    // show score
    playerOne.showScore();
    computer.showScore();
  }

  std::cout << std::endl;
}

void GameQuartzParchmentShears() {
  system("clear");
  char ans = ' ';

  do {
    PlayQuartzParchmentShears();
    ans = inputChar("Play again? (y/n): ", 'y', 'n');
  } while (ans == 'y' || ans == 'Y');
}
