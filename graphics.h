/*
Created by: Benjamin Olsen
Student Number: 19481681
Purpose: To act as the header file for the main graphics file. Includes the
         definition of true and false which is used throughout the program
         and also the function prototypes and includes needed
*/
#ifndef GRAPHICS_H
/* Header Guard */
#define GRAPHICS_H

/* General definition of true and false if needed in the program
   (Used to allow for simple returns and such) */
#define TRUE 0
#define FALSE !TRUE

#include "io.h"
#include "linkedlist.h"
#include "effects.h"

/* Is the start of the program, and does the inital work of calling functions
   and setting up the linked list */
void start(char* filename);

#endif
