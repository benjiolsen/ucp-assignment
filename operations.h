/*
Created by: Benjamin Olsen
Student Number: 19481681
Purpose: To act as the header file for the operations file. Contains the struct for
         the position, the function prototypes and also the definition of PI, so that
         the conversion to radians is easier. (Also contains various includes)
*/
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

/* A struct used to hold the position of the cursor in double form, allowing for
   easy passing through to the required functions, and easy use */
typedef struct
{
    double x1,x2,y1,y2;
}Position;

/* Iterates through a string and converts each lowercase letter to an
   uppercase letter by shifting the ASCII value down */
void upperCase(char* string);
/* Runs through the commands and validates them to ensure they are the correct
   commands, adn their values are in the correct range and datatype */
int test(LinkedList* list);
/* Takes in the data to be printed to the screen, ensures its valid, and then prints
   them to the screen */
void plotter(void *plotData);
/* Uses the known formula to convert from degrees to radians, modifying the actual
   pointer, rather than returning a value */
void radians(double* degrees);
/* Rounds a double to the nearest integer value */
int round(double value);
/* Edits the current angle depending on the input angle */
void rotate(double* curAngle,double newAngle);
/* Runs through the commands and then executes them depending on what needs to be
   done */
int execute(LinkedList* list);
/* Runs the needed calculations (dcos(theta)) and (dsin(theta)) for x and y
   whilst preserving the previous position */
void distance(Position* pos,double angle,double dist);

#endif
