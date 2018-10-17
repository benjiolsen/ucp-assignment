CC=gcc
CFLAGS= -Wall -pedantic -ansi -g -c -Werror
MATH= -lm
OBJ= linkedlist.o io.o graphics.o operations.o effects.o
OUT=TurtleGraphics
OUTDEBUG=TurtleGraphicsDebug
OUTSIMPLE=TurtleGraphicsSimple
DEBUG=-DDEBUG=1
SIMPLE=-DSIMPLE=1

default: TurtleGrahpics TurtleGraphicsDebug TurtleGraphicsSimple

TurtleGrahpics: $(OBJ)
	$(CC) $(OBJ) $(MATH) -o $(OUT)
TurtleGraphicsDebug: $(OBJ) debug.o
	$(CC) $(OBJ) $(MATH) -o $(OUTDEBUG)
TurtleGraphicsSimple: $(OBJ) simple.o
	$(CC) $(OBJ) $(MATH) -o $(OUTSIMPLE)

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
debug.o: operations.c operations.h linkedlist.h graphics.h effects.h io.h
	$(CC) $(CFLAGS) $(DEBUG) operations.c
simple.o: operations.c operations.h linkedlist.h graphics.h effects.h io.h
	$(CC) $(CFLAGS) $(SIMPLE) operations.c


clean:
	rm *.o $(OUT) $(OUTDEBUG) $(OUTSIMPLE)
	clear
