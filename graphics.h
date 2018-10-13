#ifndef GRAPHICS_H
/* Header Guard */
#define GRAPHICS_H

/* General definition of true and false if needed in the program
   (Used to allow for simple returns and such) */
#define TRUE 0
#define FALSE !TRUE

#include <math.h>

#include "io.h"
#include "linkedlist.h"

/* Iterates through a string and converts each lowercase letter to an
   uppercase letter by shifting the ASCII value down */
void upperCase(LinkedList* list);
/* Is the start of the program, and does the inital work of calling functions
   and setting up the linked list */
void start(char* filename);
/* Will run through the COMMANDS and ensure each one entered was valid */
int test(LinkedList* list);

#endif
