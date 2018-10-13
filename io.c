#include "io.h"

void readLines(LinkedList* list,char* filename)
{
    FILE* plotdata = NULL;
    char buffer[BUFFER_SIZE];
    char* line;

    plotdata = fopen(filename,"r");
    if(plotdata==NULL)
    {/* Handles the file not existing problem */
        perror("There was an error opening the file");
    }
    else if(ferror(plotdata))
    {/* Checks if file is okay to use */
        perror("There was an error with the file");
    }
    else
    {
        if(fgets(buffer,BUFFER_SIZE,plotdata)!=NULL)
        {/* Attempts to read in the first line, if it cant, runs the else */
            do
            {/* Loops through the file, reading the lines into a stack array
                then mallocs them */
                line = stringDupe(buffer);
                insertFirst(list,line);
            }
            while(fgets(buffer,BUFFER_SIZE,plotdata)!=NULL);
            /* Cant leave the file being a dangly boi */
            fclose(plotdata);
        }
        else
        {
            /* fprintf because i dont like it saying Error:Success with
               perror */
            fprintf(stderr,"There was no data in the file\n");
            /* also close the dangly boi */
            fclose(plotdata);
        }
    }


}

char* stringDupe(char* source)
{
    char *dest;
    dest = (char*)malloc((strlen(source)+1)*sizeof(char));
    if(dest != NULL)
    {/* Pray to god malloc doesnt fail */
        strcpy(dest,source);
    }
    return dest;
}
