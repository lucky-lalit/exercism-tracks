#include "atbash_cipher.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *atbash_encode(const char *input)
{
    // printf("%c\n",input[0]);
    char *reverse_arr = "zyxwvutsrqponmlkjihgfedcba";
    int len = strlen(input);
    char *encoded = malloc(len * len);
    int index = 0;
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalnum(input[i]))
        {
            if (counter > 0 && counter % 5 == 0)
            {
            encoded[index] = ' ';
            index++;
            counter = 0;
            }
            
            if (isalpha(input[i]))
            {
                encoded[index] = reverse_arr[tolower(input[i]) - 'a'];
                index++;
                counter++;
            }
            if (isdigit(input[i]))
            {
                encoded[index] = input[i];
                index++;
                counter++;
            }
        }
        
    }
    encoded[index] = '\0';
    return encoded;
}
char *atbash_decode(const char *input)
{
    char *alpha_array = "zyxwvutsrqponmlkjihgfedcba";
    int len = strlen(input);
    char *decoded = malloc(len);
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalnum(input[i]))
        {
            if (isalpha(input[i]))
            {
                decoded[index] = alpha_array[input[i] - 'a'];
                index++;
            }
            else
            {
                decoded[index] = input[i];
                index++;
            }
        }
    }
    decoded[index] = '\0';
    return decoded;
}