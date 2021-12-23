#include "GameObject.h"
#include <cmath>
#include <iostream>

GameObject::GameObject() {
  playerChoice = 0;
  computerChoice = 0;
  playerScore = 0;
  computerScore = 0;
}

GameObject::GameObject(int playerChoice, int computerChoice, int playerScore,
                       int computerScore) {
  this->playerChoice = playerChoice;
  this->computerChoice = computerChoice;
  this->playerScore = playerScore;
  this->computerScore = computerScore;
}

void GameObject::setPlayerChoice(int playerChoice) {
  this->playerChoice = playerChoice;
}

void GameObject::setComputerChoice(int computerChoice) {
  this->computerChoice = computerChoice;
}

int GameObject::getPlayerChoice() { return playerChoice; }

int GameObject::getComputerChoice() { return computerChoice; }

void GameObject::setPlayerScore(int playerScore) {
  this->playerScore = playerScore;
}

void GameObject::setComputerScore(int computerScore) {
  this->computerScore = computerScore;
}

int GameObject::getPlayerScore() { return playerScore; }

int GameObject::getComputerScore() { return computerScore; }

void GameObject::playerPrompt(int endRange) {
  int input = inputInteger("Enter your choice: ", 1, endRange);
  setPlayerChoice(input);
}

int GameObject::generateComputerChoice(int endRange) {
  srand(time(NULL));
  int computerChoice = 0;
  computerChoice = (rand() % endRange) + 1;
  return computerChoice;
}

void GameObject::showResult(bool isWinner, bool hasScore) {
  std::cout << "Player chose: " << getPlayerChoice() << std::endl;
  std::cout << "Computer chose: " << getComputerChoice() << std::endl;

  if (isWinner) {
    std::cout << "\nPlayer wins!" << std::endl;
    setPlayerScore(getPlayerScore() + 1);
  } else {
    std::cout << "\nComputer wins!" << std::endl;
    setComputerScore(getComputerScore() + 1);
  }

  std::cout << "\nPlayer Score: " << getPlayerScore() << std::endl;
  std::cout << "Computer Score: " << getComputerScore() << std::endl;
}
