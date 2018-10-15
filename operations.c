#include "operations.h"

double rotate(void* angle)
{

}

void distance(Position* pos,double angle,int dist)
{

}

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

int execute(LinkedList* list)
{
    ListNode* cur = NULL;
    Position* pos;
    char pattern = '+';
    char *empty = ' ';
    int distance,fg,bg;
    double value,angle = 0;
    cur = list->head;
    /*clearScreen();*/
    do
    {
        if(strcmp(cur->command,"MOVE")==0)
        {
            line(pos->x1,pos->y1,pos->x2,pos->y2,&plotter,empty);
        }
        else if(strcmp(cur->command,"DRAW")==0)
        {
            line(pos->x1,pos->y1,pos->x2,pos->y2,&plotter,&pattern);
        }
        else if(strcmp(cur->command,"ROTATE")==0)
        {

        }
        else if(strcmp(cur->command,"FG")==0)
        {
            if(atoi(cur->value)!=0)
            {
                setFgColour(atoi(cur->value));
            }
        }
        else if(strcmp(cur->command,"BG")==0)
        {
            if(atoi(cur->value)!=0)
            {
                setBgColour(atoi(cur->value));
            }
        }
        else if(strcmp(cur->command,"PATTERN")==0)
        {
            if(cur->value[0] == ' ')
            pattern = cur->value[0];
        }
        cur = cur->next;
    }while(cur!=NULL)
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
