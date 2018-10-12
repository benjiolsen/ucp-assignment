#include "linkedlist.h"
LinkedList* makeEmpty()
{
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
    {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next=list->head;
        list->head=newNode;
    }
}

void insertLast(LinkedList* list, void *inData)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data=inData;
    if(list->head==NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = NULL;
    }
    else
    {
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
    cur = (list->head);
    length = lengthRecurse(cur);
    return length;
}

int lengthRecurse(ListNode* cur)
{
    int length = 0;
    if(cur!=NULL)
    {
        length = 1 + lengthRecurse(cur->next);
    }
    return length;
}

void deleteFirst(LinkedList* list)
{
    ListNode* temp;
    if(list->head==NULL)
    {
        perror("The head was empty");
    }
    else if(list->head->next==NULL)
    {
        free(list->head->data);
        list->head->data=NULL;
        free(list->head);
        list->head=NULL;
        list->tail=NULL;
    }
    else
    {
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
    {
        perror("The head was empty");
    }
    else if(list->head->next==NULL)
    {
        free(list->head->data);
        list->head->data=NULL;
        free(list->head);
        list->head=NULL;
        list->tail=NULL;
    }
    else
    {
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
    {
        freeRecurse(cur->next);
        free(cur->data);
        cur->data = NULL;
        free(cur);
        cur = NULL;
    }
}
