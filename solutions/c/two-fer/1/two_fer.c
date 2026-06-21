#include "two_fer.h"
#include <stdio.h>
#include <string.h>

void two_fer(char *buffer, const char *name)
{
    // return;
    // printf("%s\n",buffer);
    // printf("%s\n",name);
    if (name == NULL)
    {
        strcpy(buffer,"One for you, one for me.");
        // buffer = "One for you, one for me.";
        // printf("One for you, one for me.");
        printf("%s",buffer);
        return;
    }
    else
        sprintf(buffer,"One for %s, one for me.",name);
    // printf("%s\n",buffer);
    // printf("%s\n",name);
    printf("%s",buffer);
    return;
}