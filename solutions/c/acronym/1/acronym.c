#include "acronym.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *abbreviate(const char *phrase)
{   
    if (phrase == NULL)
        return NULL;
    int len = strlen(phrase);
    if (len == 0)
        return NULL;
    
    // printf("%s\n",phrase);
    char *temp = malloc(26);
    int count = 0; 
    for (int i = 1; i <= len; i++)
    {
        if (i == 1)
            temp[count] = toupper(phrase[0]);
        if (phrase[i - 1] == ' ' || phrase[i - 1] == '-' || phrase[i - 1] == '_')
        {
            if (isalpha(phrase[i]))
            {
                count++;
                temp[count] = toupper(phrase[i]);
            }
        }
            
    }
    temp[count + 1] = '\0';
    return temp;
}
