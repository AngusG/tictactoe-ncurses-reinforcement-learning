#include <ncurses.h>
#include "tictactoe.h"

void initCurses() {

	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
}

/* Draw game grid */
void drawBoard() {

	int i, h;

	for(i=0;i<=6;i++) {
		mvaddch(i, 0, '|');
		mvaddch(i, 4, '|');
		mvaddch(i, 8, '|');
		mvaddch(i, 4, '|');
		mvaddch(i, 8, '|');
		mvaddch(i, 12,'|');

		if(i%2 == 0){
			for(h=0;h<=12;h++) {
				mvaddch(i, h, '-');
			}
		}
		move(1,2);
	}
	refresh();
}

void initBoard(int * boardData){

	int i;

	for(i=0; i<=8;i++){
		boardData[i] = i+2;
	}
}

/**********************************************
 *
 *
 ********************************/
int playGame() {

	int boardData[9];
	int playerNum = 1;
	int inputChar;
	int x = 2, y = 1;
	int didWin = 0;
	int canWeMove = 0;
	int nMoves = 0;

	initBoard(boardData);

	/* Move to y=8, x = 0 */
	mvprintw(8, 0, "It is Player 1's turn to place an (X)");
	move(y, x); /* move to origin */
	refresh();

	while (inputChar != 'q') {

		if(nMoves == 9) {
			mvprintw(10, 0, "Tie game");
			inputChar = getch();
			erase();
			return 3;
		}
		inputChar = getch();

		/* If not spacebar, they are moving */
		if(inputChar != ' '){

			switch (inputChar){

				case KEY_UP:
					if(y == 3 || y == 5){
						move(y-=2, x);
					}
					break;

				case KEY_DOWN:
					if(y == 1 || y == 3){
						move(y+=2, x);
					}
					break;

				case KEY_LEFT:
					if(x == 10 || x == 6){
						move(y, x-=4);
					}
					break;
				case KEY_RIGHT:
					if(x == 2 || x == 6){
						move(y, x+=4);
					}
					break;											
			}
		}

		else if(playerNum == PLAYER_1 && inputChar == ' '){

			getyx(stdscr, y, x);
			canWeMove = updateBoardData(boardData, x, y,1);

			if(canWeMove == OKAY) {

				mvaddch(y, x, 'X');

				/* Returns 1 if last move caused winning scenario */
				didWin = checkWin(boardData);

				if(didWin){

					mvprintw(10,0, "Player 1 wins");
					inputChar = getch();
					erase();
					return TRUE;
				}
				nMoves += 1;

				playerNum = 2;
				mvprintw(8, 0, "It is Player 2's turn to place an (O)");
				move(y, x);
				/*refresh();*/

			}
		}
		else if(playerNum == PLAYER_2 && inputChar == ' ') {

			getyx(stdscr, y, x);
			canWeMove = updateBoardData(boardData, x, y,0);

			if(canWeMove == OKAY) {

				mvaddch(y, x, 'O');

				/* Returns 1 if last move caused winning scenario */
				didWin = checkWin(boardData);

				if(didWin){

					mvprintw(10,0, "Player 2 wins");
					inputChar = getch();
					erase();
					return TRUE;
				}
				nMoves += 1;

				playerNum = 1;
				mvprintw(8, 0, "It is Player 1's turn to place an (X)");
				move(y, x);
				/*refresh();*/
			}
		}
		refresh();
	}
	return FALSE;
	endwin();

}

int updateBoardData(int * boardData, int x, int y, int XorO) {

	/* Check row 1*/
	if(y == 1){
		if(x == 2){
			if(boardData[0] > 1){
				boardData[0] = XorO;
				return OKAY;
			}
		}
		else if( x == 6){	
			if(boardData[1] > 1){
				boardData[1] = XorO;
				return OKAY;
			}
		}
		else if( x == 10){
			if(boardData[2] > 1){
				boardData[2] = XorO;
				return OKAY;
			}				
		}
	} 

	/* Check row 2 */
	else if(y == 3){
		if(x == 2){
			if(boardData[3] > 1){
				boardData[3] = XorO;
				return OKAY;
			}
		}	
		else if( x == 6){	
			if(boardData[4] > 1){
				boardData[4] = XorO;
				return OKAY;
			}
		}
		else if( x == 10){
			if(boardData[5] > 1){
				boardData[5] = XorO;
				return OKAY;
			}
		}
	}

	/* Check row 3*/
	else if(y == 5){			
		if(x == 2){
			if(boardData[6] > 1){
				boardData[6] = XorO;
				return OKAY;
			}
		}
		else if( x == 6){
			if(boardData[7] > 1){
				boardData[7] = XorO;
				return OKAY;
			}
		}
		else if( x == 10){
			if(boardData[8] > 1){
				boardData[8] = XorO;
				return OKAY;
			}
		}
	}
	return FALSE;		
}

int checkWin(int * boardData) {

	/* Check rows */
	if( boardData[0] == boardData[1] && boardData[1] == boardData[2] )
		return TRUE;
	else if( boardData[3] == boardData[4] && boardData[4] == boardData[5] )
		return TRUE;	
	else if( boardData[6] == boardData[7] && boardData[7] == boardData[8] )
		return TRUE;

	/* Check cols */
	else if( boardData[0] == boardData[3] && boardData[3] == boardData[6] )
		return TRUE;
	else if( boardData[1] == boardData[4] && boardData[4] == boardData[7] )
		return TRUE;
	else if( boardData[2] == boardData[5] && boardData[5] == boardData[8] )
		return TRUE;

	/* Check diagonals */
	else if( boardData[0] == boardData[4] && boardData[4] == boardData[8] )
		return TRUE;
	else if( boardData[2] == boardData[4] && boardData[4] == boardData[6] )
		return TRUE;

	else
		return FALSE;

}