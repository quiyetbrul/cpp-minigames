#include <chrono>
#include <thread>

#include "GameHangman.h"

Hangman::~Hangman(){}

Hangman::Hangman(){}

void Hangman::GameMechanics(){}

void Hangman::GamePlay() {
  system("clear");
  std::cout << "Hangman has not been developed yet." << std::endl;
  std::cout << "Please wait for the next update." << std::endl;
  std::cout << "Returning to main menu..." << std::endl;
  std::chrono::seconds dura(3);
  std::this_thread::sleep_for(dura);
}
