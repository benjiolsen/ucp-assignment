#include "graphics.h"
int main(int argc,char** argv)
{
    if(argc==2)
    {/* Ensures no funny buisness is put in */
        start(argv[1]);
    }
    else
    {/* Tells you off for being naughty */
        fprintf(stderr,"Please run as\n./graphics {filename}\n");
    }
    return 0;
}

void start(char* filename)
{
    int length;
    LinkedList* list = NULL;
    list = makeEmpty();

    readLines(list,filename);
    length = getLength(list);

    /*if(test(list)==TRUE)
    {
        upperCase(list);
    }
    else
    {
        fprintf(stderr,"Please ensure the file has the correct commands\n");
    }*/
    
    freeList(list);
}

void upperCase(LinkedList* list)
{
    int ii = 0;
    int length = 0;
    ListNode* temp = list->head;

    while(temp->next!=NULL)
    {
        length = strlen(temp->data) - 1;
        for(ii=0;ii<length;ii++)
        {
            if(temp->data[ii] <= 122 && temp->data[ii] >= 97)
            {/* If it is a lowercase letter, make it uppercase */
                temp->data[ii] = temp->data[ii] - 32;
            }
        }

        temp = temp->next;
    }
    temp = NULL;
}

int test(LinkedList* list)
{
    int correct = FALSE;
    return correct;
}
