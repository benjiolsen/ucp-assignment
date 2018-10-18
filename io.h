/*
Created by: Benjamin Olsen
Student Number: 19481681
Purpose: To act as the header file for the file IO file. Contains the function
         prototypes and the definition of the max buffer size, and the various
         needed includes
*/
#ifndef IO_H
/* Header Guard */
#define IO_H

/* Defines a max size of 1024 characters for the file IO buffer string */
/* Please dont hurt me with a really long string :( */
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "graphics.h"
#include "operations.h"

/* Reads the lines into a linked list, creating a string of the right size
   and sending that to insertLast */
int readLines(LinkedList* list,char* filename);
/* Duplicates a string to a new heap allocated string. I use this so i can use a
   string of smaller size, rather than the buffered size stack string in my ll */
char* stringDupe(char* source);
/* Handles the creation/appending to a logfile for the graphics.log */
int commandLog(LinkedList* list);

#endif
