#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define PLAYER_1 1
#define PLAYER_2 2


#define OKAY 5

void initCurses();
void drawBoard();
void initBoard(int * boardData);
int playGame();
int updateBoardData(int * boardData, int x, int y, int XorO);
int checkWin(int * boardData);