#include <iostream>

#include "../inputValidation.h"
#include "QuartzParchmentShears.h"
#include "QuartzParchmentShearsGameplay.h"

void QuartzParchmentShearsGameplay()
{
    char ans = 'y';
    
    QuartzParchmentShears game;
    
    do
    {
        game.play();
        ans = inputChar("Would you like to play again? (y/n): ", 'y', 'n');
    } while (ans == 'y' || ans == 'Y');
}
