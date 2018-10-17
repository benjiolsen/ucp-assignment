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
    LinkedList* list = NULL;

    list = makeEmpty();
    if(readLines(list,filename) == FALSE)
    {
        if(test(list)==TRUE)
        {
            if(execute(list)==TRUE)
            {
            }
            else
            {
                fprintf(stderr,"There was an error executing the function");
            }
        }
        else
        {
            fprintf(stderr,"Please ensure the file has the correct commands\n");
        }
    }
    else
    {
        fprintf(stderr,"There was an erronous file\n");
    }


    freeList(list);
}
