#ifndef GAMETICTACTOE_H
#define GAMETICTACTOE_H

#include "GameObject.h"

void reset(int board[][3]);

bool isWinner(const int board[][3], int *player);

bool isDraw(const int board[][3]);

void displayBoard(const int board[][3]);

void play();

#endif // GAMETICTACTOE_H
