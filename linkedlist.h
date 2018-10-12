#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
    char* data;
    struct ListNode* next;
    struct ListNode* prev;
} ListNode;

typedef struct{
    ListNode* head;
    ListNode* tail;
} LinkedList;

LinkedList* makeEmpty();
void insertFirst(LinkedList* list,void *inData);
int getLength(LinkedList* list);
int lengthRecurse(ListNode* cur);
void deleteFirst(LinkedList* list);
void freeList(LinkedList* list);
void freeRecurse(ListNode* cur);
void insertLast(LinkedList* list, void *inData);
void deleteLast(LinkedList* list);

#endif
