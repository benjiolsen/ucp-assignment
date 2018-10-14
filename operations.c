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
    length = getLength(list);
    int ii, length = getLength(list);
    for(ii=0;ii<length;ii++)
    {

    }
}

int test(LinkedList* list)
{
    int correct = FALSE;
    return correct;
}
