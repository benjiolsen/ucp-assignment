#include "operations.h"

int round(double value)
{/* I have seen this done in less code, but i understand my way better */
    int num;
    if(value >= 0)
    {/* If the number is positive, adding .5 and truncing will put it to the
        nearest whole value */
        num = (int)(value + 0.5);
    }
    else
    {/* ditto but negative and -.5 */
        num = (int)(value - 0.5);
    }
    return num;
}

void radians(double* degrees)
{/* RAD = DEG * PI/180 ezpz*/
    degrees = ( degrees * (PI/180) );
}

Plotfunc plotter(void *plotData)
{
    if(((char*)plotdata == plotdata)&&(plotData != NULL))
    {
        printf("%c",(char*)plotData);
    }
}

Commands* extract(LinkedList list)
{
    int ii, length = getLength(list);
    char* number;
    char *string, *pattern;
    Commands* commands = NULL;
    ListNode cur = list->head;

    commands = (Commands*)malloc(length*sizeof(Commands));
    while(sscanf(list->data,"%s %s",&string,&number)!=NULL)
    {
        upperCase(string);
        if(strcmp(string,"PATTERN"))
        {
            strcpy(number,pattern)
        }
        else
        {
            strcpy(commands[ii]->Operation,string);
        }

        ii++;
    }
}

int test(Commands* commands)
{
    char move[] = "MOVE";
    char rotate[] = "ROTATE";
    char draw[] = "DRAW";
    char fg[] = "FG";
    char bg[] = "BG";
    char pattern[] = "PATTERN";
    int correct = FALSE;

    do
    {

    }while();

    return correct;
}

void upperCase(char* string)
{
    int ii = 0;
    int length = 0;

    length = strlen(string);
    for(ii=0;ii<length;ii++)
    {
        if(string[ii] <= 122 && string[ii] >= 97)
        {/* If it is a lowercase letter, make it uppercase */
            string[ii] = string[ii] - 32;
        }
    }
}
