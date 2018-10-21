#Created by: Benjamin Olsen
#Student Number: 19481681
#Purpose: To act as the makefile for the 2018 UCP assignment. Contains all the
#         specified targets, and makes use of make 'variables' to make
#         compilation easier

# Defines some macros so things such as all the gcc flags, dont have to be
# fully typed every time
CC=gcc
CFLAGS= -Wall -pedantic -ansi -g -c -Werror
MATH= -lm
OBJ= linkedlist.o io.o graphics.o operations.o effects.o
OUT=TurtleGraphics
OUTDEBUG=TurtleGraphicsDebug
OUTSIMPLE=TurtleGraphicsSimple
DEBUG=-DDEBUG=1
SIMPLE=-DSIMPLE=1

# Aims for each target for the regular, debug, and simple modes
default: TurtleGrahpics TurtleGraphicsDebug TurtleGraphicsSimple

TurtleGrahpics: $(OBJ)
	$(CC) $(OBJ) $(MATH) -o $(OUT)
TurtleGraphicsDebug: $(OBJ) debug.o
	$(CC) $(OBJ) $(MATH) -o $(OUTDEBUG)
TurtleGraphicsSimple: $(OBJ) simple.o
	$(CC) $(OBJ) $(MATH) -o $(OUTSIMPLE)
	rm operations.o

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
# Creates the object file which has debug defined for the stderr log output
debug.o: operations.c operations.h linkedlist.h graphics.h effects.h io.h
	$(CC) $(CFLAGS) $(DEBUG) operations.c
# Creates the object file which has simple defined for the basic colour output
simple.o: operations.c operations.h linkedlist.h graphics.h effects.h io.h
	$(CC) $(CFLAGS) $(SIMPLE) operations.c

# Cleans up everything and makes it look good
clean:
	rm *.o $(OUT) $(OUTDEBUG) $(OUTSIMPLE)
	clear
