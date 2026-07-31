#include "rail_fence_cipher.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *encode(char *text, size_t rails)
{
    printf("%li\n",rails);
    printf("%s\n",text);
    // bool direction  = true;
    int len = strlen(text);
    char *result = malloc(len + 1);
    int array[len];
    bool direction = true;
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (direction)
        {
            array[i] = count;
            if (count + 1 >= (int)rails)
            {direction = false;
             count--;
            }
            else
                count++;
        }
        else{
            array[i] = count;
            if (count  == 0)
            {direction = true;
             count++;
            }
            else
                count--;
        }
    }
    int index = 0;
    for (int i = 0; i < (int)rails; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (i == array[j])
            {
                result[index] = text[j];
                index++;
            }
        }
    }
    result[index] = '\0';
    printf("final result %s\n",result);
    
    return result;
}

char *decode(char *ciphertext, size_t rails)
{
    printf("%li\n",rails);
    printf("%s\n",ciphertext);
       printf("%li\n",rails);
    printf("%s\n",ciphertext);
    // bool direction  = true;
    int len = strlen(ciphertext);
    char *result = malloc(len + 1);
    int array[len];
    bool direction = true;
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (direction)
        {
            array[i] = count;
            if (count + 1 >= (int)rails)
            {direction = false;
             count--;
            }
            else
                count++;
        }
        else{
            array[i] = count;
            if (count  == 0)
            {direction = true;
             count++;
            }
            else
                count--;
        }
    }
    int index = 0;
    for (int i = 0; i < (int)rails; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (i == array[j])
            {
                result[j] = ciphertext[index];
                index++;
            }
        }
    }
    result[index] = '\0';
    printf("final result %s\n",result);
    
    return result;
}