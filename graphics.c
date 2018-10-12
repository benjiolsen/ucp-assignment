#include "graphics.h"
int main(int argc,char** argv)
{
    if(argc==2)
    {
        start(argv[1]);
    }
    else
    {
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
    char* string;
    ListNode* temp = list->head;

    while(temp->next!=NULL)
    {
        string = (char*)temp->data;
        length = strlen(string) - 1;
        for(ii=0;ii<length;ii++)
        {
            if(string[ii] <= 122 && string[ii] >= 97)
            {
                string[ii] = string[ii] - 32;
            }
        }

        temp = temp->next;
    }
    temp = NULL;
    string = NULL;
}

int test(LinkedList* list)
{
    int correct = FALSE;
    return correct;
}
