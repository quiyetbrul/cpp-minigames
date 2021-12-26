#include "GameWelcome.h"

void Welcome(std::string gameName, bool players) {
  std::cout << "Welcome to the game of " << gameName << "!" << std::endl;
  std::cout << "You are playing against "
            << (players ? "another player" : "a computer") << "." << std::endl;
}
