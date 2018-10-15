#ifndef OPERATIONS_H
/* Header Guard */
#define OPERATIONS_H

/* Why the FLIP is this not in the FLIPPING math library */
/* C89 is where its at bois */
/* Defines the known mathematical constant, pi, to 4 decimal places */
#define PI 3.1415

#include <math.h>
#include "linkedlist.h"
#include "graphics.h"
#include "effects.h"
#include "io.h"

typedef struct
{
    int x1,x2,y1,y2;
}Position;

/* Iterates through a string and converts each lowercase letter to an
   uppercase letter by shifting the ASCII value down */
void upperCase(char* string);

/* Will run through the commands and ensure each one entered was valid */
int test(LinkedList* list);
/* Plots the pattern across the screen */
void plotter(void *plotData);
/* Converts degrees to radians for sin and cos */
void radians(double* degrees);
/* Rounds a double to the nearest integer value */
int round(double value);

#endif
