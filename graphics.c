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
    /*int length;*/
    LinkedList* list = NULL;
    list = makeEmpty();
    if(readLines(list,filename) == FALSE)
    {

    }
    else
    {
        fprintf(stderr,"There was an erronous file\n");
    }
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
