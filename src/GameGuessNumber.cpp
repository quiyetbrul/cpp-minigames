#include "GameGuessNumber.h"

static Player playerOne;
static Player computer;

GuessNumber::GuessNumber() {}

void GuessNumber::Reset() {
  player = 0;

  playerOne.reset(false);
  computer.reset(false);

  numberOfGuess = 0;
  guessHistory.clear();
}

int GuessNumber::NumberOfGuess(int &numberOfGuess) { return ++numberOfGuess; }

void GuessNumber::PrintGuessHistory(const std::vector<int> &guessHistory) {
  std::cout << "Guess history:" << std::endl;

  int col = 0;
  for (auto i : guessHistory) {
    std::cout << std::left << std::setw(5) << i << " ";
    if (++col % 10 == 0) {
      std::cout << std::endl;
    }
  }

  std::cout << std::endl;
}

void GuessNumber::GuessHistory(const std::string currentGuesser,
                               std::vector<int> &guessHistory,
                               const int guess) {
  // already guessed
  if (std::find(guessHistory.begin(), guessHistory.end(), guess) !=
      guessHistory.end()) {
    std::cout << currentGuesser << " already guessed " << guess << std::endl;
    return;
  }

  // add guess to history
  guessHistory.push_back(guess);

  // show history
  PrintGuessHistory(guessHistory);
}

void GuessNumber::GuessRange(const std::string currentGuesser,
                             const int startRange, const int endRange,
                             int guess, const int numberToGuess,
                             int &numberOfGuess) {
  // out of range
  if (guess < startRange || guess > endRange) {
    std::cout << currentGuesser << " guess must be between " << startRange
              << " and " << endRange << std::endl;
  }
  // too high
  else if (guess > numberToGuess) {
    std::cout << currentGuesser << " guessed too high." << std::endl;
  }
  // too low
  else if (guess < numberToGuess) {
    std::cout << currentGuesser << " guessed too low." << std::endl;
  }
}

void GuessNumber::GuessMechanics(bool player, const int startRange,
                                 const int endRange, const int guess,
                                 const int numberToGuess, int &numberOfGuess) {
  // who is the player?
  std::string currentGuesser =
      player ? playerOne.getPlayerName() : computer.getPlayerName();

  // right guess
  if (guess == numberToGuess) {
    NumberOfGuess(numberOfGuess);
    std::cout << currentGuesser << " guessed " << guess << " in "
              << numberOfGuess << " guesses." << std::endl;
    return;
  }

  // check guess history
  GuessHistory(currentGuesser, guessHistory, guess);

  // guess range
  GuessRange(currentGuesser, startRange, endRange, guess, numberToGuess,
             numberOfGuess);

  // add guess to number of guesses
  NumberOfGuess(numberOfGuess);
}

void GuessNumber::GameMechanics() {
  std::string gameName = "Guess Number";
  Welcome(gameName, false);
  std::cout << std::endl;

  startRange = 1; // INT_MIN;
  endRange = 100; // INT_MAX;

  // set players' names
  computer.setPlayerName("Computer");
  playerOne.setPlayerName("Player One");

  // who is playing?
  player = inputInteger("Who is playing (1-Player, 2-Computer)?: ", 1, 2,
                        "{GameGuessNumber.cpp}GuessNumber::GameMechanics()");
  std::cout << std::endl;

  // computer will give a random number, player will guess
  if (player == 1) {

    computer.setPlayerChoice(randomNumber(startRange, endRange));

    while (playerOne.getPlayerChoice() != computer.getPlayerChoice()) {
      playerOne.setPlayerChoice(
          playerOne.playerPrompt(", enter your guess: ", startRange, endRange));

      GuessMechanics(true, startRange, endRange, playerOne.getPlayerChoice(),
                     computer.getPlayerChoice(), numberOfGuess);

      std::cout << std::endl;
    }
  }
  // player will give a random number, computer will guess
  else if (player == 2) {

    playerOne.setPlayerChoice(playerOne.playerPrompt(
        ", enter a number for computer to guess: ", startRange, endRange));

    std::cout << playerOne.getPlayerName() << " chose "
              << playerOne.getPlayerChoice() << std::endl;

    while (computer.getPlayerChoice() != playerOne.getPlayerChoice()) {
      // initiate binary search
      int mid = (startRange + endRange) / 2;

      computer.setPlayerChoice(mid);

      // change range
      if (computer.getPlayerChoice() < playerOne.getPlayerChoice()) {
        startRange = computer.getPlayerChoice();
      } else if (computer.getPlayerChoice() > playerOne.getPlayerChoice()) {
        endRange = computer.getPlayerChoice();
      }

      GuessMechanics(false, startRange, endRange, computer.getPlayerChoice(),
                     playerOne.getPlayerChoice(), numberOfGuess);
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
                    "{GameGuessNumber.cpp}GuessNumber::GamePlay()");

    // reset game
    Reset();

    system("clear");
  } while (ans == 'y' || ans == 'Y');
}
