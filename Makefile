all:
	gcc -Wall -ansi main.c tictactoefunctions.c -Iinclude -o run -lncurses
