#include "linkedlist.h"
LinkedList* makeEmpty()
{
    /* Creates the pointer, allocates the space, and ensures ther head and
       tail are null */
    LinkedList* list;

    list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;

    return list;
}

void insertFirst(LinkedList* list,void *inData)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

    newNode->data=inData;
    if(list->head==NULL)
    {/* If there isnt any values, the first is also the last */
        list->head = newNode;
        list->tail = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else
    {/* Otherwise, shuffle pointers */
        newNode->next=list->head;
        list->head->prev = newNode;
        newNode->prev=NULL;
        list->head=newNode;
    }
}

void insertLast(LinkedList* list, void *inData)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

    newNode->data=inData;
    if(list->head==NULL)
    {/* If the list is empty, the end is also the start */
        list->head = newNode;
        list->tail = newNode;
        newNode->next = NULL;
    }
    else
    {/* Otherwise, insert and point to it accordingly */
        newNode->prev=list->tail;
        list->tail->next=newNode;
        list->tail=newNode;
        newNode->next=NULL;
    }
}

int getLength(LinkedList* list)
{
    int length = 0;
    ListNode* cur;

    /* Uses a dummy variable to be able to loop through the list */
    cur = (list->head);
    length = lengthRecurse(cur);
    return length;
}

int lengthRecurse(ListNode* cur)
{
    int length = 0;
    if(cur!=NULL)
    {/* Please dont stack overflow <3 */
        length = 1 + lengthRecurse(cur->next);
    }
    return length;
}

void deleteFirst(LinkedList* list)
{
    ListNode* temp;

    if(list->head==NULL)
    {/* If the list is empty, nothing can be deleted */
        perror("The head was empty");
    }
    else if(list->head->next==NULL)
    {/* If the list has one element, remove the head and tail */
        free(list->head->data);
        list->head->data=NULL;
        free(list->head);
        list->head=NULL;
        list->tail=NULL;
    }
    else
    {/* Otherwise, just remove the head and shuffle it all down */
        temp = list->head->next;
        free(list->head->data);
        list->head->data = NULL;
        free(list->head);
        list->head=NULL;
        list->head = temp;
        list->head->prev=NULL;
    }
}

void deleteLast(LinkedList* list)
{
    ListNode* temp;
    if(list->head==NULL)
    {/* If the list is empty, nothing can be deleted */
        perror("The head was empty");
    }
    else if(list->head->next==NULL)
    {/* If the list has one item in it, remove both head and tail */
        free(list->head->data);
        list->head->data=NULL;
        free(list->head);
        list->head=NULL;
        list->tail=NULL;
    }
    else
    {/* Otherwise, remove the tail, and point the tail to the previous */
        temp = list->tail->prev;
        free(list->tail->data);
        list->tail->data = NULL;
        free(list->tail);
        list->tail=NULL;
        list->tail = temp;
        list->tail->next=NULL;
    }
}

void freeList(LinkedList* list)
{
    freeRecurse(list->head);
    free(list);
    list = NULL;
}
void freeRecurse(ListNode* cur)
{
    if(cur!= NULL)
    {/* Feels like you were here a second ago */
        /* Keeps calling until the end of the list, then frees all the
           data and pointers going back up! */
        freeRecurse(cur->next);
        free(cur->data);
        cur->data = NULL;
        free(cur);
        cur = NULL;
    }
}
