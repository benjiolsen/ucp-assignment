#include "io.h"

void readLines(LinkedList* list,char* filename)
{
    FILE* plotdata = NULL;
    char buffer[BUFFER_SIZE];
    char* line;

    plotdata = fopen(filename,"r");
    if(plotdata==NULL)
    {
        perror("There was an error opening the file");
    }
    else if(ferror(plotdata))
    {
        perror("There was an error with the file");
    }
    else
    {
        if(fgets(buffer,BUFFER_SIZE,plotdata)!=NULL)
        {
            do
            {
                line = stringDupe(buffer);
                insertFirst(list,line);
            }
            while(fgets(buffer,BUFFER_SIZE,plotdata)!=NULL);
            fclose(plotdata);
        }
        else
        {
            fprintf(stderr,"There was no data in the file\n");
            fclose(plotdata);
        }
    }


}

char* stringDupe(char* source)
{
    char *dest;
    dest = (char*)malloc((strlen(source)+1)*sizeof(char));
    if(dest != NULL)
    {
        strcpy(dest,source);
    }
    return dest;
}
