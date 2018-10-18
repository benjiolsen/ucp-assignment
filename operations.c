/*
Created by: Benjamin Olsen
Student Number: 19481681
Purpose: To act as the file containing all various operations other than file
         I/O that the program needs, ranging from simple rotation, all the way
         through to validation of the incoming commands. This is the file which
         calls the effects.c functions such as line, and clearScreen etc. etc.
*/
#include "operations.h"
void rotate(double* curAngle,double newAngle)
{
    *curAngle = *curAngle - newAngle;
}

void distance(Position* pos,double angle,double dist)
{
    /* Ensures the current position is kept */
    pos->x1 = pos->x2;
    pos->y1 = pos->y2;
    /* Updates the position based upon the old position */
    pos->x2 = pos->x1 + ( dist * (cos(angle)) );
    pos->y2 = pos->y1 + ( dist * (sin(angle)) );
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
    Position* pos = (Position*)malloc(sizeof(Position));
    LinkedList* logList = NULL;
    char pattern = '+';
    char logString[BUFFER_SIZE],*value,*command;
    double dist = 0.0;
    int valid = TRUE;
    double angle = 0.0;
    double newAngle = 0.0;

    logList = makeEmpty();

    pos->x1 = 0.0;
    pos->x2 = 0.0;
    pos->y1 = 0.0;
    pos->y2 = 0.0;
    cur = list->head;

    /* Set up */
    clearScreen();
    setFgColour(7);
    setBgColour(0);

    do
    {/* Runs through the commands executing their values */
        if(strcmp(cur->command,"MOVE")==0)
        {
            /* Moves the cursor but doesnt print */
            dist = atof(cur->value)-1.0;
            distance(pos,angle,1.0);
            distance(pos,angle,dist);
            /* Outputs the effect of the move into a string, then into a
               Linked List */
            sprintf(logString,"%4s (%07.3f,%07.3f)-(%07.3f,%07.3f)\n",
                                                            cur->command,
                                                            pos->x1,pos->y1,
                                                            pos->x2,pos->y2);
            value = stringDupe(" ");
            command = stringDupe(logString);
            /* If the mode is debug, it will print it out along side the
               regular printing */
            #ifdef DEBUG
            fprintf(stderr,"%s",logString);
            #endif
            insertFirst(logList,command,value);
        }
        else if(strcmp(cur->command,"DRAW")==0)
        {
            /* Moves the cursor and draws a line accordingly */
            dist = atof(cur->value) - 1.0;
            distance(pos,angle,1.0);
            distance(pos,angle,dist);
            line(round(pos->x1),round(pos->y1),round(pos->x2),
                 round(pos->y2),&plotter,&pattern);
            /* Outputs the effect of the move into a string, then into a
               Linked List */
            sprintf(logString,"%4s (%07.3f,%07.3f)-(%07.3f,%07.3f)\n",
                                                            cur->command,
                                                            pos->x1,pos->y1,
                                                            pos->x2,pos->y2);
            value = stringDupe(" ");
            command = stringDupe(logString);
            /* If the mode is debug, it will print it out along side the
               regular printing */
            #ifdef DEBUG
            fprintf(stderr,"%s",logString);
            #endif
            insertFirst(logList,command,value);
        }
        else if(strcmp(cur->command,"ROTATE")==0)
        {
            /* Converts each angle to the radian value and then edits the
               current angle depending on the new angle */
            newAngle = atof(cur->value);
            radians(&newAngle);
            rotate(&angle,newAngle);
        }
        /* If the simple version isnt run, the colours will behave as normal,
           otherwise they will take on the default value */
        #ifndef SIMPLE
        else if(strcmp(cur->command,"FG")==0)
        {
            setFgColour(round(atoi(cur->value)));
        }
        else if(strcmp(cur->command,"BG")==0)
        {
            setBgColour(round(atoi(cur->value)));
        }
        #endif

        else if(strcmp(cur->command,"PATTERN")==0)
        {
            pattern = cur->value[0];
        }

        cur = cur->next;
    }while(cur!=NULL&&valid == TRUE);

    if(commandLog(logList)==TRUE)
    {/* Prints to the log file, or tells the user of their error */
        fprintf(stderr,"There was an error with the logfile!\n");
    }

    freeList(logList);
    penDown();
    free(pos);
    return valid;
}

void radians(double* degrees)
{/* RAD = DEG * PI/180 ezpz*/
    *degrees = ( (*degrees) * (PI/180) );
}

void plotter(void *plotData)
{
    if(((char*)plotData == plotData)&&(plotData != NULL))
    {/* Ensures the data is infact a string, and isnt null
        then prints */
        printf("%s",(char*)plotData);
    }
}

int test(LinkedList* list)
{
    /* Uses a node that changes where it points to, to move through the list */
    ListNode* cur = list->head;
    /* These strings are used to make sure the commands are valid */
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
        {/* Ensures the input command matches one of the specified ones */
            if(strcmp(cur->command,rotate)==0)
            {
                if(atof(cur->value)>360.0||atof(cur->value)<0.0)
                {/* As per specification */
                    correct = FALSE;
                }
            }
            if(strcmp(cur->command,fg)==0)
            {
                if(atoi(cur->value)<0||atoi(cur->value)>15)
                {/* As per specification */
                    correct = FALSE;
                }
            }
            if(strcmp(cur->command,bg)==0)
            {
                if(atoi(cur->value)<0||atoi(cur->value)>7)
                {/* As per specification */
                    correct = FALSE;
                }
            }
            if(strcmp(cur->command,pattern)==0)
            {
                if(strcmp(cur->value," ")==0)
                {/* As per specification */
                    correct = FALSE;
                }
            }
        }
        else
        {/* If it matches none of the commands, the file is invalid, print an
            error */
            correct=FALSE;
        }
        /* Points to the next node */
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
