#include "reverse_string.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *reverse(const char *value)
{
    int len = strlen(value);
    // if (len == 0)
    // printf("%i\n",len);
    char *copy = malloc(1 + len);
    if (copy == NULL)
        return NULL;
    for (int i = 1; i <= len; i++)
    {
        // printf("%c\n", value[len - i]);
        copy[i - 1] = value[len - i];
        // printf("%c\n",copy[i]);
    }
    // free(copy);
    copy[len] = '\0';
    
    // free(copy);
    // printf("%s\n",copy);
    return copy;
}