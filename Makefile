CC=gcc
CFLAGS= -Wall -pedantic -ansi -g -c
MATH= -lm
OBJ= linkedlist.o io.o graphics.o
OUT=graphics

default: TurtleGrahpics
TurtleGrahpics: $(OBJ)
	$(CC) $(OBJ) -o $(OUT)

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) linkedlist.c
io.o: io.c io.h linkedlist.h
	$(CC) $(CFLAGS) io.c
graphics.o: graphics.c graphics.h io.h linkedlist.h
	$(CC) $(CFLAGS) graphics.c

clean:
	rm *.o graphics
	clear
