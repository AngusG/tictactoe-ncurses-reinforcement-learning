all:
	gcc -Wall -ansi main.c tictactoefunctions.c -Iinclude -o tictactoe -lncurses

clean:
	rm tictactoe
