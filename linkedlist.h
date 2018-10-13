/*
Created by: Benjamin Olsen
Student Number: 19481681
Purpose: To act as the header file for the linked list file. Contains the
         stucts and typedefs for the linked lists, and the prototypes for the
         needed functions
*/
#ifndef LINKEDLIST_H
/* Header Guard */
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Acts as the nodes for the list, holding the data and pointing to the
   next node in the list (and the previous) */
typedef struct ListNode
{
    char* data;
    struct ListNode* next;
    struct ListNode* prev;
} ListNode;

/* Acts to hold/point to the head and tail of the linked list
   and allows the list to be used easier and nicer
   (double ended doubly linked                                 */
typedef struct
{
    ListNode* head;
    ListNode* tail;
} LinkedList;

/* Creates and returns a pointer to an empty linked list */
LinkedList* makeEmpty();
/* Inserts an item into the front of a linked list, doing the checking and
   possible shuffling needed */
void insertFirst(LinkedList* list,void *inData);
/* Acts to call the lengthRecurse module to recusively get the length of the
   list by traversing through it */
int getLength(LinkedList* list);
/* Recusively calls itself to find the length of the list */
int lengthRecurse(ListNode* cur);
/* Deletes the item which is the head of the list, freeing it and removing
   all the pointers to it */
void deleteFirst(LinkedList* list);
/* Acts to free each item in the list, and then eventually the list itself
   by using the recusive call */
void freeList(LinkedList* list);
/* Recusively calls itself, freeing each node as it goes */
void freeRecurse(ListNode* cur);
/* Inserts the item at the tail of the list */
void insertLast(LinkedList* list, void *inData);
/* Deletes the item at the tail of the list */
void deleteLast(LinkedList* list);

#endif
