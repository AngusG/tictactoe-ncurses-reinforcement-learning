/* Copyright (C) 2013-2016 Angus Galloway
 * angus.galloway.ca@ieee.org
 * 
 * This file is part of tictactoe-ncurses
 *
 * tictactoe-ncurses is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * tictactoe-ncurses is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 */
 
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