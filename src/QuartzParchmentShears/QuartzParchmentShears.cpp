#include <cmath>
#include <iostream>
#include "../inputValidation.h"
#include "QuartzParchmentShears.h"

QuartzParchmentShears::QuartzParchmentShears()
{
    playerChoice = 0;
    computerChoice = 0;
    playerWins = false;
    playerScore = 0;
    computerScore = 0;
}

QuartzParchmentShears::QuartzParchmentShears(int playerChoice, int computerChoice, bool playerWins, int playerScore, int computerScore)
{
    this->playerChoice = playerChoice;
    this->computerChoice = computerChoice;
    this->playerWins = playerWins;
    this->playerScore = playerScore;
    this->computerScore = computerScore;
}

void QuartzParchmentShears::setPlayerChoice(int playerChoice)
{
    this->playerChoice = playerChoice;
}

void QuartzParchmentShears::setComputerChoice(int computerChoice)
{
    this->computerChoice = computerChoice;
}

int QuartzParchmentShears::getPlayerChoice()
{
    return this->playerChoice;
}

int QuartzParchmentShears::getComputerChoice()
{
    return this->computerChoice;
}

void QuartzParchmentShears::setPlayerScore(int playerScore)
{
    this->playerScore = playerScore;
}

void QuartzParchmentShears::setComputerScore(int computerScore)
{
    this->computerScore = computerScore;
}

int QuartzParchmentShears::getPlayerScore()
{
    return this->playerScore;
}

int QuartzParchmentShears::getComputerScore()
{
    return this->computerScore;
}

void QuartzParchmentShears::playerPrompt()
{
    // int input = inputInteger("Enter your choice: ", 0, 2);
    int input = 0;
    input = inputInteger("Enter your choice: ", 1, 3);
    setPlayerChoice(input);
}

void QuartzParchmentShears::play()
{

    // generate computer choice
    int randomNumber = rand() % 3 + 1;
    setComputerChoice(randomNumber);

    // get player choice
    playerPrompt();

    // determine winner
    if (getPlayerChoice() == getComputerChoice())
    {
        // tie
    }
    else if ((getPlayerChoice() == 1 && getComputerChoice()) == 3 ||
             (getPlayerChoice() == 2 && getComputerChoice()) == 1 ||
             (getPlayerChoice() == 3 && getComputerChoice()) == 2)
    {
        setPlayerScore(getPlayerScore() + 1);
    }
    else if ((getPlayerChoice() == 3 && getComputerChoice()) == 1 ||
             (getPlayerChoice() == 1 && getComputerChoice()) == 2 ||
             (getPlayerChoice() == 2 && getComputerChoice()) == 3)
    {
        setComputerChoice(getComputerScore() + 1);
    }
}
