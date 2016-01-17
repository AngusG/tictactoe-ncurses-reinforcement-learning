#include <ncurses.h>
#include "tictactoe.h"

int main() {

	int keepPlaying;

	do {

		initCurses();
		drawBoard();
		/* playGame(); */
		keepPlaying = playGame();

	} while (keepPlaying);

	endwin();

	return(0);
}