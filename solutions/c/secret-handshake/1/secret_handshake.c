#include "secret_handshake.h"
#include <stdio.h>
#include <stdlib.h>
const char **commands(size_t number)
{
    int temp_arr[5] = {0};
    // int count = 0;
    printf("number %li\n",number);
    for (int i = 0; i < 5; i++)
    {
        temp_arr[5 - (i + 1)] = number % 2;
        number = number / 2;
        if (number == 0)
            break;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%i\n",temp_arr[i]);
    }
    const char **temp_char = malloc(4 * (sizeof(char *)));
    for (int i = 0; i < 4; i++)
    {
        temp_char[i] = NULL;
    }
    int index = 0;
    if (temp_arr[4] == 1)
    {
        temp_char[index] = "wink";
        index++;
    }
    if (temp_arr[3] == 1)
    {
        temp_char[index] = "double blink";
        index++;
    }
    if (temp_arr[2] == 1)
    {
        temp_char[index] = "close your eyes";
        index++;
    }
    if (temp_arr[1] == 1)
    {
        temp_char[index] = "jump";
        index++;
    }
    if(temp_arr[0] == 1)
    {
        const char *temp  = temp_char[0];
        if (index == 4)
        {
        temp_char[0] = temp_char[3];
        temp_char[3] = temp;
        temp = temp_char[1];
        temp_char[1] = temp_char[2];
        temp_char[2] = temp;
        }
        if (index ==  1)
            return temp_char;
        if (index == 2)
        {
            temp_char[0] = temp_char[1];
            temp_char[1] = temp;
        }
        if (index == 3)
        {
            temp_char[0] = temp_char[2];
            temp_char[2] = temp;
        }
    }
    return temp_char;  
}