#include "GameGuessNumber.h"
#include "InputValidation.h"

static Player playerOne;
static Player computer;

const std::string FILENAME = "{GameGuessNumber.cpp}";

GuessNumber::~GuessNumber() {
  // destructor
}

GuessNumber::GuessNumber() {
  player = 0;
  numberOfGuess = 0;
  playerGuess = 0;
  numberToGuess = 0;
  startRange = 1;
  endRange = 100;
}

void GuessNumber::Reset() {
  playerOne.reset(false);
  computer.reset(false);

  player = 0;
  numberOfGuess = 0;
  playerGuess = 0;
  numberToGuess = 0;
  startRange = 1;
  endRange = 100;

  guessHistory.clear();
}

void GuessNumber::setNumberOfGuess(int numberOfGuess) {
  this->numberOfGuess = numberOfGuess;
}

int GuessNumber::getNumberOfGuess() { return playerGuess; }

void GuessNumber::GuessHistory() {
  // right guess
  if (playerGuess == numberToGuess) {
    ++numberOfGuess;
    std::cout << playerName << " guessed " << playerGuess << " in "
              << numberOfGuess << " guesses." << std::endl;
    return;
  }

  // already guessed
  if (std::find(guessHistory.begin(), guessHistory.end(), playerGuess) !=
      guessHistory.end()) {
    std::cout << playerName << " already guessed " << playerGuess << std::endl;
    return;
  }

  guessHistory.push_back(playerGuess);

  PrintGuessHistory();

  GuessRange();

  ++numberOfGuess;
}

void GuessNumber::PrintGuessHistory() {
  std::cout << "Guess history:" << std::endl;

  int col = 0;
  for (auto i : guessHistory) {
    std::cout << std::left << std::setw(5) << i << " ";
    // each row has 10 columns
    if (++col % 10 == 0) {
      std::cout << std::endl;
    }
  }

  std::cout << std::endl;
}

void GuessNumber::GuessRange() {
  // too high
  if (playerGuess > numberToGuess) {
    std::cout << playerName << " guessed too high." << std::endl;
    return;
  }
  // too low
  else if (playerGuess < numberToGuess) {
    std::cout << playerName << " guessed too low." << std::endl;
    return;
  }

  // input validation already handles ranges
  // this will never run
  // out of range
  if (playerGuess < startRange || playerGuess > endRange) {
    std::cout << playerName << " guessed out of range." << std::endl;
    return;
  }
}

void GuessNumber::GameMechanics() {
  std::string gameName = "Guess Number";
  Welcome(gameName, false);
  std::cout << std::endl;

  // set players' names
  computer.setPlayerName("Computer");
  playerOne.setPlayerName("Player One");

  // who is playing?
  player = inputInteger("Who is playing (1-Player, 2-Computer)?: ", 1, 2,
                        FILENAME + "GuessNumber::GameMechanics()");
  std::cout << std::endl;

  // computer will give a random number, player will guess
  if (player == 1) {
    playerName = playerOne.getPlayerName();

    computer.setPlayerChoice(randomNumber(startRange, endRange));
    numberToGuess = computer.getPlayerChoice();

    while (playerOne.getPlayerChoice() != numberToGuess) {
      playerOne.setPlayerChoice(
          playerOne.playerPrompt(", enter your guess: ", startRange, endRange,
                                 FILENAME + "GuessNumber::GameMechanics()"));

      playerGuess = playerOne.getPlayerChoice();

      GuessHistory();

      std::cout << std::endl;
    }
  }
  // player will give a random number, computer will guess
  else if (player == 2) {
    playerName = computer.getPlayerName();

    playerOne.setPlayerChoice(playerOne.playerPrompt(
        ", enter a number for computer to guess: ", startRange, endRange,
        FILENAME + "GuessNumber::GameMechanics()"));
    numberToGuess = playerOne.getPlayerChoice();

    std::cout << playerOne.getPlayerName() << " chose "
              << playerOne.getPlayerChoice() << std::endl;

    while (computer.getPlayerChoice() != playerOne.getPlayerChoice()) {
      int mid = (startRange + endRange) / 2;

      computer.setPlayerChoice(mid);
      playerGuess = computer.getPlayerChoice();

      // change range
      if (playerGuess < numberToGuess) {
        startRange = playerGuess;
      } else if (playerGuess > numberToGuess) {
        endRange = playerGuess;
      }

      GuessHistory();
      std::cout << std::endl;
    }
  }
}

void GuessNumber::GamePlay() {
  system("clear");
  char ans = ' ';

  do {
    // start game
    GameMechanics();

    ans = inputChar("Play again? (y/n): ", 'y', 'n',
                    FILENAME + "GuessNumber::GamePlay()");

    // reset game
    Reset();

    system("clear");
  } while (ans == 'y' || ans == 'Y');
}
