#ifndef GRAPHICS_H
#define GRAPHICS_H
#define TRUE 0
#define FALSE !TRUE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "io.h"
#include "linkedlist.h"

void upperCase(LinkedList* list);
void start(char* filename);
int test(LinkedList* list);

#endif
