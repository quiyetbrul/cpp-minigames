#include <iostream>

#include "include/GameQuartzParchmentShears.h"

static Player playerOne;
static Player computer;

const std::string FILENAME = "{GameQuartzParchmentShears.cpp}";

QuartzParchmentShears::~QuartzParchmentShears() {
  std::cout << "Destructor called" << std::endl;
} // -----------------------------------------------------------------------------

QuartzParchmentShears::QuartzParchmentShears() {
  playerName = "";
  ResetWeights();
  startRange = 1;
  endRange = 3;
  round = 0;
  tie = 0;
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::Reset(bool keepScore) {
  playerOne.reset(keepScore);
  computer.reset(keepScore);
  choiceHistoryPlayer.clear();
  choiceHistoryComputer.clear();
  winHistoryPlayer.clear();
  winHistoryComputer.clear();
  ResetWeights();
  startRange = 1;
  endRange = 3;
  round = 0;
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::ResetWeights() {
  rockWeight = 0;
  paperWeight = 0;
  scissorsWeight = 0;
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::WinHistory() {
  winHistoryPlayer.push_back((playerOne.getIsWinner() ? 1 : 0));
  winHistoryComputer.push_back((computer.getIsWinner() ? 1 : 0));
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::PrintWinHistory() {
  std::cout << "Player Win/Loss History: " << std::endl;
  std::cout << winHistoryPlayer << std::endl;

  std::cout << "Computer Win/Loss History: " << std::endl;
  std::cout << winHistoryComputer << std::endl;

  std::cout << std::endl;
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::ChoiceHistory() {
  choiceHistoryPlayer.push_back(playerOne.getPlayerChoice());
  choiceHistoryComputer.push_back(computer.getPlayerChoice());
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::PrintChoiceHistory() {
  std::cout << "Player Choice History: " << std::endl;
  std::cout << choiceHistoryPlayer << std::endl;

  std::cout << "Computer Choice History: " << std::endl;
  std::cout << choiceHistoryComputer << std::endl;

  std::cout << std::endl;
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::ShowChoice(Player &player) {
  std::cout << std::left << std::setw(10) << player.getPlayerName()
            << " chose: ";

  const char *choice[] = {"Rock", "Paper", "Scissors"};
  std::cout << choice[player.getPlayerChoice() - 1] << std::endl;
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::ShowWeights() {
  std::cout << "Rock Weight:     " << rockWeight << std::endl;
  std::cout << "Paper Weight:    " << paperWeight << std::endl;
  std::cout << "Scissors Weight: " << scissorsWeight << std::endl;

  std::cout << std::endl;
} // -----------------------------------------------------------------------------

double QuartzParchmentShears::CalculateStats(Player &player) {
  if (player.getPlayerScore() == 0) {
    return 0;
  }

  double score = static_cast<double>(player.getPlayerScore());
  double rounds = static_cast<double>(round);
  double ties = static_cast<double>(tie);
  double percent = 100.0;

  return ((score + ties) / rounds) * percent;
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::ShowStats(Player &player) {
  std::cout.setf(std::ios::fixed);
  std::cout.setf(std::ios::showpoint);
  std::cout.precision(3);

  std::cout << std::left << std::setw(10) << player.getPlayerName()
            << " stats: " << CalculateStats(player) << std::endl;
} // -----------------------------------------------------------------------------

int QuartzParchmentShears::CalculateComputerChoice() {
  // predicting by partial matching
  // check the last three player's choices
  // 33% chance of predicting the player's next choice
  // probability increases/decreases based on the number of times the player's
  // pattern if any + wins/losses stats
  // int vElem = choiceHistoryPlayer.size();
  // if (vElem >= 3 && winHistoryPlayer[vElem - 1] == 1 &&
  //     choiceHistoryPlayer[vElem - 2] == choiceHistoryPlayer[vElem - 3]) {
  //   std::cout << "EXECUTED: pattern3 algo" << std::endl;
  //   return choiceHistoryPlayer[vElem - 2] == 1   ? 3
  //          : choiceHistoryPlayer[vElem - 2] == 2 ? 2
  //                                                : 1;
  // }

  if (randomNumber(1, 100) % 2 == 1) {
    ResetWeights();
  }

  // add weights to the player's choices
  // std::cout << "EXECUTED: frequentist algo" << std::endl;
  playerOne.getPlayerChoice() == 1   ? rockWeight += 1
  : playerOne.getPlayerChoice() == 2 ? paperWeight += 1
                                     : scissorsWeight += 1;

  return rockWeight >= paperWeight && rockWeight > scissorsWeight     ? 2
         : paperWeight >= scissorsWeight && paperWeight >= rockWeight ? 3
                                                                      : 1;
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::WinnerMechanics(bool player) {
  if (player) {
    // player wins
    playerOne.setIsWinner(true);
    computer.setIsWinner(false);

    std::cout << std::endl;

    // show winner
    playerOne.showWinner();
    computer.showWinner();

    // add score
    playerOne.addScore();
  } else {
    // computer wins
    playerOne.setIsWinner(false);
    computer.setIsWinner(true);

    std::cout << std::endl;

    // show winner
    playerOne.showWinner();
    computer.showWinner();

    // add score
    computer.addScore();
  }
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::DetermineWinner() {
  // show player's and computer's choices
  ShowChoice(playerOne); // player
  ShowChoice(computer);  // computer

  // tie
  if (playerOne.getPlayerChoice() == computer.getPlayerChoice()) {
    ++tie;
    std::cout << "Tie! " << std::endl;
  }
  // player winner
  else if (playerOne.getPlayerChoice() - computer.getPlayerChoice() % 3 == 1) {
    WinnerMechanics(true);
  }
  // computer winner
  else {
    WinnerMechanics(false);
  }

  std::cout << std::endl;

  // show score
  playerOne.showScore();
  computer.showScore();
  std::cout << "Ties: " << tie << std::endl;

  // show stats
  ShowStats(playerOne);
  ShowStats(computer);

  std::cout << std::endl;
} // -----------------------------------------------------------------------------

void QuartzParchmentShears::GameMechanics() {
  std::string gameName = "Rock Paper Scissors";
  Welcome(gameName, false);

  std::cout << "RULES: " << std::endl;
  std::cout << "1 - Rock beats Scissors" << std::endl;
  std::cout << "2 - Paper beats Rock" << std::endl;
  std::cout << "3 - Scissors beats Paper" << std::endl;
  std::cout << std::endl;

  computer.setPlayerName("Computer");
  playerOne.setPlayerName("Player One");

  ++round;

  std::cout << "ROUND: " << round << std::endl;
  std::string prompt = ", enter your choice: ";

  std::cout << std::endl;

  // generate computer choice
  computer.setPlayerChoice(CalculateComputerChoice());

  // get/set player choice
  playerOne.setPlayerChoice(playerOne.playerPrompt(
      prompt, startRange, endRange,
      FILENAME + "QuartzParchmentShears::GameMechanics()"));

  // add both choices to history
  ChoiceHistory();

  // determine winner
  DetermineWinner();

  // add wins/losses to history
  WinHistory();

  // show wins/losses
  PrintWinHistory();

  // show choice history
  PrintChoiceHistory();

  // shoow choices weigths
  ShowWeights();

} // -----------------------------------------------------------------------------

void QuartzParchmentShears::GamePlay() {
  char ans = ' ';

  do {
    system("clear");

    // start game
    GameMechanics();

    ans = inputChar("Play again? (y/n): ", 'y', 'n',
                    FILENAME + "QuartzParchmentShears::GamePlay()");

  } while (ans == 'y' || ans == 'Y');

  // reset game without keeping score
  Reset(false);
} // -----------------------------------------------------------------------------
