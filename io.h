#ifndef IO_H
#define IO_H

#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void readLines(LinkedList* list,char* filename);
char* stringDupe(char* source);
void insertFirst(LinkedList* list,void *inData);

#endif
