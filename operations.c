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
    *degrees = ( (*degrees) * (PI/180) );
}

void plotter(void *plotData)
{
    if(((char*)plotData == plotData)&&(plotData != NULL))
    {
        printf("%s",(char*)plotData);
    }
}

int test(LinkedList* list)
{
    ListNode* cur = list->head;
    char move[] = "MOVE";
    char rotate[] = "ROTATE";
    char draw[] = "DRAW";
    char fg[] = "FG";
    char bg[] = "BG";
    char pattern[] = "PATTERN";
    int correct = TRUE;

    do
    {
        if(strcmp(cur->command,move)==0 ||
           strcmp(cur->command,rotate)==0 ||
           strcmp(cur->command,draw)==0 ||
           strcmp(cur->command,fg)==0 ||
           strcmp(cur->command,bg)==0 ||
           strcmp(cur->command,pattern)==0)
        {

        }
        else
        {
            correct=FALSE;
        }
        cur = cur->next;
    }while(correct==TRUE&&cur!=NULL);
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
