CC=gcc
CFLAGS= -Wall -pedantic -ansi -g -c
MATH= -lm
OBJ= linkedlist.o io.o graphics.o operations.o effects.o
OUT=graphics

default: TurtleGrahpics
TurtleGrahpics: $(OBJ)
	$(CC) $(OBJ) $(MATH) -o $(OUT)

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) linkedlist.c
io.o: io.c io.h linkedlist.h graphics.h operations.h
	$(CC) $(CFLAGS) io.c
graphics.o: graphics.c graphics.h io.h linkedlist.h effects.h
	$(CC) $(CFLAGS) graphics.c
operations.o: operations.c operations.h linkedlist.h graphics.h effects.h io.h
	$(CC) $(CFLAGS) operations.c
effects.o: effects.c effects.h
	$(CC) $(CFLAGS) effects.c

clean:
	rm *.o graphics
	clear
