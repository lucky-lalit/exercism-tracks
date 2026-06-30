#include "rotational_cipher.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char *rotate(const char *text, int shift_key)
{
    int len = strlen(text);
    char *copy = malloc(len + 1);
    // printf("%i\n",len);
    // printf("debug 0 %s\n",text);
    // printf("%i\n",shift_key);
    for (int i = 0; i < len; i++)
    {
        if(isalpha(text[i]))
        {
            if(isupper(text[i]))
                copy[i] = ((text[i] - 65 + shift_key ) % 26 + 65);
            else
                copy[i] = ((text[i] - 97 + shift_key ) % 26 + 97);
        }
        else
            copy[i] = text[i];
    }
    copy[len] = '\0';
    return copy;
    
}