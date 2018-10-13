#ifndef IO_H
/* Header Guard */
#define IO_H

/* For the buffer stack string */
/* Please dont hurt me with a really long string :( */
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/* Reads the lines into a linked list, creating a string of the right size
   and sending that to insertLast */
void readLines(LinkedList* list,char* filename);
/* Duplicates the stack string into a malloced string so that I could use
   pointers easier */
char* stringDupe(char* source);

#endif
