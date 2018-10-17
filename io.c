#include "io.h"

int readLines(LinkedList* list,char* filename)
{
    FILE* plotdata = NULL;
    char buffer[BUFFER_SIZE];
    char *command,*value;
    int failed = FALSE;
    int line = 1;

    command = malloc(BUFFER_SIZE*sizeof(char));
    value = malloc(BUFFER_SIZE*sizeof(char));
    plotdata = fopen(filename,"r");
    if(plotdata==NULL)
    {/* Handles the file not existing problem */
        perror("There was an error opening the file");
        failed = TRUE;
    }
    else if(ferror(plotdata))
    {/* Checks if file is okay to use */
        perror("There was an error with the file");
        failed = TRUE;
        fclose(plotdata);
    }
    else
    {
        if(fgets(buffer,BUFFER_SIZE,plotdata)!=NULL)
        {/* Attempts to read in the first line, if it cant, runs the else */
            do
            {
                if(sscanf(buffer,"%s %s",command,value)==2)
                {
                    upperCase(command);
                    insertLast(list,stringDupe(command),stringDupe(value));
                }
                else
                {
                    failed = TRUE;
                    fprintf(stderr,"Error on line %d, not in proper format\n",line);
                }
                line++;
            }while((failed == FALSE) && fgets(buffer,BUFFER_SIZE,plotdata)!=NULL);
            /* Cant leave the file being a dangly open boi */
            fclose(plotdata);
        }
        else
        {
            /* fprintf because i don't like it saying Error:Success with
               perror */
            fprintf(stderr,"There was no data in the file\n");
            failed = TRUE;
            /* also close the dangly open boi */
            fclose(plotdata);
        }
    }
    free(command);
    free(value);
    return failed;
}

int commandLog(LinkedList* list)
{
    FILE* logFile = NULL;
    ListNode* cur = NULL;
    int failed = FALSE;

    logFile = fopen("graphics.log","a");
    cur = list->head;

    if(logFile==NULL)
    {/* Handles the file not existing problem */
        perror("There was an error opening the log file");
        failed = TRUE;
    }
    else if(ferror(logFile))
    {/* Checks if file is okay to use */
        perror("There was an error with the log file");
        fclose(logFile);
        failed = TRUE;
    }
    else
    {
        if(fputs("---\n",logFile)!=EOF)
        {/* As per the spec, appends the file beginning with --- */
            do
            {/* Loops through the list until its empty */
                fputs(cur->command,logFile);
                cur = cur->next;
            }while(cur!=NULL);
            /* Cant forget to close this dangley boi */
            fclose(logFile);
        }
        else
        {
            fprintf(stderr,"There was an error writing to the file\n");
            failed = TRUE;
            fclose(logFile);
        }
    }
    return failed;
}

char* stringDupe(char* source)
{
    char *dest;
    dest = (char*)malloc((strlen(source)+1)*sizeof(char));
    /* Mallocs the new string */
    if(dest != NULL)
    {/* Pray to god malloc doesnt fail */
        strcpy(dest,source);
    }
    return dest;
}
