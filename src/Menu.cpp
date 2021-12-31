#include "Menu.h"
const std::string FILENAME = "{Menu.cpp}";

void Menu() {

  QuartzParchmentShears QuartzParchmentShears;
  TicTacToe TicTacToe;
  GuessNumber GuessNumber;

  do {
    system("clear");
    std::cout << "CHOOSE A MINI GAME" << std::endl;
    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
    std::cout << "1. Quartz Parchment Shears" << std::endl;
    std::cout << "2. Tic Tac Toe" << std::endl;
    std::cout << "3. Guess Number" << std::endl;
    std::cout << "0. Quit" << std::endl;
    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
    int choice = inputInteger("Enter your choice: ", 0, 4, FILENAME + "Menu()");
    cinIgnore();

    switch (choice) {
    case 1:
      QuartzParchmentShears.GamePlay();
      break;
    case 2:
      TicTacToe.GamePlay();
      break;
    case 3:
      GuessNumber.GamePlay();
      break;
    case 0:
      exit(0);
    default:
      std::cout << "=-=-= "
                << invalidInput(FILENAME + "MENU()", "A VALID CHOICE")
                << " =-=-= " << std::endl;
    }
  } while (true);
} // -----------------------------------------------------------------------------
