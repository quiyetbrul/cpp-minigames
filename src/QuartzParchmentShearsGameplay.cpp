#include <iostream>

#include "QuartzParchmentShearsGameplay.h"

void play()
{
    static GameObject game;

    // generate computer choice
    game.setComputerChoice(game.generateComputerChoice(3));

    std::cout << "1 - Rock\n";
    std::cout << "2 - Paper\n";
    std::cout << "3 - Scissors\n";
    // get player choice
    game.playerPrompt(3);

    std::cout << std::endl;

    // determine winner
    if (game.getPlayerChoice() == game.getComputerChoice())
    {
        std::cout << "Player chose: " << game.getPlayerChoice() << std::endl;
        std::cout << "Computer chose: " << game.getComputerChoice() << std::endl;
        std::cout << "Tie!" << std::endl;
        std::cout << "\nPlayer Score: " << game.getPlayerScore() << std::endl;
        std::cout << "Computer Score: " << game.getComputerScore() << std::endl;
    }
    else if ((game.getPlayerChoice() == 1 && game.getComputerChoice()) == 3 ||
             (game.getPlayerChoice() == 2 && game.getComputerChoice()) == 1 ||
             (game.getPlayerChoice() == 3 && game.getComputerChoice()) == 2)
    {
        game.showResult(true);
    }
    else if ((game.getPlayerChoice() == 3 && game.getComputerChoice()) == 1 ||
             (game.getPlayerChoice() == 1 && game.getComputerChoice()) == 2 ||
             (game.getPlayerChoice() == 2 && game.getComputerChoice()) == 3)
    {
        game.showResult(false);
    }
}

void QuartzParchmentShearsGameplay()
{
    char ans = ' ';

    do
    {
        play();
        ans = inputChar("Would you like to play again? (y/n): ", 'y', 'n');
    } while (ans == 'y' || ans == 'Y');
}
