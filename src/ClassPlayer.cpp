#include "ClassPlayer.h"

Player::Player() {
  playerName = "";
  playerChoice = 0;
  playerScore = 0;
  isWinner = false;
}

Player::Player(std::string playerName, int playerChoice, int playerScore,
               bool isWinner) {
  this->playerName = playerName;
  this->playerChoice = playerChoice;
  this->playerScore = playerScore;
  this->isWinner = isWinner;
}

void Player::reset(bool keepScore) {
  setPlayerName(" ");
  setPlayerChoice(0);
  setIsWinner(false);
  if (!keepScore)
    setPlayerScore(0);
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
  int input = inputInteger(getPlayerName() + prompt, startRange, endRange,
                           "{ClassPlayer.cpp}Player::playerPrompt()");
  return input;
}

void Player::showChoice() {
  std::cout << getPlayerName() << " chose: " << getPlayerChoice() << std::endl;
}

void Player::addScore() { setPlayerScore(getPlayerScore() + 1); }

void Player::showWinner() {
  std::cout << getPlayerName() << (getIsWinner() ? " wins!" : " lost!")
            << std::endl;
}

void Player::showScore() {
  std::cout << getPlayerName() << " score: " << getPlayerScore() << std::endl;
}

int Player::randomNumber(int startRange, int endRange) {
  srand(time(NULL));
  int computerChoice = rand() % (endRange - startRange) + startRange;
  return computerChoice;
}

int Player::intBinarySearch(int startRange, int endRange, int target) {
  int mid = (startRange + endRange) / 2;

  if (startRange > endRange) {
    return -1;
  }
  if (startRange > endRange) {
    return -1;
  }
  if (target == mid) {
    return mid;
  }
  if (target < mid) {
    return intBinarySearch(startRange, mid - 1, target);
  }
  if (target > mid) {
    return intBinarySearch(mid + 1, endRange, target);
  }

  return -1;
}
