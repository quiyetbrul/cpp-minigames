#include <iostream>

#include "Menu.h"

void Menu() {
  do {
    system("clear");
    std::cout << "CHOOSE A MINI GAME" << std::endl;
    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
    std::cout << "1. Quartz Parchment Shears" << std::endl;
    std::cout << "2. Tic Tac Toe" << std::endl;
    std::cout << "0. Quit" << std::endl;
    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
    int choice = inputInteger("Enter your choice: ", 0, 2);

    switch (choice) {
      case 1: GameQuartzParchmentShears(); break;
      case 2: GameTicTactoe(); break;
      case 0: exit(0);
      default: std::cout << "=-=-= ERROR: INVALID CHOICE =-=-=" << std::endl;
    }
  }while (true);
  
}
