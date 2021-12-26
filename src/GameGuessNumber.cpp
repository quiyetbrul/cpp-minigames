#include "GameGuessNumber.h"
#include <climits>

static Player playerOne;
static Player computer;

GuessNumber::GuessNumber() {}

void GuessNumber::Reset(std::vector<int> &guessHistory, int &numberOfGuess) {
  numberOfGuess = 0;
  guessHistory.clear();
}

int GuessNumber::NumberOfGuess(int &numberOfGuess) { return ++numberOfGuess; }

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

  // already guessed
  if (std::find(guessHistory.begin(), guessHistory.end(), guess) !=
      guessHistory.end()) {
    std::cout << currentGuesser << " already guessed " << guess << std::endl;
    // NumberOfGuess(numberOfGuess);
    return;
  }

  // add guess to history
  guessHistory.push_back(guess);

  // show history
  std::cout << "Guess history: ";
  for (int i : guessHistory) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // out of range
  if (guess < startRange || guess > endRange) {
    std::cout << currentGuesser << " guess must be between " << startRange
              << " and " << endRange << std::endl;
    // NumberOfGuess(numberOfGuess);
    return;
  }
  // too high
  else if (guess > numberToGuess) {
    std::cout << currentGuesser << " guessed too high." << std::endl;
    NumberOfGuess(numberOfGuess);
    return;
  }
  // too low
  else if (guess < numberToGuess) {
    std::cout << currentGuesser << " guessed too low." << std::endl;
    NumberOfGuess(numberOfGuess);
    return;
  }
}

void GuessNumber::GameMechanics() {

  startRange = 1; // INT_MIN;
  endRange = 100; // INT_MAX;

  Reset(guessHistory, numberOfGuess);

  std::string gameName = "Guess Number";
  Welcome(gameName, false);

  // set players' names
  computer.setPlayerName("Computer");
  playerOne.setPlayerName("Player One");

  // who is playing?
  int player = inputInteger("Who is playing (1-Player, 2-Computer)?: ", 1, 2);

  // computer will give a random number, player will guess
  if (player == 1) {
    std::cout << playerOne.getPlayerName() << " must guess a number between "
              << startRange << " and " << endRange << "." << std::endl;
    computer.setPlayerChoice(randomNumber(startRange, endRange));
    std::cout << computer.getPlayerName() << " chose "
              << computer.getPlayerChoice() << std::endl;

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
    std::cout << computer.getPlayerName() << " must guess a number between "
              << startRange << " and " << endRange << "." << std::endl;
    playerOne.setPlayerChoice(playerOne.playerPrompt(
        ", enter a number for computer to guess: ", startRange, endRange));
    std::cout << playerOne.getPlayerName() << " chose "
              << playerOne.getPlayerChoice() << std::endl;

    while (computer.getPlayerChoice() != playerOne.getPlayerChoice()) {
      // do I want this or do I want Player::intBinarySearch(int,int,int)?
      int mid = (startRange + endRange) / 2;
      computer.setPlayerChoice(mid);
      // change range
      /*
        initial range (startRange = 1, endRange = 100)
        1 < numberToGuess < 100

        numberToGuess = 32
        guess = 12

        guess < numberToGuess
        startRange = guess
        12 < numberToGuess < 100

        guess = 50
        guess > numberToGuess
        endRange = guess
        12 < numberToGuess < 50
      */
      if (computer.getPlayerChoice() < playerOne.getPlayerChoice()) {
        startRange = computer.getPlayerChoice();
      } else if (computer.getPlayerChoice() > playerOne.getPlayerChoice()) {
        endRange = computer.getPlayerChoice();
      }

      // if guess is not in history, continue
      if (!(std::find(guessHistory.begin(), guessHistory.end(),
                      computer.getPlayerChoice()) != guessHistory.end())) {
        GuessMechanics(false, startRange, endRange, computer.getPlayerChoice(),
                       playerOne.getPlayerChoice(), numberOfGuess);
        std::cout << std::endl;
      }
    }
  }
}

void GuessNumber::GamePlay() {
  system("clear");
  char ans = ' ';

  do {
    GameMechanics();
    ans = inputChar("Play again? (y/n): ", 'y', 'n');
    system("clear");
  } while (ans == 'y' || ans == 'Y');
}
