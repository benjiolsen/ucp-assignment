#ifndef OPERATIONS_H
/* Header Guard */
#define OPERATIONS_H

/* Why the FLIP is this not in the FLIPPING math library */
/* C89 is where its at bois */
/* Defines the known mathematical constant, pi, to 4 decimal places */
#define PI 3.1415

#include <math.h>

/* Defines the struct to hold command and its value, along with the pattern
   that it would correspond to */
typdef struct
{
    char* operation;
    char pattern[1];
    void* value;
    int x1,x2,y1,y2;
}Commands;

/* Iterates through a string and converts each lowercase letter to an
   uppercase letter by shifting the ASCII value down */
void upperCase(char* string);

/* Will run through the commands and ensure each one entered was valid */
int test(LinkedList* list);

#endif
