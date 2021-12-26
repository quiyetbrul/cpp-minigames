#include "ClassPlayer.h"

Player::Player() {
  playerChoice = 0;
  playerScore = 0;
}

Player::Player(int playerChoice, int playerScore) {
  this->playerChoice = playerChoice;
  this->playerScore = playerScore;
}

void Player::setPlayerName(std::string playerName) {
  this->playerName = playerName;
}

std::string Player::getPlayerName() { return playerName; }

void Player::setPlayerChoice(int playerChoice) {
  this->playerChoice = playerChoice;
}

int Player::getPlayerChoice() { return playerChoice; }

void Player::setPlayerScore(int playerScore) {
  this->playerScore = playerScore;
}

int Player::getPlayerScore() { return playerScore; }

void Player::setIsWinner(bool isWinner) { this->isWinner = isWinner; }

bool Player::getIsWinner() { return isWinner; }

int Player::playerPrompt(std::string prompt, int startRange, int endRange) {
  int input = inputInteger(getPlayerName() + prompt, startRange, endRange);
  return input;
}

int Player::generateComputerChoice(int startRange, int endRange) {
  srand(time(NULL));
  int computerChoice = rand() % (endRange - startRange) + startRange;
  return computerChoice;
}

void Player::showChoice() {
  std::cout << getPlayerName() << " chose: " << getPlayerChoice() << std::endl;
}

void Player::addScore() { setPlayerScore(getPlayerScore() + 1); }

void Player::showWinner() {
  std::cout << getPlayerName() << (getIsWinner() ? " wins!" : " lost!") << std::endl;
}

void Player::showScore() {
  std::cout << getPlayerName() << " score: " << getPlayerScore() << std::endl;
}
