#include "raindrops.h"
#include <stdio.h>
#include <string.h>

void convert(char result[], int drops)
{
    // printf("debug 0 %c\n",result[0]);
    // printf("debug 1 %i\n",drops);
    if (drops % 3 != 0 && drops % 5 != 0 && drops % 7 != 0)
    {
        sprintf(result,"%i",drops);
        return;
    }
    if (drops % 3 == 0)
        strcpy(result,"Pling");
    if (drops % 5 == 0)
        strcat(result,"Plang");
    if (drops % 7 == 0)
        strcat(result,"Plong");
    return;
}